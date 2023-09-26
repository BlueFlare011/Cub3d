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

static void	set_step_and_side(t_raycast *raycast)
{
	raycast->step_x = 1;
	raycast->step_y = 1;
	if (raycast->ray_dir_x < 0)
		raycast->step_x = -1;
	if (raycast->ray_dir_y < 0)
		raycast->step_y = -1;
}

/**
 * - Function which throws n rays, where n is equal to the width of the window.
 * - For each ray, camera is calculated, which controls the direction of the
 *   plain vector. Camera values will go from -1 to 1.
 * - Calculate the ray dir vector which is the addition of the dir of the
 *   the player (the center of their view) and the plane vector deviated by
 *   the camera value.
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
		set_step_and_side(&raycast);
		i++;
	}
}
