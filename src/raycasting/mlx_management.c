/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blueflare011 <blueflare011@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:03:07 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/16 21:23:04 by blueflare01      ###   ########.fr       */
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

int	key_control(int keycode, t_cube *cube)
{
	if (keycode == KEY_ESC)
		exit(1);
	if (keycode == KEY_W)
		move(*cube, cube->map->dir_x * SPEED, cube->map->dir_y * SPEED);
	else if (keycode == KEY_S)
		move(*cube, -cube->map->dir_x * SPEED, -cube->map->dir_y * SPEED);
	else if (keycode == KEY_A)
		move(*cube, cube->map->dir_y * SPEED, -cube->map->dir_x * SPEED);
	else if (keycode == KEY_D)
		move(*cube, -cube->map->dir_y * SPEED, cube->map->dir_x * SPEED);
	else if (keycode == KEY_LEFT)
		rotation(*cube, -ALPHA);
	else if (keycode == KEY_RIGHT)
		rotation(*cube, ALPHA);
	raycasting(cube);
	return (0);
}

void	paint_ray(t_cube cube, t_raycast raycast, int x, int start, int end) // El raycast esta ahi solo para diferenciar las paredes, luego se quita :)
{
	int j;

	j = 0;
//	printf("start = %d, end = %d\n", start, end);
	while (j < WIN_Y)
	{
		if (j < end) // pintar cielo
			my_pixel_put(*(cube.mlx->img), x, j, cube.color[SKY].true_color);
		else if (j < start || start < 0 || end < 0){ // pintar pared
			if (raycast.collided_side == X)
				my_pixel_put(*(cube.mlx->img), x, j, GREEN/2);
			else
				my_pixel_put(*(cube.mlx->img), x, j, GREEN);
		}
		else // pintar cielo
			my_pixel_put(*(cube.mlx->img), x, j, cube.color[FLOOR].true_color);
		j++;
	}

}
