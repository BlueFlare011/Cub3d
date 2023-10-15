/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:13:25 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/15 19:56:41 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cube.h"

void	move(t_cube cube, double move_x, double move_y)
{
	double	x;
	double	y;

	x = cube.map->player_x + move_x;
	y = cube.map->player_y + move_y;
	if (cube.map->map[(int)y][(int)x] == '1')
		return ;
	cube.map->player_x = x;
	cube.map->player_y = y;
}

void	rotation(t_cube cube, int direction)
{
	cube.map->dir_x = direction * (cube.map->dir_x * cos(ALPHA) - cube.map->dir_x * sin(ALPHA));
	cube.map->dir_y = direction * (cube.map->dir_y * sin(ALPHA) + cube.map->dir_y * cos(ALPHA));
}
