/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blueflare011 <blueflare011@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:49:32 by rgallego          #+#    #+#             */
/*   Updated: 2023/09/18 17:57:31 by blueflare01      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_chars(t_cube *cube, int num_player, int i, int j)
{
	while (cube->map->map[i] && (!i || !cube->map->map[i - 1][j]))
	{
		j = 0;
		while (cube->map->map[i][j]
			&& ft_strchr("NESW10 ", cube->map->map[i][j]) && num_player <= 1)
		{
			if (ft_strchr("NESW", cube->map->map[i][j]))
			{
				num_player++;
				cube->map->player_x = j;
				cube->map->player_y = i;
			}
			if (ft_strchr("NESW10 ", cube->map->map[i][j]))
				j++;
		}
		if (!cube->map->map[i][j] && j > cube->map->max_x)
			cube->map->max_x = j - 1;
		if (!cube->map->map[i][j])
			i++;
	}
	if (num_player != 1)
		error_exit(TOO_MUCH_PLAYERS, GENERAL_ERR);
	else if (cube->map->map[i])
		error_exit(INVALID_CHAR, GENERAL_ERR);
	cube->map->max_y = i - 1;
}

void	untrim_map(char **map, int max_x)
{
	int		i;
	int		j;
	char	*aux;

	i = 0;
	while (map[i] && (!i || aux))
	{
		if ((int)ft_strlen(map[i]) < max_x)
		{
			aux = malloc(sizeof(char) * (max_x + 2));
			if (aux)
			{
				j = ft_strlen(map[i]);
				strncpy(aux, map[i], j);
				while (j <= max_x)
					aux[j++] = ' ';
				aux[j] = '\0';
				free(map[i]);
				map[i] = aux;
			}
		}
		i++;
	}
	if (!aux)
		error_exit(strerror(errno), SYS_ERR);
}

void	valid_map(t_cube *cube)
{
	cube->map->player_x = 0;
	cube->map->player_y = 0;
	check_chars(cube, 0, 0, 0);
	untrim_map(cube->map->map, cube->map->max_x);
	floodfill(cube);
}
