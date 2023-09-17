/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:49:32 by rgallego          #+#    #+#             */
/*   Updated: 2023/09/17 17:50:49 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_chars(char **map, int *max_x, int *max_y, int num_players)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] && !ft_strchr("10 ", map[i][j]) && num_players <= 1)
	{
		j = 0;
		while (map[i][j] && !ft_strchr("10 ", map[i][j]) && num_players <= 1)
		{
			if (ft_strchr("NESW", map[i][j]))
				num_players++;
			j++;
		}
		if ((j > *max_x) && ft_strchr("10 ", map[i][j]) && num_players <= 1)
		{
			*max_x = j - 1;
			i++;
		}
	}
	if (num_players != 1)
		error_exit(TOO_MUCH_PLAYERS, GENERAL_ERR);
	if (!ft_strchr("10 ", map[i][j]))
		error_exit(INVALID_CHAR, GENERAL_ERR);
	*max_y = i - 1;
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

void	locate_start(t_cube *cube, t_node *stack)
{
	int	i;
	int	j;

	i = 0;
	while (cube->map[i])
	{
		j = 0;
		while (cube->map[i][j])
		{
			if (cube->map[i][j] == 'N' || cube->map[i][j] == 'S' ||
				cube->map[i][j] == 'E' || cube->map[i][j] == 'W')
				break ;
			j++;
		}
		if (cube->map[i][j])
			break ;
		i++;
	}
	push(stack, i, j);
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

void	floodfill(t_cube *cube, int max_x, int max_y)
{
	t_node	*stack;
	t_node	*aux;

	stack = create_node();
	locate_start(cube, stack);
	while (stack)
	{
		aux = pop(stack);
		if (!aux)
			break ;
		if (check_square(cube->map, aux, max_y, max_x))
			error_exit(MAP_NOT_CLOSED, GENERAL_ERR);
		//printf("Coor: %d %d\nChar: %c\n", aux->y, aux->x, cube->map[aux->y][aux->x]);
		if (cube->map[aux->y][aux->x] == '0')
			cube->map[aux->y][aux->x] = '2';
		if (cube->map[aux->y + 1][aux->x] == '0')
			push(stack, aux->y + 1, aux->x);
		if (cube->map[aux->y - 1][aux->x] == '0')
			push(stack, aux->y - 1, aux->x);
		if (cube->map[aux->y][aux->x + 1] == '0')
			push(stack, aux->y, aux->x + 1);
		if (cube->map[aux->y][aux->x - 1] == '0')
			push(stack, aux->y, aux->x - 1);
		free(aux);
	}
	free(stack);
}

void	valid_map(t_cube *cube)
{
	int	max_x;
	int	max_y;

	max_x = 0;
	check_chars(cube->map, &max_x, &max_y, 0);
	untrim_map(cube->map, max_x);
	floodfill(cube, max_x, max_y);
}
