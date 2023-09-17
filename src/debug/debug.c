#include "cube.h"

void	paint_window(t_cube *cube, void *mlx, void *win)
{
	int	i;
	int	j;
	int	length;

	length = 50;
	i = 0;
	void	*floor = mlx_xpm_file_to_image(mlx, "../../files/textures/white_square.xpm", &length, &length);
	void	*wall = mlx_xpm_file_to_image(mlx, "../../files/textures/black_square.xpm", &length, &length);
	while (cube->map->map[i])
	{
		j = 0;
		while (cube->map->map[i][j])
		{
			if (cube->map->map[i][j] == '1')
				mlx_put_image_to_window(mlx, win, wall, j * 50, i * 50);
			if (cube->map->map[i][j] == '0' || ft_strchr("NSWE", cube->map->map[i][j]))
				mlx_put_image_to_window(mlx, win, floor, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	debug_map(t_cube *cube)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, cube->map->max_x * 50, cube->map->max_y * 50, "Debuguiando");
	paint_window(cube, mlx, win);
	mlx_loop(mlx);
}
