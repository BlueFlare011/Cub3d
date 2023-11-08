#include "minimap_bonus.h"

static void	print_wall(t_cube *cube, int i, int j)
{
	int	min_x;
	int	min_y;

	min_x = (int)cube->map.player_x - 4;
	min_y = (int)cube->map.player_y - 4;
	if ((int)cube->map.player_x == j / 20 + min_x && (int)cube->map.player_y == i / 20 + min_y)
		my_pixel_put(cube->mlx.img, j, i, 0x00FF00);
	if (j / 20 + min_x >= 0 && i / 20 + min_y >= 0
		&& min_x + j / 20 <= cube->map.max_x && min_y + i / 20 <= cube->map.max_y
		&& cube->map.map[i / 20 + min_y][j / 20 + min_x] == '1')
			my_pixel_put(cube->mlx.img, j, i, 0xB0B0B0);
}

void	print_minimap(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINI_MAP)
	{
		j = 0;
		while (j < MINI_MAP)
		{
			my_pixel_put(cube->mlx.img, j, i, 0x000000);
			print_wall(cube, i, j);
			if (j % 20 == 0 || i % 20 == 0)
				my_pixel_put(cube->mlx.img, j, i, 0x505050);
			j++;
		}
		i++;
	}
	
}
