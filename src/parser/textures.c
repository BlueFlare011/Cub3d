/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:59:01 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/19 00:14:19 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	get_colour(unsigned char t, unsigned char r, unsigned char g,
	unsigned char b)
{
	return ((t << 24) + (r << 16) + (g << 8) + b);
}

int	check_and_get_colour(int t, int r, int g, int b)
{
	if (t > 255 || r > 255 || g > 255 || b > 255)
		return (-1);
	return (get_colour(t, r, g, b));
}

void	read_texture(t_cube cube, char *file_name, t_texture *texture)
{
	t_img	img;
	char	*addr;
	int		i;

	img.img = mlx_xpm_file_to_image(cube.mlx->mlx, file_name,
		&texture->width, &texture->height);
	addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	texture->img = malloc(sizeof(int *) * texture->height);
	i = 0;
	while (i < texture->height)
	{
		texture->img[i] = malloc(sizeof(int) * texture->width);
		i++;
	}
	i = 0;
	while (i < (texture->height * texture->width * 4))
	{
		if (!img.endian)
			texture->img[(i / 4) / texture->height][(i / 4) % texture->height] =
				get_colour(addr[i + 3], addr[i + 2], addr[i + 1], addr[i]);
		else
			texture->img[(i / 4) / texture->height][(i / 4) % texture->height] =
				get_colour(addr[i], addr[i + 1], addr[i + 2], addr[i + 3]);
		i += 4;
	}
	mlx_destroy_image(cube.mlx->mlx, img.img);
}
