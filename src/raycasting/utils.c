/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:13:25 by rgallego          #+#    #+#             */
/*   Updated: 2023/09/26 21:26:29 by rgallego         ###   ########.fr       */
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
