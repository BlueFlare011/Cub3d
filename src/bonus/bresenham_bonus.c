/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:12:51 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/11 15:52:18 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap_bonus.h"

static void	bresen_x(t_img img, t_point start, t_point end, t_bresen bham)
{
	bham.variation = bham.d.y - (bham.d.x / 2);
	while (start.x != end.x)
	{
		start.x += bham.step.x;
		if (bham.variation >= 0)
		{
			start.y += bham.step.y;
			bham.variation -= bham.d.x;
		}
		bham.variation += bham.d.y;
		my_pixel_put(img, start.x, start.y, PERSP_COLOUR);
	}
}

static void	bresen_y(t_img img, t_point start, t_point end, t_bresen bham)
{
	bham.variation = bham.d.x - (bham.d.y / 2);
	while (start.y != end.y)
	{
		start.y += bham.step.y;
		if (bham.variation >= 0)
		{
			start.x += bham.step.x;
			bham.variation -= bham.d.y;
		}
		bham.variation += bham.d.x;
		my_pixel_put(img, start.x, start.y, PERSP_COLOUR);
	}
}

static void	bresenham(t_img img, t_point start, t_point end)
{
	t_bresen	bham;

	bham.d.x = 2 * (ft_max(start.x, end.x) - ft_min(start.x, end.x));
	bham.d.y = 2 * (ft_max(start.y, end.y) - ft_min(start.y, end.y));
	bham.step = (t_point){1, 1};
	if ((end.x - start.x) < 0)
		bham.step.x = -1;
	if ((end.y - start.y) < 0)
		bham.step.y = -1;
	my_pixel_put(img, start.x, start.y, PERSP_COLOUR);
	if (bham.d.x > bham.d.y)
		bresen_x(img, start, end, bham);
	else
		bresen_y(img, start, end, bham);
}

void	prepare_bresenham(t_cube *cube, double x, double y)
{
	t_point	start;
	t_point	end;

	start.x = (x + MINIMAP_SIZE) * CELL_SIZE;
	start.y = (y + MINIMAP_SIZE) * CELL_SIZE;
	end.x = (x + cube->map.dir_x * PERSP_SIZE + MINIMAP_SIZE) * CELL_SIZE;
	end.y = (y + cube->map.dir_y * PERSP_SIZE + MINIMAP_SIZE) * CELL_SIZE;
	bresenham(cube->mlx.img, start, end);
}
