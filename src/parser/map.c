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
			if (map[i][j] != '1' || map[i][j] != '0' || map[i][j] != ' ')
				return (1);
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				aux++;
			if (aux != 1)
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

int	is_closed_up(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[i][j])
	{
		i = 0;
		while (map[i] && map[i][j] == ' ')
			i++;
		if (map[i] && map[i][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	is_closed_down(char **map, int y_max)
{
	int	i;
	int	j;

	j = 0;
	i = y_max;
	while (map[i][j])
	{
		i = y_max;
		while (map[i][j] == ' ')
			i--;
		if (map[i][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	is_closed_left(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] == ' ')
			j++;
		if (map[i][j] && map[i][j] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	is_closed_right(char **map, int x_max)
{
	int	i;
	int	j;

	j = x_max;
	i = 0;
	while (map[i])
	{
		j = x_max;
		while (j > 0 && map[i][j] == ' ')
			j--;
		if (j > 0 && map[i][j] != '1')
			return (1);
		i++;
	}
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
			aux = malloc(sizeof(char) * (max_x + 1));
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

int	valid_map(char **map)
{
	int	max_x;
	int	max_y;

	max_x = 0;
	if (check_chars(map, &max_x, &max_y, 0))
		return (1);
	if (untrim_map(map, max_x))
		return (1);
	if (is_closed_up(map) || is_closed_down(map, max_y) ||
		is_closed_left(map) || is_closed_right(map, max_x))
		return (1);
	return (0);
}
