/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:59:01 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/23 22:00:17 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	get_colour(unsigned char t, unsigned char r, unsigned char g,
	unsigned char b)
{
	return ((t << 24) + (r << 16) + (g << 8) + b);
}

int	check_and_get_colour(char **rgb)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[RED]);
	g = ft_atoi(rgb[GREEN]);
	b = ft_atoi(rgb[BLUE]);
	if (is_rgb(rgb[RED]) || is_rgb(rgb[GREEN]) || is_rgb(rgb[BLUE]))
		return (-1);
	if (r > 255 || g > 255 || b > 255)
		return (-1);
	return (get_colour(0, r, g, b));
}

static int	create_texture_img(t_texture *texture)
{
	int	i;

	texture->img = malloc(sizeof(int *) * texture->height);
	if (!texture->img)
		return (1);
	i = 0;
	while (i < texture->height && (!i || texture->img[i - 1]))
	{
		texture->img[i] = malloc(sizeof(int) * texture->width);
		i++;
	}
	if (!texture->img[i - 1])
	{
		while (i >= 0)
		{
			free(texture->img[i]);
			i--;
		}
		free(texture->img);
		return (1);
	}
	return (0);
}

static int	read_texture(t_cube cube, char *file_name, t_texture *texture)
{
	t_img	img;
	char	*addr;
	int		i;

	addr = mlx_get_texture(cube, &img, texture, file_name);
	if (!addr)
		return (1);
	if (create_texture_img(texture))
	{
		mlx_destroy_image(cube.mlx.mlx, img.img);
		return (1);
	}
	i = 0;
	while (i < (texture->height * texture->width * 4))
	{
		if (!img.endian)
			texture->img[(i / 4) / texture->width][(i / 4) % texture->width] \
				= get_colour(addr[i + 3], addr[i + 2], addr[i + 1], addr[i]);
		else
			texture->img[(i / 4) / texture->width][(i / 4) % texture->width] \
				= get_colour(addr[i], addr[i + 1], addr[i + 2], addr[i + 3]);
		i += 4;
	}
	mlx_destroy_image(cube.mlx.mlx, img.img);
	return (0);
}

void	get_texture(t_cube *cube, char *trimmed_line, int id, int fd)
{
	id -= OFFSET;
	if (read_texture(*cube, trimmed_line, &(cube->texture[id])))
	{
		close(fd);
		free(trimmed_line);
		error_exit(IMAGE_ERROR, GENERAL_ERR, cube);
	}
}
