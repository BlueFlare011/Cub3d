/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 02:10:52 by rgallego          #+#    #+#             */
/*   Updated: 2023/12/01 19:47:28 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "minimap_bonus.h"
/**
 * Function which sets delta for the 2 axis, after a few demonstrations
 * the formula is delta_i = 1 / ray_dir_i. REMINDER: keep in mind the case when
 * ray_dir_i = 0, delta_i = INF.
*/
static void	set_delta(t_raycast *raycast)
{
	if (raycast->ray_dir_x == 0.0)
		raycast->delta_x = __DBL_MAX__;
	else
		raycast->delta_x = fabs(1.0 / raycast->ray_dir_x);
	if (raycast->ray_dir_y == 0.0)
		raycast->delta_y = __DBL_MAX__;
	else
		raycast->delta_y = fabs(1.0 / raycast->ray_dir_y);
}

/**
 * Function which calculates the step. It is 1 cell step if the component is
 * positive or negative if it is negative. To calculate the side distance is
 * needed to calculate the lower distance from the point to one of the sides
 * multiplied by the delta of the component.
*/
static void	set_step_and_side(t_raycast *raycast, double x, double y)
{
	raycast->step_x = 1;
	raycast->step_y = 1;
	if (raycast->ray_dir_x < 0)
		raycast->step_x = -1;
	if (raycast->ray_dir_y < 0)
		raycast->step_y = -1;
	if (raycast->ray_dir_x < 0)
		raycast->side_dist_x = (x - (int)x) * raycast->delta_x;
	else
		raycast->side_dist_x = ((int)x + 1.0 - x) * raycast->delta_x;
	if (raycast->ray_dir_y < 0)
		raycast->side_dist_y = (y - (int)y) * raycast->delta_y;
	else
		raycast->side_dist_y = ((int)y + 1.0 - y) * raycast->delta_y;
}

/**
 * Function which searchs for the first collision, either on the X or Y axis.
 * Both sides start on the first cell collided by side dist and if it is not a
 * wall it continues to the next cell and so on until a collision is found on 
 * one of the sides.
*/
static void	collider(t_raycast *raycast, t_cube cube)
{
	int	cell_x;
	int	cell_y;

	cell_x = (int)cube.map.player_x;
	cell_y = (int)cube.map.player_y;
	while (cube.map.map[cell_y][cell_x] != '1')
	{
		if (raycast->side_dist_x < raycast->side_dist_y)
		{
			raycast->side_dist_x += raycast->delta_x;
			cell_x += raycast->step_x;
			raycast->collided_side = X;
		}
		else
		{
			raycast->side_dist_y += raycast->delta_y;
			cell_y += raycast->step_y;
			raycast->collided_side = Y;
		}
	}
}

static void	set_and_paint_ray(t_cube *cube, int x)
{
	if (cube->raycast.collided_side == X)
		cube->raycast.dist = cube->raycast.side_dist_x - cube->raycast.delta_x;
	else
		cube->raycast.dist = cube->raycast.side_dist_y - cube->raycast.delta_y;
	if (fabs(cube->raycast.dist - 0.0) < EPSILON)
		cube->raycast.dist = SPEED / 2;
	cube->raycast.height = (int)(WIN_Y / cube->raycast.dist);
	cube->raycast.start = -cube->raycast.height / 2 + WIN_Y / 2;
	if (cube->raycast.start < 0)
		cube->raycast.start = 0;
	cube->raycast.end = cube->raycast.height / 2 + WIN_Y / 2;
	if (cube->raycast.end >= WIN_Y)
		cube->raycast.end = WIN_Y - 1;
	paint_ray(*cube, x);
}

/**
 * Function which throws n rays, where n is equal to the width of the window.
 * For each ray, camera is calculated, which controls the direction of the
 * plain vector. Camera values will go from -1 to 1. Calculate the ray dir
 * vector which is the addition of the dir of the the player (the center of
 * their view) and the plane vector deviated by the camera value.
*/
void	raycasting(t_cube *cube)
{
	int			i;

	i = 0;
	while (i < WIN_X)
	{
		cube->raycast.camera = (2 * i / (double)WIN_X) - 1;
		cube->raycast.ray_dir_x = cube->map.dir_x
			+ (FOV * -cube->map.dir_y * cube->raycast.camera);
		cube->raycast.ray_dir_y = cube->map.dir_y
			+ (FOV * cube->map.dir_x * cube->raycast.camera);
		set_delta(&cube->raycast);
		set_step_and_side(&cube->raycast, cube->map.player_x,
			cube->map.player_y);
		collider(&cube->raycast, *cube);
		set_and_paint_ray(cube, i);
		i++;
	}
	print_minimap(cube);
	mlx_put_image_to_window(cube->mlx.mlx, cube->mlx.win,
		cube->mlx.img.img, 0, 0);
}
