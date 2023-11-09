#include "minimap_bonus.h"

static void	print_wall(t_cube *cube, int i, int j)
{
	int	min_x;
	int	min_y;
	int	map_x;
	int	map_y;

	min_x = (int)cube->map.player_x - 4;
	min_y = (int)cube->map.player_y - 4;
	map_x = j / CUBE_SIZE + min_x;
	map_y = i / CUBE_SIZE + min_y;
	if (len_double_pointer(cube->map.map) <= map_y
		|| (int)ft_strlen(cube->map.map[map_y]) <= map_x)
		return ;
	if ((int)cube->map.player_x == map_x && (int)cube->map.player_y == map_y)
		my_pixel_put(cube->mlx.img, j, i, PLAYER_COLOUR);
	if (map_x >= 0 && map_y >= 0
		&& map_x <= cube->map.max_x && map_y <= cube->map.max_y
		&& cube->map.map[map_y][map_x] == '1')
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
			if (j % 20 == 0 || i % 20 == 0)
				my_pixel_put(cube->mlx.img, j, i, 0x505050);
			j++;
		}
		i++;
	}
	
}
