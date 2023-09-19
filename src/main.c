/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blueflare011 <blueflare011@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:34:12 by socana-b          #+#    #+#             */
/*   Updated: 2023/09/20 00:05:30 by blueflare01      ###   ########.fr       */
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
	//print_cube(cube);
	debug_map(cube);
	delete_struct(cube);
	return (0);
}
