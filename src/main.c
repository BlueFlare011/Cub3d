/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:34:12 by socana-b          #+#    #+#             */
/*   Updated: 2023/10/21 14:50:44 by rgallego         ###   ########.fr       */
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

void	check_arguments(int num, char **args)
{
	char	*extension;

	if (num != 2)
		return (error_exit(ERROR_NUM_ARGS, GENERAL_ERR));
	extension = ft_strrchr(args[1], '.');
	if (!extension)
		return (error_exit(NO_EXTENSION, GENERAL_ERR));
	if (ft_strncmp(extension, ".cub", 4))
		return (error_exit(NO_VALID_EXTENSION, GENERAL_ERR));
}

int	main(int argc, char **argv)
{
	t_cube	cube;

	check_arguments(argc, argv);
	extract_file_info(&cube, argv[1]);
	raycasting(&cube);
	mlx_hook(cube.mlx.win, ON_KEYDOWN, PRESS_MASK, key_down, &cube);
	mlx_hook(cube.mlx.win, ON_KEYRELEASE, RELEASE_MASK, key_release, &cube);
	mlx_loop_hook(cube.mlx.mlx, event_management, &cube);
	mlx_loop(cube.mlx.mlx);
	// delete_struct(cube);
	return (0);
}
