/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:03:07 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/15 19:40:57 by rgallego         ###   ########.fr       */
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
	if (keycode == KEY_S)
		move(*cube, -cube->map->dir_x * SPEED, -cube->map->dir_y * SPEED);
	if (keycode == KEY_A)
		move(*cube, -cube->map->dir_y * SPEED, -cube->map->dir_x * SPEED);
	if (keycode == KEY_D)
		move(*cube, cube->map->dir_y * SPEED, cube->map->dir_x * SPEED);
	raycasting(cube);
	return (0);
}

void	paint_ray(t_cube cube, int x, int start, int end)
{
	int j;

	j = 0;
//	printf("start = %d, end = %d\n", start, end);
	while (j < WIN_Y)
	{
		if (j < end) // pintar cielo
			my_pixel_put(*(cube.mlx->img), x, j, WHITE);
		else if (j < start || start < 0 || end < 0) // pintar pared
			my_pixel_put(*(cube.mlx->img), x, j, GREEN);
		else // pintar cielo
			my_pixel_put(*(cube.mlx->img), x, j, BLACK);
		j++;
	}

}
