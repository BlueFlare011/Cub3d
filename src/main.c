/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:34:12 by socana-b          #+#    #+#             */
/*   Updated: 2023/11/08 14:09:30 by rgallego         ###   ########.fr       */
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
	mlx_mouse_move(cube.mlx.win, WIN_X / 2, WIN_Y / 2); // MacOs
	// mlx_mouse_move(cube.mlx.mlx, cube.mlx.win, WIN_X / 2, WIN_Y / 2); // Linux
	raycasting(&cube);
	mlx_hook(cube.mlx.win, ON_KEYDOWN, PRESS_MASK, key_down, &cube);
	mlx_hook(cube.mlx.win, ON_KEYRELEASE, RELEASE_MASK, key_release, &cube);
	mlx_hook(cube.mlx.win, 17, 1L << 17, close_window_x, &cube);
	mlx_loop_hook(cube.mlx.mlx, event_management, &cube);
	mlx_loop(cube.mlx.mlx);
	free_cube(&cube);
	return (0);
}
