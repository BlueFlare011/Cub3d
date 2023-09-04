#include "cube.h"

void	delete_meta_spaces(char *str)
{
	while (*str)
	{
		if (*str == '\t' || *str == '\f' || *str == '\v' || *str == '\r')
			*str = ' ';
		str++;
	}
}

int	len_double_pointer(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
		i++;
	return (i);
}

void	free_double_pointer(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	if (matrix)
		free(matrix);
}

int	create_struct(t_info *info)
{
	int	i;

	i = 0;
	info->color = malloc(sizeof(t_color) * 2);
	if (!info->color)
		return(error_int(strerror(errno), 1));
	info->texture = malloc(sizeof(t_texture) * 4);
	if (!info->texture)
	{
		free(info->color);
		return(error_int(strerror(errno), 1));
	}
	while (i < 4)
		info->texture[i++].fd_texture = -2;
	info->map = NULL;
	return (0);
}

void	delete_struct(t_info *info)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (info->texture[i].fd_texture > 0)
			close(info->texture[i++].fd_texture);
	}
	if (info->map)
		free_double_pointer(info->map);
	if (info->texture)
		free(info->texture);
	if (info->color)
		free(info->color);
	if (info)
		free(info);
}

int	is_num(char **rgb)
{
	int	i;
	int	j;
	int	aux;

	i = 0;
	aux = 1;
	while (rgb[i] && aux)
	{
		j = 0;
		while (rgb[i][j] && aux)
		{
			aux = ft_isdigit(rgb[i][j]);
			j++;
		}
		i++;
	}
	return (!aux);
}

char	*trim_line(char *line)
{
	char	*result;

	result = ft_strtrim(line, "\n");
	if (!result)
	{
		free(line);
		return (NULL);
	}
	free(line);
	return (result);
}

void	print_info(t_info *info)
{
	int	it;

	it = 0;
	for (int i = 0; i < 4; i++)
		printf("%d - %d\n", info->texture[i].id, info->texture[i].fd_texture);
	for (int i = 0; i < 2; i++)
		printf("%d - (%d,%d,%d)\n", info->color[i].id, info->color[i].red, info->color[i].green, info->color[i].blue);
	while (info->map && info->map[it])
	{
		printf("%s\n", info->map[it]);
		it++;
	}
}
