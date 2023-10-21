/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:34:18 by socana-b          #+#    #+#             */
/*   Updated: 2023/10/21 14:58:05 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
	// cube->map = malloc(sizeof(t_map));
	// if (!cube->map)
	// 	error_exit(strerror(errno), SYS_ERR);
	// cube->mlx = malloc(sizeof(t_mlx));
	// if (!cube->mlx)
	// 	error_exit(strerror(errno), SYS_ERR);
	// cube->mlx->img = malloc(sizeof(t_img));
	// if (!cube->mlx->img)
	// 	error_exit(strerror(errno), SYS_ERR);
	// cube->map->map = NULL;
	(void)set_keys(cube);
}

// void	delete_struct(t_cube *cube)
// {
// 	// int	i;

// 	// i = 0;
// 	if (cube->map)
// 	{
// 		free_double_pointer(cube->map->map);
// 		free(cube->map);
// 	}
// 	// while (i < 4)
// 	// {
// 	// 	free_double_pointer(cube->texture[i].img);
// 	// 	i++;
// 	// }
// 	if (cube)
// 		free(cube);
// }

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

int	set_keys(t_cube *cube)
{
	cube->keys.a = 0;
	cube->keys.w = 0;
	cube->keys.s = 0;
	cube->keys.d = 0;
	cube->keys.left = 0;
	cube->keys.right = 0;
	return (0);
}
