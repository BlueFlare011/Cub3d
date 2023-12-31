/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 23:42:52 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/23 22:02:56 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	is_in_map(char **map, int x, int y)
{
	if (y < 0 || x < 0 || y >= len_double_pointer(map)
		|| x >= (int)ft_strlen(map[y]))
		return (0);
	return (1);
}

static int	check_square(char **map, t_node *square)
{
	if (!is_in_map(map, square->x + 1, square->y)
		|| !is_in_map(map, square->x - 1, square->y)
		|| !is_in_map(map, square->x, square->y + 1)
		|| !is_in_map(map, square->x, square->y - 1))
		return (1);
	return (0);
}

static void	add_nearest(t_node **stack, char **map, int x, int y)
{
	if (ft_strchr("0 ", map[y + 1][x]))
		push(stack, y + 1, x);
	if (ft_strchr("0 ", map[y][x + 1]))
		push(stack, y, x + 1);
	if (ft_strchr("0 ", map[y - 1][x]))
		push(stack, y - 1, x);
	if (ft_strchr("0 ", map[y][x - 1]))
		push(stack, y, x - 1);
}

void	floodfill(t_cube *cube)
{
	t_node	*stack;
	t_node	*aux;

	stack = NULL;
	push(&stack, cube->map.player_y, cube->map.player_x);
	aux = stack;
	while (stack && aux)
	{
		aux = pop(&stack);
		if (aux)
		{
			if (check_square(cube->map.map, aux))
				error_exit(MAP_NOT_CLOSED, GENERAL_ERR, cube);
			if (ft_strchr("0 ", cube->map.map[aux->y][aux->x]))
				cube->map.map[aux->y][aux->x] = '2';
			add_nearest(&stack, cube->map.map, aux->x, aux->y);
			free(aux);
		}
	}
	delete_stack(&stack);
}
