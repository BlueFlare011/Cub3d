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
	if (map_x < 0 || map_y < 0 || map_y >=len_double_pointer(cube->map.map)
		|| map_x >= (int)ft_strlen(cube->map.map[map_y]))
		return ;
	if (j % CUBE_SIZE == 0 || i % CUBE_SIZE == 0)
		return (my_pixel_put(cube->mlx.img, j, i, BORDER_COLOUR));
	if (fabs(cube->map.player_x - ((double)j / CUBE_SIZE + cube->map.player_x - 4)) < (0.2)
		&& fabs(cube->map.player_y - ((double)i / CUBE_SIZE + cube->map.player_y - 4)) < (0.2))
			return (my_pixel_put(cube->mlx.img, j, i, PLAYER_COLOUR));
	if (cube->map.map[map_y][map_x] == '1')
		return (my_pixel_put(cube->mlx.img, j, i, WALL_COLOUR));
	my_pixel_put(cube->mlx.img, j, i, FLOOR_COLOUR);
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
			print_wall(cube, i, j);
			j++;
		}
		i++;
	}
	
}
