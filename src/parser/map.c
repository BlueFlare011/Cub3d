#include "cube.h"

int	check_chars(char **map, int *max_x, int *max_y, int aux)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				aux++;
			else if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' ')
				return (1);
			if (aux > 1)
				return (1);
			j++;
		}
		if (j > *max_x)
			*max_x = j - 1;
		i++;
	}
	*max_y = i - 1;
	return (0);
}

int	untrim_map(char **map, int max_x)
{
	int		i;
	int		j;
	char	*aux;

	i = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) < max_x)
		{
			aux = malloc(sizeof(char) * (max_x + 2));
			if (!aux)
				return (1);
			strncpy(aux, map[i], ft_strlen(map[i]));
			j = ft_strlen(map[i]);
			while (j <= max_x)
				aux[j++] = ' ';
			aux[j] = '\0';
			free(map[i]);
			map[i] = aux;
		}
		i++;
	}
	return (0);
}

void locate_start(t_info *info, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == 'N' || info->map[i][j] == 'S' ||
				info->map[i][j] == 'E' || info->map[i][j] == 'W')
				break ;
			j++;
		}
		if (info->map[i][j])
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
	if	(map[square->y + 1][square->x] == ' ' ||
		map[square->y - 1][square->x] == ' ' ||
		map[square->y][square->x + 1] == ' ' ||
		map[square->y][square->x - 1] == ' ')
		return (1);
	return (0);
}

void	floodfill(t_info *info, int max_x, int max_y)
{
	t_stack	*stack;
	t_node	*aux;

	stack = malloc(sizeof(stack));
	if (!stack)
		error_exit(strerror(errno), info);
	create_stack(stack);
	locate_start(info, stack);
	while (stack)
	{
		aux = pop(stack);
		if (!aux)
			break ;
		if (check_square(info->map, aux, max_y, max_x))
			error_exit(MAP_NOT_CLOSED, info);
		//printf("Coor: %d %d\nChar: %c\n", aux->y, aux->x, info->map[aux->y][aux->x]);
		if (info->map[aux->y][aux->x] == '0')
			info->map[aux->y][aux->x] = '2';
		if (info->map[aux->y + 1][aux->x] == '0')
			push(stack, aux->y + 1, aux->x);
		if (info->map[aux->y - 1][aux->x] == '0')
			push(stack, aux->y - 1, aux->x);
		if (info->map[aux->y][aux->x + 1] == '0')
			push(stack, aux->y, aux->x + 1);
		if (info->map[aux->y][aux->x - 1] == '0')
			push(stack, aux->y, aux->x - 1);
		free(aux);
	}
	free(stack);
}

void	valid_map(t_info *info)
{
	int	max_x;
	int	max_y;

	max_x = 0;
	if (check_chars(info->map, &max_x, &max_y, 0))
		exit(1);
	if (untrim_map(info->map, max_x))
		exit(1);
	floodfill(info, max_x, max_y);	
}
