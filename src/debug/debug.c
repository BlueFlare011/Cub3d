#include "cube.h"

void	paint_lines(t_cube *cube, t_debug *info)
{
	int	x;
	int	y;
	
	y = 0;
	while (y <= cube->map->max_y)
	{
		x = 0;
		while (x < (cube->map->max_x + 1) * 50)
		{
			mlx_pixel_put(info->mlx, info->window, x, y * 50, 0x0000FF);
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
			mlx_pixel_put(info->mlx, info->window, x * 50, y, 0x0000FF);
			y++;	
		}
		x++;
	}
}

void	repaintNear(t_cube *cube, t_debug *info)
{
	int	i;
	int	j;
	int	max_x;
	int	max_y;

	i = (info->player_y / 50) - 1;
	j = (info->player_x / 50) - 1;
	max_x = j + 2;
	max_y = i + 2;
	while (i <= max_y)
	{
		j = (info->player_x / 50) - 1;
		while (j <= max_x)
		{
			if (cube->map->map[i][j] == '2' || ft_strchr("NSWE", cube->map->map[i][j]))
				mlx_put_image_to_window(info->mlx, info->window, info->floor, j * 50, i * 50);
			else if (cube->map->map[i][j] == '1')
				mlx_put_image_to_window(info->mlx, info->window, info->wall, j * 50, i * 50);
			j++;
		}
		i++;
	}
	paint_lines(cube, info);
}

void	paint_player(t_debug *info)
{
	int	i;
	int	j;

	i = info->player_y - 5;
	while (i < info->player_y + 5)
	{
		j = info->player_x - 5;
		while (j < info->player_x + 5)
		{
			mlx_pixel_put(info->mlx, info->window, j, i, 0x00FF00);
			j++;
		}
		i++;
	}
}

void	paint_window(t_cube *cube, t_debug *info)
{
	int	i;
	int	j;

	info->size = 50;
	i = 0;
	info->floor = mlx_xpm_file_to_image(info->mlx, "files/textures/white_square.xpm", &info->size, &info->size);
	info->wall = mlx_xpm_file_to_image(info->mlx, "files/textures/black_square.xpm", &info->size, &info->size);
	while (i <= cube->map->max_y)
	{
		j = 0;
		while (j <= cube->map->max_x)
		{
			if (cube->map->map[i][j] == '1')
				mlx_put_image_to_window(info->mlx, info->window, info->wall, j * 50, i * 50);
			if (cube->map->map[i][j] == '2')
				mlx_put_image_to_window(info->mlx, info->window, info->floor, j * 50, i * 50);
			if (ft_strchr("NSWE", cube->map->map[i][j]))
			{
				mlx_put_image_to_window(info->mlx, info->window, info->floor, j * 50, i * 50);
				paint_player(info);
			}
			j++;
		}
		i++;
	}
}

int	key_control(int keycode, t_cube *cube)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 13)	//Up
	{
		if (cube->map->map[(cube->debug->player_y - 2) / 50][cube->debug->player_x / 50] != '1')
			cube->debug->player_y -= 2;
	}
	if (keycode == 1)	//Down
	{
		if (cube->map->map[(cube->debug->player_y + 2) / 50][cube->debug->player_x / 50] != '1')
			cube->debug->player_y += 2;
	}
	if (keycode == 0)	//Left
	{
		if (cube->map->map[cube->debug->player_y / 50][(cube->debug->player_x - 2) / 50] != '1')
			cube->debug->player_x -= 2;
	}
	if (keycode == 2)	//Right
	{
		if (cube->map->map[cube->debug->player_y / 50][(cube->debug->player_x + 2) / 50] != '1')
			cube->debug->player_x += 2;
	}
	repaintNear(cube, cube->debug);
	paint_player(cube->debug);
	return (0);
}

void	debug_map(t_cube *cube)
{
	t_debug	*info = cube->debug;

	info->player_x = (cube->map->player_x * 50) + 25;
	info->player_y = (cube->map->player_y * 50) + 25;
	info->mlx = mlx_init();
	info->window = mlx_new_window(info->mlx, (cube->map->max_x + 1) * 50, (cube->map->max_y + 1) * 50, "Debuguiando");
	paint_window(cube, info);
	paint_lines(cube, info);
	mlx_hook(info->window, 2, 1L<<0, key_control, cube);
	mlx_loop(info->mlx);
}
