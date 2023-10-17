/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:59:01 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/17 23:59:17 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	get_colour(unsigned char t, unsigned char r, unsigned char g,
	unsigned char b)
{
	return ((t << 24) + (r << 16) + (g << 8) + b);
}

void test_textures(t_cube cube)
{
	void	*img;
	int		img_width;
	int		img_height;
	int		bpp;
	int		line_len;
	int		endian;
	int		**texture;
	int		i;

	img = mlx_xpm_file_to_image(cube.mlx->mlx, "./files/textures/white_square.xpm", &img_width, &img_height);
	char *addr = mlx_get_data_addr(img, &bpp, &line_len, &endian);
	texture = malloc(sizeof(int) * img_height);

	i = 0;
	while (i < img_height)
	{
		texture[i] = malloc(sizeof(int) * img_width);
		i++;
	}
	i = 0;
	while (i < (img_height * img_width))
	{
		if (!endian)
			texture[i / img_height][i % img_height] =
				get_colour(addr[i + 3], addr[i + 2], addr[i + 1], addr[i]);
		else
			texture[i / img_height][i % img_height] =
				get_colour(addr[i], addr[i + 1], addr[i + 2], addr[i + 3]);
		i += 4;
	}
	mlx_destroy_image(cube.mlx->mlx, img);
}
