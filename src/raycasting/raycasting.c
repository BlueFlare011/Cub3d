#include "cube.h"

/**
 * Function which sets delta for the 2 axis, after a few demonstrations
 * the formula is delta_i = 1 / ray_dir_i. REMINDER: keep in mind the case when
 * ray_dir_i = 0, delta_i = INF.
*/
static void	set_delta(t_raycast *raycast)
{
	if (raycast->ray_dir_x)
		raycast->delta_x = 1 / raycast->ray_dir_x;
	else
		raycast->delta_x = __DBL_MAX__;
	if (raycast->ray_dir_y)
		raycast->delta_y = 1 / raycast->ray_dir_y;
	else
		raycast->delta_y = __DBL_MAX__;
}

/**
 * Function which calculates the step. It is 1 cell step if the component is
 * positive or negative if it is negative. To calculate the side distance is
 * needed to calculate the lower distance from the point to one of the sides
 * multiplied by the delta of the component.
*/
static void	set_step_and_side(t_raycast *raycast, int x, int y)
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
		raycast->side_dist_x = ((int)x + 1 - x) * raycast->delta_x;
	if (raycast->ray_dir_y < 0)
		raycast->side_dist_y = (y - (int)y) * raycast->delta_y;
	else
		raycast->side_dist_y = ((int)y + 1 - y) * raycast->delta_y;
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

	cell_x = (int)cube.map->player_x;
	cell_y = (int)cube.map->player_y;
	while(cube.map->map[cell_y][cell_x] != '1')
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

static void	set_and_paint_ray(t_raycast raycast, t_cube cube, int x)
{
	double	dist;
	int		height;
	int		start;
	int		end;

	if (raycast.collided_side == X)
		dist = raycast.side_dist_x - raycast.delta_x;
	else
		dist = raycast.side_dist_y - raycast.delta_y;
	height = (int)(WIN_Y / dist);
	printf("dis = %f, height = %d\n", dist, height);
	start = (-height + WIN_Y) / 2;
	if (start < 0)
		start = 0;
	end = (height + WIN_Y) / 2;
	if (end > WIN_Y)
		end = WIN_Y - 1;
	paint_ray(cube, x, start, end);
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
	t_raycast	raycast;

	i = 0;
	while (i < WIN_X)
	{
		raycast.camera = (2 * i / WIN_X) - 1;
		raycast.ray_dir_x = cube->map->dir_x + (PLANE_X * raycast.camera);
		raycast.ray_dir_y = cube->map->dir_y + (PLANE_Y * raycast.camera);
		set_delta(&raycast);
		set_step_and_side(&raycast, cube->map->player_x, cube->map->player_y);
		collider(&raycast, *cube);
		set_and_paint_ray(raycast, *cube, i);
		i++;
	}
	mlx_put_image_to_window(cube->mlx->mlx, cube->mlx->win, cube->mlx->img->img, 0, 0);
}
