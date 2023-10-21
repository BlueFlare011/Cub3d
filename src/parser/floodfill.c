/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 23:42:52 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/21 18:03:24 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_square(char **map, t_node *square)
{
	if (!square->x || !square->y
		|| !map[square->y + 1][square->x + 1] || !map[square->y][square->x + 1]
		|| !map[square->y - 1][square->x + 1] || !map[square->y + 1][square->x]
		|| !map[square->y - 1][square->x - 1])
		return (1);
	return (0);
}

void	add_nearest(t_node **stack, char **map, int x, int y)
{
	if (ft_strchr("0 ", map[y + 1][x]))
		push(stack, y + 1, x);
	if (ft_strchr("0 ", map[y][x + 1]))
		push(stack, y, x + 1);
	if (ft_strchr("0 ", map[y - 1][x]))
		push(stack, y - 1, x);
	if (ft_strchr("0 ", map[y][x - 1]))
		push(stack, y, x - 1);
	if (ft_strchr("0 ", map[y + 1][x - 1]))
		push(stack, y + 1, x - 1);
	if (ft_strchr("0 ", map[y + 1][x + 1]))
		push(stack, y + 1, x + 1);
	if (ft_strchr("0 ", map[y - 1][x + 1]))
		push(stack, y - 1, x + 1);
	if (ft_strchr("0 ", map[y - 1][x - 1]))
		push(stack, y - 1, x - 1);
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
