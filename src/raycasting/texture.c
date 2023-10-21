/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:03:07 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/21 13:15:57 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	chose_texture(t_raycast raycast)
{
	if (raycast.collided_side == Y && raycast.ray_dir_y < 0)
		return (NORTH);
	if (raycast.collided_side == X && raycast.ray_dir_x > 0)
		return (EAST);
	if (raycast.collided_side == Y && raycast.ray_dir_y > 0)
		return (SOUTH);
	return (WEST);
}

int get_texture_x(t_cube cube, t_raycast raycast, int id)
{
	int		texture_x;
	double	collision_pos;
	
	if (raycast.collided_side == X)
		collision_pos = cube.map->player_y + raycast.dist * raycast.ray_dir_y;
	else
		collision_pos = cube.map->player_x + raycast.dist * raycast.ray_dir_x;
	collision_pos -= floor(collision_pos);
	texture_x = (int)(collision_pos * (double)cube.texture[id].width);
	if ((raycast.collided_side == X && raycast.ray_dir_x < 0)
		|| (raycast.collided_side == Y && raycast.ray_dir_y > 0))
		return (cube.texture[id].width - texture_x - 1);
	return (texture_x);
}

void	paint_ray(t_cube cube, t_raycast raycast, int x, int start, int end) // El raycast esta ahi solo para diferenciar las paredes, luego se quita :)
{
	int		j;
	int		id;
	int		texture_x;
	double	step;
	double	texture_pos;

	j = 0;
	id = chose_texture(raycast);
	texture_x = get_texture_x(cube, raycast, id);
	step = 1.0 * cube.texture[id].height / raycast.height;
	texture_pos = (end - WIN_Y / 2 + raycast.height / 2) * step;
	// printf("start = %d, lineheight = %d, texture_pos = %f, step = %f, H/2 = %d, lineheight/2 = %d\n", end, lineheight, texture_pos, step, WIN_Y / 2, ((int)(WIN_Y / raycast.dist)) / 2);
	// printf("PARENTHESIS = %d\n", (end - WIN_Y / 2 + lineheight / 2));
	// printf("TEXTURE POS = %f, HEIGHT = %d, res = %d, perpWallDist = %f\n", texture_pos, cube.texture[id].height, (start - WIN_Y / 2 + ((int)(WIN_Y / raycast.dist)) / 2), raycast.dist);
	if ((int)(texture_pos) >= cube.texture[id].height)
		texture_pos = cube.texture[id].height - 1;
	// printf("TEXTURE POS = %f\n", texture_pos);
	while (j < WIN_Y)
	{
		if (j < end) // pintar cielo
			my_pixel_put(*(cube.mlx->img), x, j, cube.colour[FLOOR]);
		else if (j <= start) // pintar pared
		{
			// fprintf(stderr, "TEXTURE X = %d, TEXTURE Y = %d, j = %d\n", texture_x, (int)texture_pos, j);
			// my_pixel_put(*(cube.mlx->img), x, j, COLOR);
			my_pixel_put(*(cube.mlx->img), x, j, cube.texture[id].img[(int)texture_pos][texture_x]);
			if ((int)(texture_pos + step) < cube.texture[id].height)
				texture_pos += step;
		}
		else // pintar cielo
			my_pixel_put(*(cube.mlx->img), x, j, cube.colour[SKY]);
		j++;
	}
}
