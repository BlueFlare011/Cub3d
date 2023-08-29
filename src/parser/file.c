#include "cube.h"

int	get_texture_aux(t_info *info, char **data, int id)
{
	char	*aux;

	aux = ft_strtrim(data[1], "\n");
	if (!aux)
		return (error_int(strerror(errno), 1));
	info->texture[id].id = id;
	info->texture[id].fd_texture = open(aux, O_RDONLY);
	if (info->texture[id].fd_texture < 0)
	{
		free(aux);
		return (error_int(strerror(errno), 1));
	}
	free(aux);
	return (0);
}

int	get_texture(t_info *info, char **data)
{
	if (!ft_strncmp(data[0], "NO", 3))
		return(get_texture_aux(info, data, NORTH));
	if (!ft_strncmp(data[0], "SO", 3))
		return(get_texture_aux(info, data, SOUTH));
	if (!ft_strncmp(data[0], "EA", 3))
		return(get_texture_aux(info, data, EAST));
	if (!ft_strncmp(data[0], "WE", 3))
		return(get_texture_aux(info, data, WEST));
	return (1);
}

int	get_color(t_info *info, char **data)
{
	char	**rgb;

	rgb = ft_split(data[1], ',');
	if (!rgb)
		return (error_int(strerror(errno), 1));
	if (is_num(rgb))
	{
		free_double_pointer(rgb);
		return (error_int(NO_NUMBER, 1));
	}
	//Mejorar esta puta mierda
	if (!ft_strncmp(data[0], "C", 2))
	{
		info->color[1].id = CEILING;
		info->color[1].red = ft_atoi(rgb[0]);
		info->color[1].green = ft_atoi(rgb[1]);
		info->color[1].blue = ft_atoi(rgb[2]);
	}
	else if (!ft_strncmp(data[0], "F", 2))
	{
		info->color[0].id = FLOOR;
		info->color[0].red = ft_atoi(rgb[0]);
		info->color[0].green = ft_atoi(rgb[1]);
		info->color[0].blue = ft_atoi(rgb[2]);
	}
	else
	{
		free_double_pointer(rgb);
		return (1);
	}
	free_double_pointer(rgb);
	return (0);
}

void	get_map(t_info *info, char *line, int fd)
{
	char	*super_string;
	char	*aux;

	super_string = line;
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			aux = ft_strjoin(super_string, line);
			free(line);
			free(super_string);
			super_string = aux;
		}
	}
	info->map = ft_split(super_string, '\n');
	free(super_string);
}

int	analyse_line(t_info *info, char *line, int status)
{
	char	**data;

	if (*line == '\0')
		return (status);
	data = ft_split(line, ' ');
	if (!data)
		return (error_int(strerror(errno), -1));
	if (len_double_pointer(data) != 2)
	{
		free_double_pointer(data);
		return (error_int(INVALID_LINE_NUM, -1));
	}
	if (get_texture(info, data) == 0 || get_color(info, data) == 0)
		status++;
	else
	{
		(void)error(INVALID_LINE);
		status = -1;
	}
	free_double_pointer(data);
	return (status);
}

int	get_attribbutes(t_info *info, int fd)
{
	char	*line;
	int		limit;

	limit = 0;
	line = get_next_line(fd);
	while (line && limit < 6 && limit != -1)
	{
		delete_meta_spaces(line);
		line = trim_line(line);
		if (!line)
			break;
		limit = analyse_line(info, line, limit);
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		return (error_int(strerror(errno), 1));
	if (limit == -1)
		return (1);
	get_map(info, line, fd);
	return (0);
}

t_info	*extract_file_info(char *file)
{
	t_info	*info;
	int		fd;

	info = malloc(sizeof(t_info));
	if (!info)
		return(error(strerror(errno)));
	if (create_struct(info))
	{
		free(info);
		return (NULL);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return(error(strerror(errno)));
	if (get_attribbutes(info, fd))
	{
		close(fd);
		return (NULL);
	}
	close(fd);
	return (info);
}
