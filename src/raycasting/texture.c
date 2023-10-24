/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:03:07 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/24 23:48:33 by rgallego         ###   ########.fr       */
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

static int	get_texture_x(t_cube cube, int id)
{
	int		texture_x;
	double	collision_pos;

	if (cube.raycast.collided_side == X)
		collision_pos = cube.map.player_y
			+ (cube.raycast.dist * cube.raycast.ray_dir_y);
	else
		collision_pos = cube.map.player_x
			+ (cube.raycast.dist * cube.raycast.ray_dir_x);
	collision_pos -= floor(collision_pos);
	texture_x = (int)(collision_pos * (double)cube.texture[id].width);
	if ((cube.raycast.collided_side == X && cube.raycast.ray_dir_x < 0)
		|| (cube.raycast.collided_side == Y && cube.raycast.ray_dir_y > 0))
		return (cube.texture[id].width - texture_x - 1);
	return (texture_x);
}

void	paint_ray(t_cube cube, int x)
{
	int		j;
	int		id;
	int		texture_x;
	double	step;
	double	texture_pos;

	j = 0;
	id = chose_texture(cube.raycast);
	texture_x = get_texture_x(cube, id);
	step = 1.0 * cube.texture[id].height / cube.raycast.height;
	texture_pos = (cube.raycast.start - WIN_Y / 2 + cube.raycast.height / 2)
		* step;
	while (j < cube.raycast.start)
		my_pixel_put(cube.mlx.img, x, j++, cube.colour[SKY]);
	while (j <= cube.raycast.end)
	{
		my_pixel_put(cube.mlx.img, x, j++,
			cube.texture[id].img[(int)texture_pos][texture_x]);
		if ((int)(texture_pos + step) < cube.texture[id].height)
			texture_pos += step;
	}
	while (j < WIN_Y)
		my_pixel_put(cube.mlx.img, x, j++, cube.colour[FLOOR]);
}
