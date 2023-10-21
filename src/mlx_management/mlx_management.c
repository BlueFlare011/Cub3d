/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:03:07 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/21 14:44:22 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_management.h"

void	ft_mlx_init(t_cube *cube)
{
	cube->mlx.mlx = mlx_init();
	cube->mlx.win = mlx_new_window(cube->mlx.mlx, WIN_X, WIN_Y, "cub3d");
	cube->mlx.img.img = mlx_new_image(cube->mlx.mlx, WIN_X, WIN_Y);
	cube->mlx.img.addr = mlx_get_data_addr(cube->mlx.img.img,
			&cube->mlx.img.bpp, &cube->mlx.img.line_len,
			&cube->mlx.img.endian);
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
