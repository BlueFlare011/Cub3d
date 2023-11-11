/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:35:50 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/11 14:36:43 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap_bonus.h"

static int	is_player(t_cube *cube, int x, int y)
{
	if (y < (cube->map.player_y * CELL_SIZE - PLAYER_SIZE)
		|| y > (cube->map.player_y * CELL_SIZE + PLAYER_SIZE)
		|| x < (cube->map.player_x * CELL_SIZE - PLAYER_SIZE)
		|| x > (cube->map.player_x * CELL_SIZE + PLAYER_SIZE))
		return (0);
	return (1);
}

static void	print_cell(t_cube *cube, int i, int j, char cell_type)
{
	int	k;
	int	l;
	int	x;
	int	y;

	k = 0;
	x = j - ((int)cube->map.player_x - MINIMAP_SIZE) * CELL_SIZE;
	y = i - ((int)cube->map.player_y - MINIMAP_SIZE) * CELL_SIZE;
	while (k < CELL_SIZE)
	{
		l = 0;
		while (l < CELL_SIZE)
		{
			if (is_player(cube, j + l, i + k))
				my_pixel_put(cube->mlx.img, x + l, y + k, PLAYER_COLOUR);
			else if (!k || !l || !(k - CELL_SIZE - 1) || !(l - CELL_SIZE - 1))
				my_pixel_put(cube->mlx.img, x + l, y + k, BORDER_COLOUR);
			else if (cell_type == '1')
				my_pixel_put(cube->mlx.img, x + l, y + k, WALL_COLOUR);
			else
				my_pixel_put(cube->mlx.img, x + l, y + k, FLOOR_COLOUR);
			l++;
		}
		k++;
	}
}

void	print_minimap(t_cube *cube)
{
	int	i;
	int	j;

	i = (int)cube->map.player_y - MINIMAP_SIZE;
	while ((i - (int)cube->map.player_y) <= MINIMAP_SIZE)
	{
		j = (int)cube->map.player_x - MINIMAP_SIZE;
		while ((j - (int)cube->map.player_x) <= MINIMAP_SIZE)
		{
			if (i >= 0 && j >= 0 && i < len_double_pointer(cube->map.map)
				&& j < (int)ft_strlen(cube->map.map[i]))
				print_cell(cube, i * CELL_SIZE, j * CELL_SIZE,
					cube->map.map[i][j]);
			j++;
		}
		i++;
	}
}
