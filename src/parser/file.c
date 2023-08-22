#include "cube.h"

int	get_texture_aux(t_info *info, char **data, int id)
{
	info->texture[id].id = id;
	info->texture[id].fd_texture = open(data[1], O_RDONLY);
	if (info->texture[id].fd_texture < 0)
		return (1);
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
	int		num;

	rgb = ft_split(data[1], ',');
	if (!rgb)
		return (1);
	if (is_num(rgb))
	{
		free_double_pointer((void **)rgb);
		return (1);
	}
	if (!ft_strncmp(data[0], "C", 2))
	{
		info->color[1].id = CEILING;
		info->color[1].red = ft_atoi(rgb[0]);
		info->color[1].green = ft_atoi(rgb[1]);
		info->color[1].blue = ft_atoi(rgb[2]);
	}
	else if (!ft_strncmp(data[0], "F", 2))
	{
		info->color[0].id = CEILING;
		info->color[0].red = ft_atoi(rgb[0]);
		info->color[0].green = ft_atoi(rgb[1]);
		info->color[0].blue = ft_atoi(rgb[2]);
	}
	else
	{
		free_double_pointer((void **)rgb);
		return (1);
	}
	return (0);
}

void	get_map(t_info *info, char *line, int fd)
{
	(void)line;
	(void)fd;
	(void)info;
	write(1, "Aqui va el Mapa\n", 16);
}

int	analyse_line(t_info *info, char *line)
{
	char	*data;
	int		status;

	status = 0;
	if (*line == '\n')
		return (0);
	data = ft_split(line, ' ');
	if (!data)
		return (1);
	if (len_double_pointer((void **)data) != 2)
	{
		free_double_pointer((void **)data);
		return (1);
	}
	status = get_texture(info, data);
	status = get_color(info, data);
	free_double_pointer((void **)data);
	if (status)
	{
		while (*line && *line != 1)
			line++;
		if (*line == 1)
			status = 2;
	}
	return (status);
}

int	get_attribbutes(t_info *info, int fd)
{
	char	*line;
	int		flag;

	flag = 0;
	line = get_next_line(fd);
	while (line && flag != 2)
	{
		delete_meta_spaces(line);
		flag = analyse_line(info, line);
		if (flag)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	if (flag == 1)
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
		return (NULL);
	if (create_struct(info))
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if (get_attribbutes(info, fd))
	{
		close(fd);
		return (NULL);
	}
	close(fd);
	return (info);
}
