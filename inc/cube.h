/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:34:41 by socana-b          #+#    #+#             */
/*   Updated: 2023/10/19 18:51:54 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include <math.h>
# include <limits.h>
# include "mlx.h"
# include "stack.h"
# include "get_next_line.h"
# include "errors.h"
# include "keys.h"

# define WIN_X 1080
# define WIN_Y 720
# define SPEED 0.125
# define X 0
# define Y 1
# define FOV 0.66
# define RED 0
# define GREEN 1
# define BLUE 2

# define WHITE 0x00FFFFFF
# define COLOR 0x0000FF00
# define BLACK 0x00000000
/* ***************** DIR VECTORS***************** */
# define N_X 0.0
# define N_Y -1.0
# define E_X 1.0
# define E_Y 0.0
# define S_X 0.0
# define S_Y 1.0
# define W_X -1.0
# define W_Y 0.0
# define ALPHA (M_PI / 8)

enum e_direction
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3,
};

enum e_color
{
	FLOOR = 0,
	SKY = 1,
};

typedef struct s_raycast
{
	double	camera;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_x;
	double	delta_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	int		collided_side;
}	t_raycast;

typedef struct s_texture
{
	int	width;
	int	height;
	char **img;
}	t_texture;

typedef struct s_map
{
	char	**map;
	int		max_x;
	int		max_y;
	double	player_x;
	double	player_y;
	double	dir_x;
	double	dir_y;
}	t_map;

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	*img;
	void	*floor;
	void	*wall;
	int		size;
}	t_mlx;

typedef struct s_keys
{
	int	a;
	int	w;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_keys;

typedef struct s_cube
{
	t_map		*map;
	t_mlx		*mlx;
	int			colour[2];
	t_texture	texture[4];
	t_keys		keys;
}	t_cube;

/************** PARSER ***************/
t_cube	*extract_file_info(char *file);
void	valid_map(t_cube *map);
void	floodfill(t_cube *cube);
int		set_keys(t_cube *cube);

/************** DEBUG ****************/
void	raycasting(t_cube *cube);

/************** RAYCASTING_UTILS ****************/
void	move(t_cube cube, double move_x, double move_y);
void	rotation(t_cube cube, double alpha);

/*********** MLX_MNGMENT **************/
void	ft_mlx_init(t_cube *cube);
void	my_pixel_put(t_img img, int x, int y, int colour);
int		key_down(int keycode, t_cube *cube);
int		key_release(int keycode, t_cube *cube);
int		event_management(t_cube *cube);
void	paint_ray(t_cube cube, t_raycast raycast, int x, int start, int end);

/************** UTILS ****************/
void	create_struct(t_cube *cube);
void	free_double_pointer(char **matrix);
int		len_double_pointer(char **matrix);
int		is_num(char **rgb);
char	*process_line(int fd);
// void	print_cube(t_cube *cube);
void	delete_struct(t_cube *cube);

int		check_and_get_colour(int t, int r, int g, int b);
void	read_texture(t_cube cube, char *file_name, t_texture *texture);

#endif
