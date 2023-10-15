/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:13:25 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/15 18:36:29 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cube.h"

void	move_player(t_cube cube, int axis, double mvment_ratio)
{
	double	x;
	double	y;

	x = cube.map->player_x;
	y = cube.map->player_y;
	if (axis == X)
		x += mvment_ratio;
	else
		y += mvment_ratio;
	if (axis == X && cube.map->map[(int)y][(int)x] != '1')
		cube.map->player_x = x;
	else if (axis == Y && cube.map->map[(int)y][(int)x] != '1')
		cube.map->player_y = y;
}
