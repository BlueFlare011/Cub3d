/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:49:32 by rgallego          #+#    #+#             */
/*   Updated: 2023/09/17 23:27:47 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	check_chars(t_cube *cube, int num_player)
{
	int	i;
	int	j;

	i = 0;
	while (cube->map->map[i])
	{
		j = 0;
		while (cube->map->map[i][j])
		{
			if (ft_strchr("NESW", cube->map->map[i][j]))
			{
				num_player++;
				cube->map->char_x = j;
				cube->map->char_y = i;
			}
			else if (!ft_strchr("10 ", cube->map->map[i][j]))
				error_exit(INVALID_CHAR, GENERAL_ERR);
			j++;
		}
		if (j > cube->map->max_x)
			cube->map->max_x = j - 1;
		i++;
	}
	if (num_player != 1)
		error_exit(TOO_MUCH_PLAYERS, GENERAL_ERR);
	cube->map->max_y = i - 1;
	return (0);
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

int	check_square(char **map, t_node *square, int max_y, int max_x)
{
	if (square->x == 0 || square->y == 0 || square->y == max_y
		|| square->x == max_x)
		return (1);
	if (map[square->y + 1][square->x] == ' ' ||
		map[square->y - 1][square->x] == ' ' ||
		map[square->y][square->x + 1] == ' ' ||
		map[square->y][square->x - 1] == ' ')
		return (1);
	return (0);
}

void	floodfill(t_cube *cube)
{
	t_node	*stack;
	t_node	*aux;

	stack = NULL;
	push(&stack, cube->map->char_x, cube->map->char_y);
	while (stack)
	{
		aux = pop(&stack);
		if (!aux)
			break ;
		if (check_square(cube->map->map, aux, cube->map->max_y, cube->map->max_x))
			error_exit(MAP_NOT_CLOSED, GENERAL_ERR);
		//printf("Coor: %d %d\nChar: %c\n", aux->y, aux->x, cube->map[aux->y][aux->x]);
		if (cube->map->map[aux->y][aux->x] == '0')
			cube->map->map[aux->y][aux->x] = '2';
		if (cube->map->map[aux->y + 1][aux->x] == '0')
			push(&stack, aux->y + 1, aux->x);
		if (cube->map->map[aux->y - 1][aux->x] == '0')
			push(&stack, aux->y - 1, aux->x);
		if (cube->map->map[aux->y][aux->x + 1] == '0')
			push(&stack, aux->y, aux->x + 1);
		if (cube->map->map[aux->y][aux->x - 1] == '0')
			push(&stack, aux->y, aux->x - 1);
		free(aux);
	}
	delete_stack(&stack);
}

void	valid_map(t_cube *cube)
{
	cube->map->char_x = 0;
	cube->map->char_y = 0;
	check_chars(cube, 0);
	untrim_map(cube->map->map, cube->map->char_x);
	floodfill(cube);	
}
