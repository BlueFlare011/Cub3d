/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:13:25 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/13 20:08:34 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cube.h"

void	move_player(t_cube cube, int axis, int mvment_ratio)
{
	double	x;
	double	y;

	x = cube.map->player_x;
	y = cube.map->player_y;
	if (axis == X)
		x += (double)mvment_ratio / (double)CUBE_SIZE;
	else
		y += (double)mvment_ratio / (double)CUBE_SIZE;
	if (axis == X && cube.map->map[(int)y][(int)x] != '1')
		cube.map->player_x = x;
	else if (axis == Y && cube.map->map[(int)y][(int)x] != '1')
		cube.map->player_y = y;
}
