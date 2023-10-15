/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:13:25 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/15 19:31:35 by rgallego         ###   ########.fr       */
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
