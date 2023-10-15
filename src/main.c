/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:34:12 by socana-b          #+#    #+#             */
/*   Updated: 2023/10/13 23:30:03 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
	t_cube	*cube;

	check_arguments(argc, argv);
	cube = extract_file_info(argv[1]);
	ft_mlx_init(cube);
	raycasting(cube);
	mlx_hook(cube->mlx->win, ON_KEYDOWN, MASK, key_control, cube);
	mlx_loop(cube->mlx->mlx);
	delete_struct(cube);
	return (0);
}
