/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:34:18 by socana-b          #+#    #+#             */
/*   Updated: 2023/10/16 02:11:35 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

void	create_struct(t_cube *cube)
{
	int	i;

	cube->color = malloc(sizeof(t_color) * 2);
	if (!cube->color)
		error_exit(strerror(errno), SYS_ERR);
	cube->texture = malloc(sizeof(t_texture) * 4);
	if (!cube->texture)
		error_exit(strerror(errno), SYS_ERR);
	cube->map = malloc(sizeof(t_map));
	if (!cube->map)
		error_exit(strerror(errno), SYS_ERR);
	cube->mlx = malloc(sizeof(t_mlx));
	if (!cube->mlx)
		error_exit(strerror(errno), SYS_ERR);
	cube->mlx->img = malloc(sizeof(t_img));
	if (!cube->mlx->img)
		error_exit(strerror(errno), SYS_ERR);
	i = 0;
	while (i < 4)
	{
		cube->texture[i].fd_texture = -1;
		i++;
	}
	cube->map->map = NULL;
}

void	delete_struct(t_cube *cube)
{
	int	i;

	i = 0;
	if (cube->map)
	{
		free_double_pointer(cube->map->map);
		free(cube->map);
	}
	if (cube->texture)
	{
		while (i < 4)
		{
			if (cube->texture[i].fd_texture > 0)
				close(cube->texture[i].fd_texture);
			i++;
		}
		free(cube->texture);
	}
	if (cube->color)
		free(cube->color);
	if (cube)
		free(cube);
}

int	is_num(char **rgb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (rgb[i] && (!rgb[i][j] || ft_isdigit(rgb[i][j])))
	{
		while (rgb[i][j] && ft_isdigit(rgb[i][j]))
			if (ft_isdigit(rgb[i][j]))
				j++;
		if (!rgb[i][j])
			i++;
		j = 0;
	}
	return (!rgb[i]);
}

char	*process_line(int fd)
{
	char			*line;
	char			*result;
	unsigned int	i;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	i = 0;
	while (line[i])
	{
		if (ft_strchr("\t\f\v\r", line[i]))
			line[i] = ' ';
		i++;
	}
	result = ft_strtrim(line, "\n");
	if (!result)
		error_exit(strerror(errno), SYS_ERR);
	free(line);
	return (result);
}

void	print_cube(t_cube *cube)
{
	int	it;

	it = 0;
	for (int i = 0; i < 4; i++)
		printf("%d - %d\n", cube->texture[i].id, cube->texture[i].fd_texture);
	for (int i = 0; i < 2; i++)
		printf("%d - (%d,%d,%d)\n", cube->color[i].id, cube->color[i].red, cube->color[i].green, cube->color[i].blue);
	while (cube->map->map && cube->map->map[it])
	{
		printf("%s\n", cube->map->map[it]);
		it++;
	}
}
