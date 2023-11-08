#include "minimap_bonus.h"

static void	print_wall(t_cube *cube, int i, int j)
{
	int	min_x;
	int	min_y;

	min_x = (int)cube->map.player_x - 4;
	min_y = (int)cube->map.player_y - 4;
	if ((int)cube->map.player_x == j / CUBE_SIZE + min_x && (int)cube->map.player_y == i / CUBE_SIZE + min_y)
		my_pixel_put(cube->mlx.img, j, i, PLAYER_COLOUR);
	if (j / CUBE_SIZE + min_x >= 0 && i / CUBE_SIZE + min_y >= 0
		&& min_x + j / CUBE_SIZE <= cube->map.max_x && min_y + i / CUBE_SIZE <= cube->map.max_y
		&& len_double_pointer(cube->map.map) > i / CUBE_SIZE + min_y
		&& (int)ft_strlen(cube->map.map[i / CUBE_SIZE + min_y]) > j / CUBE_SIZE + min_x
		&& cube->map.map[i / CUBE_SIZE + min_y][j / CUBE_SIZE + min_x] == '1')
			my_pixel_put(cube->mlx.img, j, i, WALL_COLOUR);
}

void	print_minimap(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINIMAP_SIZE)
	{
		j = 0;
		while (j < MINIMAP_SIZE)
		{
			my_pixel_put(cube->mlx.img, j, i, FLOOR_COLOUR);
			print_wall(cube, i, j);
			// if (j % 20 == 0 || i % 20 == 0)
			// 	my_pixel_put(cube->mlx.img, j, i, 0x505050);
			j++;
		}
		i++;
	}
	
}
