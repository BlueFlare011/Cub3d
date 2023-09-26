#include "cube.h"


int	key_control(int keycode, t_cube *cube)
{
	if (keycode == KEY_ESC)
		exit(1);
	if (keycode == KEY_W)
	{
		if (cube->map->map[(cube->mlx->player_y - 2) / 50][cube->mlx->player_x / 50] != '1')
			cube->mlx->player_y -= 2;
	}
	else if (keycode == KEY_S)
	{
		if (cube->map->map[(cube->mlx->player_y + 2) / 50][cube->mlx->player_x / 50] != '1')
			cube->mlx->player_y += 2;
	}
	else if (keycode == KEY_A)
	{
		if (cube->map->map[cube->mlx->player_y / 50][(cube->mlx->player_x - 2) / 50] != '1')
			cube->mlx->player_x -= 2;
	}
	else if (keycode == KEY_D)
	{
		if (cube->map->map[cube->mlx->player_y / 50][(cube->mlx->player_x + 2) / 50] != '1')
			cube->mlx->player_x += 2;
	}
	return (0);
}

void	debug_map(t_cube *cube)
{
	cube->mlx->player_x = (cube->map->player_x * 50) + 25;
	cube->mlx->player_y = (cube->map->player_y * 50) + 25;
	
	cube->mlx->mlx = mlx_init();
	cube->mlx->win = mlx_new_window(cube->mlx->mlx,
		(cube->map->max_x + 1) * 50, (cube->map->max_y + 1) * 50, "cub3d");
	cube->mlx->img = mlx_new_image(cube->mlx->mlx, (cube->map->max_x + 1) * 50,
		(cube->map->max_y + 1) * 50);
	cube->mlx->img->addr = mlx_get_data_addr(cube->mlx->img->img,
		&cube->mlx->img->bpp, &cube->mlx->img->line_len,
		&cube->mlx->img->endian);
	mlx_hook(cube->mlx->win, ON_KEYDOWN, MASK, key_control, cube);
	mlx_loop(cube->mlx->mlx);
}
