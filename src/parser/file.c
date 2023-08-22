#include "cube.h"

void	get_texture(t_info *info, char **data)
{
	char		**aux;

	aux = ft_split(line, ' ');
	if (ft_strncmp(aux[0], "NO", 3) == 0)
	{
		info->texture[NORTH].id = NORTH;
		info->texture[NORTH].path = ft_strdup(aux[1]);
	}
	else if (ft_strncmp(aux[0], "SO", 3) == 0)
	{
		info->texture[SOUTH].id = SOUTH;
		info->texture[SOUTH].path = ft_strdup(aux[1]);
	}
	else if (ft_strncmp(aux[0], "EA", 3) == 0)
	{
		info->texture[EAST].id = EAST;
		info->texture[EAST].path = ft_strdup(aux[1]);
	}
	else if (ft_strncmp(aux[0], "WE", 3) == 0)
	{
		info->texture[WEST].id = WEST;
		info->texture[WEST].path = ft_strdup(aux[1]);
	}
	free_double_pointer((void **)aux);
}

void	get_color(t_info *info, char **data)
{
	char		**aux;
	char		**num;

	aux = ft_split(line, ' ');
	num = ft_split(aux[1], ',');
	if (ft_strncmp(aux[0], "F", 2) == 0)
	{
		info->color[0].id = FLOOR;
		info->color[0].red = ft_atoi(num[0]);
		info->color[0].green = ft_atoi(num[1]);
		info->color[0].blue = ft_atoi(num[2]);
	}
	else if (ft_strncmp(aux[0], "C", 2) == 0)
	{
		info->color[0].id = FLOOR;
		info->color[0].red = ft_atoi(num[0]);
		info->color[0].green = ft_atoi(num[1]);
		info->color[0].blue = ft_atoi(num[2]);
	}
	free_double_pointer((void **)num);
	free_double_pointer((void **)aux);
}

void	get_map(t_info *info, char *line, int fd)
{
	(void)line;
	(void)fd;
	info->map = malloc(sizeof(char *));
	free(info->map);
	info->map = NULL;
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
		free_double_pointer(data);
		return (1);
	}
	//Continue

	return (0);
}

int	get_attribbutes(t_info *info, int fd)
{
	char	*line;
	int		flag;

	flag = 0;
	line = get_next_line(fd);
	while (line)
	{
		delete_meta_spaces(line);
		if (analyse_line(info, line))
		{
			flag = 1;
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	if (flag)
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
