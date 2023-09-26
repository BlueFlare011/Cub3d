/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mngment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:03:07 by rgallego          #+#    #+#             */
/*   Updated: 2023/09/26 11:07:09 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_mlx_init(t_cube *cube)
{
	cube->mlx->mlx = mlx_init();
	cube->mlx->win = mlx_new_window(cube->mlx->mlx,
		(cube->map->max_x + 1) * 50, (cube->map->max_y + 1) * 50, "cub3d");
	cube->mlx->img = mlx_new_image(cube->mlx->mlx, (cube->map->max_x + 1) * 50,
		(cube->map->max_y + 1) * 50);
	cube->mlx->img->addr = mlx_get_data_addr(cube->mlx->img->img,
		&cube->mlx->img->bpp, &cube->mlx->img->line_len,
		&cube->mlx->img->endian);
}

void	my_pixel_put(t_img img, int x, int y, int colour)
{
	char	*dst;

	if ((0 <= x && x < 1024) && (0 <= y && y < 720))
	{
		dst = img.addr + y * img.line_len + x * (img.bpp / 8);
		*(unsigned int *)dst = colour;
	}
}
