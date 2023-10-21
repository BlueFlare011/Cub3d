/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:34:28 by socana-b          #+#    #+#             */
/*   Updated: 2023/10/21 18:14:30 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	error_exit(char *message, int exit_code, t_cube *cube)
{
	int	error;

	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	error = exit_code;
	if (error == SYS_ERR)
		error = errno;
	free_cube(cube);
	exit(error);
}

void	free_cube(t_cube *cube)
{
	int	i;
	int	j;

	if (cube->map.map)
		free_double_pointer(&cube->map.map);
	i = 0;
	while (i < 4)
	{
		if (cube->texture[i].img)
		{
			j = 0;
			while (j < cube->texture[i].height)
			{
				free(cube->texture[i].img[j]);
				j++;
			}
			free(cube->texture[i].img);
		}
		i++;
	}
	if (cube->mlx.mlx)
		mlx_destroy_window(cube->mlx.mlx, cube->mlx.win);
}
