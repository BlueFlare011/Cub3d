#include "parser.h"

int	check_square(t_cube *cube, int x, int y)
{
	if (cube->map.map[y][x] == '0' || ft_strchr("NSWE", cube->map.map[y][x])){
		if (!x || !y || cube->map.max_y == y || !cube->map.map[y][x + 1])
			return (1);
		if ((int)ft_strlen(cube->map.map[y + 1]) <= x || (int)ft_strlen(cube->map.map[y - 1]) <= x)
			return (1);
		if (cube->map.map[y + 1][x] == ' ' || cube->map.map[y - 1][x] == ' ' ||
			cube->map.map[y][x + 1] == ' ' || cube->map.map[y][x - 1] == ' ')
			return (1);
	}
	return (0);
}

void	shitty_check(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	while (cube->map.map[i])
	{
		j = 0;
		while (cube->map.map[i][j])
		{
			if (check_square(cube, j, i))
				error_exit(MAP_NOT_CLOSED, GENERAL_ERR, cube);
			j++;
		}
		i++;
	}
}