/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:34:41 by socana-b          #+#    #+#             */
/*   Updated: 2023/10/13 23:33:11 by rgallego         ###   ########.fr       */
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
# define CUBE_SIZE 64
# define MVMNT_SPEED 1
# define X 0
# define Y 1
# define PLANE_X 0.0
# define PLANE_Y 0.66

# define WHITE 0x00FFFFFF
# define GREEN 0x0000FF00
# define BLACK 0x00000000
/* ***************** DIR VECTORS***************** */
# define N_X 0
# define N_Y -1
# define E_X 1
# define E_Y 0
# define S_X 0
# define S_Y 1
# define W_X -1
# define W_Y 0

enum
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3,
	FLOOR = 4,
	CEILING = 5,
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
	int	id;
	int	fd_texture;
}	t_texture;

typedef struct s_color
{
	int	id;
	int	red;
	int	green;
	int	blue;
}	t_color;

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

typedef struct s_cube
{
	t_map		*map;
	t_color		*color;
	t_texture	*texture;
	t_mlx		*mlx;
}	t_cube;

/************** PARSER ***************/
t_cube	*extract_file_info(char *file);
void	valid_map(t_cube *map);
void	floodfill(t_cube *cube);

/************** DEBUG ****************/
void	raycasting(t_cube *cube);

/************** RAYCASTING_UTILS ****************/
void	move_player(t_cube cube, int axis, int mvment_ratio);

/*********** MLX_MNGMENT **************/
void	ft_mlx_init(t_cube *cube);
void	my_pixel_put(t_img img, int x, int y, int colour);
int		key_control(int keycode, t_cube *cube);
void	paint_ray(t_cube cube, int x, int start, int end);

/************** UTILS ****************/
void	create_struct(t_cube *cube);
void	free_double_pointer(char **matrix);
int		len_double_pointer(char **matrix);
int		is_num(char **rgb);
char	*process_line(int fd);
void	print_cube(t_cube *cube);
void	delete_struct(t_cube *cube);

#endif
