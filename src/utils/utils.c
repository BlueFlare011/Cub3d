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

int	len_double_pointer(void **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
		i++;
	return (i);
}

void	free_double_pointer(void **matrix)
{
	while (*matrix)
	{
		free(*matrix);
		matrix++;
	}
	free(matrix);
}

int	create_struct(t_info *info)
{
	info->color = malloc(sizeof(t_color) * 2);
	if (!info->color)
		return (1);
	info->texture = malloc(sizeof(t_texture) * 4);
	if (!info->color)
		return (1);
	info->map = NULL;
	return (0);
}

void	delete_struct(t_info *info)
{
	if (info->map)
		free_double_pointer((void **)info->map);
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
	j = 0;
	aux = 1;
	while (rgb[i] && aux)
	{
		while (rgb[i][j] && aux)
		{
			aux = ft_isdigit(rgb[i][j]);
			j++;
		}
		i++;
	}
	return (!aux);
}