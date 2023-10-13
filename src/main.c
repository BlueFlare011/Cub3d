/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:34:12 by socana-b          #+#    #+#             */
/*   Updated: 2023/10/13 19:31:56 by rgallego         ###   ########.fr       */
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

// int	check(void)
// {
	// char	**matrix;
	// char *str = "Prueba  uno y    2  ";
	// 
	// matrix = ft_split(str, ',');
	// printf("%s\n", *matrix);
	// pito(matrix);
	// return(0);
// }

int	main(int argc, char **argv)
{
	t_cube	*cube;

	check_arguments(argc, argv);
	cube = extract_file_info(argv[1]);
	cube->mlx->player_x = (cube->map->player_x * CUBE_SIZE) + (CUBE_SIZE / 2);
	cube->mlx->player_y = (cube->map->player_y * CUBE_SIZE) + (CUBE_SIZE / 2);
	ft_mlx_init(cube);
	raycasting(cube);
	mlx_put_image_to_window(cube->mlx->mlx, cube->mlx->win, cube->mlx->img->img, 0, 0);
	mlx_hook(cube->mlx->win, ON_KEYDOWN, MASK, key_control, cube);
	mlx_loop(cube->mlx->mlx);
	delete_struct(cube);
	return (0);
}
