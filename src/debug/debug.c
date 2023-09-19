#include "cube.h"

void	paint_window(t_cube *cube, void *mlx, void *win)
{
	int	i;
	int	j;
	int	length;

	length = 50;
	i = 0;
	void	*floor = mlx_xpm_file_to_image(mlx, "/home/blueflare011/Programacion/Cub3d/files/textures/white_square.xpm", &length, &length);
	void	*wall = mlx_xpm_file_to_image(mlx, "/home/blueflare011/Programacion/Cub3d/files/textures/black_square.xpm", &length, &length);
	while (i <= cube->map->max_y)
	{
		j = 0;
		while (j <= cube->map->max_x)
		{
			if (cube->map->map[i][j] == '1')
				mlx_put_image_to_window(mlx, win, wall, j * 50, i * 50);
			if (cube->map->map[i][j] == '2' || ft_strchr("NSWE", cube->map->map[i][j]))
				mlx_put_image_to_window(mlx, win, floor, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	paint_lines(t_cube *cube, void *mlx, void *win)
{
	int	x;
	int	y;
	
	y = 0;
	while (y <= cube->map->max_y)
	{
		x = 0;
		while (x < (cube->map->max_x + 1) * 50)
		{
			mlx_pixel_put(mlx, win, x, y * 50, 0x0000FF);
			x++;	
		}
		y++;
	}
	x = 0;
	while (x <= cube->map->max_x)
	{
		y = 0;
		while (y < (cube->map->max_y + 1) * 50)
		{
			mlx_pixel_put(mlx, win, x * 50, y, 0x0000FF);
			y++;	
		}
		x++;
	}
}

void	debug_map(t_cube *cube)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, (cube->map->max_x + 1) * 50, (cube->map->max_y + 1) * 50, "Debuguiando");
	paint_window(cube, mlx, win);
	paint_lines(cube, mlx, win);
	mlx_loop(mlx);
}
