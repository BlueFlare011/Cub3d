/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:13:25 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/21 01:01:31 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

#include <stdio.h>

static void	move(t_cube cube, double move_x, double move_y)
{
	double	x;
	double	y;
	// double	aux;

	// aux = cube.map->player_x;
	x = cube.map->player_x + move_x;
	y = cube.map->player_y + move_y;
	printf("move_x = %f, move_y = %f\n", move_x, move_y);
	if (cube.map->map[(int)y][(int)x] == '1')
		return ;
	cube.map->player_x = x;
	cube.map->player_y = y;
}

static void	rotation(t_cube cube, double alpha)
{
	double	aux;

	aux = cube.map->dir_x;
	cube.map->dir_x = cube.map->dir_x * cos(alpha)
		- cube.map->dir_y * sin(alpha);
	cube.map->dir_y = aux * sin(alpha) + cube.map->dir_y * cos(alpha);
}

int	key_down(int keycode, t_cube *cube)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(cube->mlx->mlx, cube->mlx->win);
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
		move(*cube, cube->map->dir_y * speed, -cube->map->dir_x * speed);
	if (cube->keys.w)
		move(*cube, cube->map->dir_x * speed, cube->map->dir_y * speed);
	if (cube->keys.s)
		move(*cube, -cube->map->dir_x * speed, -cube->map->dir_y * speed);
	if (cube->keys.d)
		move(*cube, -cube->map->dir_y * speed, cube->map->dir_x * speed);
	if (cube->keys.left)
		rotation(*cube, -ALPHA);
	if (cube->keys.right)
		rotation(*cube, ALPHA);
	raycasting(cube);
	return (0);
}
