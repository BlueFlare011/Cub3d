/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:13:25 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/22 14:56:51 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

static void	move(t_cube *cube, double move_x, double move_y)
{
	double	x;
	double	y;

	x = cube->map.player_x + move_x;
	y = cube->map.player_y + move_y;
	if (cube->map.map[(int)y][(int)x] != '1')
	{
		cube->map.player_x = x;
		cube->map.player_y = y;
	}
	else if ((fabs(move_x) > fabs(move_y))
		&& cube->map.map[(int)cube->map.player_y][(int)x] != '1')
		cube->map.player_x = x;
	else if ((fabs(move_x) < fabs(move_y))
		&& cube->map.map[(int)y][(int)cube->map.player_x] != '1')
		cube->map.player_y = y;
}

static void	rotation(t_cube *cube, double alpha)
{
	double	aux;

	aux = cube->map.dir_x;
	cube->map.dir_x = cube->map.dir_x * cos(alpha)
		- cube->map.dir_y * sin(alpha);
	cube->map.dir_y = aux * sin(alpha) + cube->map.dir_y * cos(alpha);
}

int	key_down(int keycode, t_cube *cube)
{
	if (keycode == KEY_ESC)
	{
		free_cube(cube);
		exit(0);
	}
	if (keycode == KEY_A)
		cube->keys.a = 1;
	if (keycode == KEY_W)
		cube->keys.w = 1;
	if (keycode == KEY_S)
		cube->keys.s = 1;
	if (keycode == KEY_D)
		cube->keys.d = 1;
	if (keycode == KEY_LEFT)
		cube->keys.left = 1;
	if (keycode == KEY_RIGHT)
		cube->keys.right = 1;
	return (0);
}

int	key_release(int keycode, t_cube *cube)
{
	if (keycode == KEY_A)
		cube->keys.a = 0;
	if (keycode == KEY_W)
		cube->keys.w = 0;
	if (keycode == KEY_S)
		cube->keys.s = 0;
	if (keycode == KEY_D)
		cube->keys.d = 0;
	if (keycode == KEY_LEFT)
		cube->keys.left = 0;
	if (keycode == KEY_RIGHT)
		cube->keys.right = 0;
	return (0);
}

int	event_management(t_cube *cube)
{
	double	speed;

	speed = SPEED;
	if ((cube->keys.a || cube->keys.d) && (cube->keys.w || cube->keys.s))
		speed = sqrt(2 * (pow(SPEED, 2)));
	if (cube->keys.a)
		move(cube, cube->map.dir_y * speed, -cube->map.dir_x * speed);
	if (cube->keys.w)
		move(cube, cube->map.dir_x * speed, cube->map.dir_y * speed);
	if (cube->keys.s)
		move(cube, -cube->map.dir_x * speed, -cube->map.dir_y * speed);
	if (cube->keys.d)
		move(cube, -cube->map.dir_y * speed, cube->map.dir_x * speed);
	if (cube->keys.left)
		rotation(cube, -M_PI / ALPHA_RATIO);
	if (cube->keys.right)
		rotation(cube, M_PI / ALPHA_RATIO);
	raycasting(cube);
	return (0);
}
