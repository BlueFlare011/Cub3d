/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:49:32 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/21 18:03:14 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	settle_player(t_cube *cube, int *num_player, int i, int j)
{
	(*num_player)++;
	cube->map.player_x = (double)j + 0.5;
	cube->map.player_y = (double)i + 0.5;
	if (cube->map.map[i][j] == 'N')
	{
		cube->map.dir_x = N_X;
		cube->map.dir_y = N_Y;
	}
	else if (cube->map.map[i][j] == 'E')
	{
		cube->map.dir_x = E_X;
		cube->map.dir_y = E_Y;
	}
	else if (cube->map.map[i][j] == 'S')
	{
		cube->map.dir_x = S_X;
		cube->map.dir_y = S_Y;
	}
	else if (cube->map.map[i][j] == 'W')
	{
		cube->map.dir_x = W_X;
		cube->map.dir_y = W_Y;
	}
}

static void	check_chars(t_cube *cube, int num_player, int i, int j)
{
	while (cube->map.map[i] && (!i || !cube->map.map[i - 1][j]))
	{
		j = 0;
		while (cube->map.map[i][j]
			&& ft_strchr("NESW10 ", cube->map.map[i][j]) && num_player <= 1)
		{
			if (ft_strchr("NESW", cube->map.map[i][j]))
				settle_player(cube, &num_player, i, j);
			if (ft_strchr("NESW10 ", cube->map.map[i][j]))
				j++;
		}
		if (!cube->map.map[i][j] && j > cube->map.max_x)
			cube->map.max_x = j - 1;
		if (!cube->map.map[i][j])
			i++;
	}
	if (num_player != 1)
		error_exit(TOO_MUCH_PLAYERS, GENERAL_ERR, cube);
	else if (cube->map.map[i])
		error_exit(INVALID_CHAR, GENERAL_ERR, cube);
	cube->map.max_y = i - 1;
}

void	valid_map(t_cube *cube)
{
	cube->map.player_x = 0;
	cube->map.player_y = 0;
	check_chars(cube, 0, 0, 0);
	floodfill(cube);
}
