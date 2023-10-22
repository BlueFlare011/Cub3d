/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:03:07 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/22 15:16:09 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_management.h"

void	ft_mlx_init(t_cube *cube)
{
	cube->mlx.mlx = mlx_init();
	cube->mlx.win = mlx_new_window(cube->mlx.mlx, WIN_X, WIN_Y, "cub3d");
	cube->mlx.img.img = mlx_new_image(cube->mlx.mlx, WIN_X, WIN_Y);
	if (!cube->mlx.img.img)
	{
		mlx_destroy_window(cube->mlx.mlx, cube->mlx.win);
		error_exit(IMAGE_ERROR, GENERAL_ERR, cube);
	}
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

char	*mlx_get_texture(t_cube cube, t_img *img, t_texture *texture,
	char *file_name)
{
	img->img = mlx_xpm_file_to_image(cube.mlx.mlx, file_name,
			&texture->width, &texture->height);
	if (!img->img)
		return (NULL);
	return (mlx_get_data_addr(img->img, &img->bpp, &img->line_len,
		&img->endian));
}
