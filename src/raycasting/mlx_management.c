/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:03:07 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/19 21:28:38 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_mlx_init(t_cube *cube)
{
	cube->mlx->mlx = mlx_init();
	cube->mlx->win = mlx_new_window(cube->mlx->mlx, WIN_X, WIN_Y, "cub3d");
	cube->mlx->img->img = mlx_new_image(cube->mlx->mlx, WIN_X, WIN_Y);
	cube->mlx->img->addr = mlx_get_data_addr(cube->mlx->img->img,
		&cube->mlx->img->bpp, &cube->mlx->img->line_len,
		&cube->mlx->img->endian);
}

void	my_pixel_put(t_img img, int x, int y, int colour)
{
	char	*dst;

	if ((0 <= x && x < WIN_X) && (0 <= y && y < WIN_Y))
	{
		dst = img.addr + y * img.line_len + x * (img.bpp / 8);
		*(unsigned int *)dst = colour;
	}
}

int	key_down(int keycode, t_cube *cube)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(cube->mlx->mlx, cube->mlx->win);
		exit(0);
	}
	if (keycode == KEY_A)
		cube->keys.a = 1;
	if (keycode == KEY_W)
		cube->keys.w = 1;
	if (keycode == KEY_S)
		cube->keys.s = 1;
	if (keycode == KEY_D)
		cube->keys.d = 1;
	if (keycode == KEY_LEFT)
		cube->keys.left = 1;
	if (keycode == KEY_RIGHT)
		cube->keys.right = 1;
	return (0);
}

int	key_release(int keycode, t_cube *cube)
{
	if (keycode == KEY_A)
		cube->keys.a = 0;
	if (keycode == KEY_W)
		cube->keys.w = 0;
	if (keycode == KEY_S)
		cube->keys.s = 0;
	if (keycode == KEY_D)
		cube->keys.d = 0;
	if (keycode == KEY_LEFT)
		cube->keys.left = 0;
	if (keycode == KEY_RIGHT)
		cube->keys.right = 0;
	return (0);
}

void	set_x_y(double *x, double *y, double x_value, double y_value)
{
	*x += x_value;
	*y += y_value;
}

int	event_management(t_cube *cube)
{
	double	speed;

	speed = SPEED;
	if ((cube->keys.a || cube->keys.d) && (cube->keys.w || cube->keys.s))
		speed = sqrt(2 * (pow(SPEED, 2)));
	if (cube->keys.a)
		move(*cube, cube->map->dir_y * speed, -cube->map->dir_x * speed);
	if (cube->keys.w)
		move(*cube, cube->map->dir_x * speed, cube->map->dir_y * speed);
	if (cube->keys.s)
		move(*cube, -cube->map->dir_x * speed, -cube->map->dir_y * speed);
	if (cube->keys.d)
		move(*cube, -cube->map->dir_y * speed, cube->map->dir_x * speed);
	if (cube->keys.left)
		rotation(*cube, -ALPHA);
	if (cube->keys.right)
		rotation(*cube, ALPHA);
	raycasting(cube);
	return (0);
}

int	chose_texture(t_raycast raycast)
{
	if (raycast.collided_side == X && raycast.ray_dir_y < 0)
		return (NORTH);
	if (raycast.collided_side == Y && raycast.ray_dir_x > 0)
		return (EAST);
	if (raycast.collided_side == X && raycast.ray_dir_y > 0)
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
	if ((raycast.collided_side == X && raycast.ray_dir_x > 0)
		|| (raycast.collided_side == Y && raycast.ray_dir_y < 0))
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
	// printf("ID = %d\n", id);
	step = 1.0 * cube.texture[id].height / (int)(WIN_Y / raycast.dist);
	texture_pos = (start - WIN_Y / 2 + (int)(WIN_Y / raycast.dist) / 2) * step;
	// printf("TEXTURE POS = %f, HEIGHT = %d\n", texture_pos, cube.texture[id].height);
	if ((int)(texture_pos) >= cube.texture[id].height)
		texture_pos = cube.texture[id].height - 1;
	// printf("TEXTURE POS = %f\n", texture_pos);
	while (j < WIN_Y)
	{
		if (j < end) // pintar cielo
			my_pixel_put(*(cube.mlx->img), x, j, cube.colour[SKY]);
		else if (j <= start || start < 0 || end < 0) // pintar pared
		{
			// fprintf(stderr, "TEXTURE X = %d, TEXTURE Y = %d, j = %d\n", texture_x, (int)texture_pos, j);
			// my_pixel_put(*(cube.mlx->img), x, j, COLOR);
			my_pixel_put(*(cube.mlx->img), x, j, cube.texture[id].img[(int)texture_pos][texture_x]);
			if ((int)(texture_pos + step) < cube.texture[id].height)
				texture_pos += step;
		}
		else // pintar cielo
			my_pixel_put(*(cube.mlx->img), x, j, cube.colour[FLOOR]);
		j++;
	}
}
