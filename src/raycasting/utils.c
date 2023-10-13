/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blueflare011 <blueflare011@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:13:25 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/13 15:45:07 by blueflare01      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cube.h"

void	move_player(t_cube cube, int axis, int mvment_ratio)
{
	int	x;
	int	y;

	x = cube.mlx->player_x;
	y = cube.mlx->player_y;
	if (axis == X)
		x += mvment_ratio;
	else
		y += mvment_ratio;
	if (axis == X && cube.map->map[y / CUBE_SIZE][x / CUBE_SIZE] != '1')
		cube.mlx->player_x = x;
	else if (axis == Y && cube.map->map[y / CUBE_SIZE][x / CUBE_SIZE] != '1')
		cube.mlx->player_y = y;
}
