/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blueflare011 <blueflare011@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:34:12 by socana-b          #+#    #+#             */
/*   Updated: 2023/11/24 20:17:19 by blueflare01      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "errors.h"
#include "events.h"
#include "keys.h"
#include "mlx_management.h"
#include "parser.h"
#include "raycasting.h"
#include "stack.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	t_cube	cube;

	init_cube(&cube);
	check_arguments(argc, argv);
	extract_file_info(&cube, argv[1]);
	//mlx_mouse_move(cube.mlx.win, WIN_X / 2, WIN_Y / 2); // MacOs
	mlx_mouse_move(cube.mlx.mlx, cube.mlx.win, WIN_X / 2, WIN_Y / 2); // Linux
	raycasting(&cube);
	mlx_hook(cube.mlx.win, ON_KEYDOWN, PRESS_MASK, key_down, &cube);
	mlx_hook(cube.mlx.win, ON_KEYRELEASE, RELEASE_MASK, key_release, &cube);
	mlx_hook(cube.mlx.win, ON_DESTROY, PRESS_MASK, close_window_x, &cube);
	mlx_loop_hook(cube.mlx.mlx, event_management, &cube);
	mlx_loop(cube.mlx.mlx);
	free_cube(&cube);
	return (0);
}
