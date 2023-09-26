/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:34:41 by socana-b          #+#    #+#             */
/*   Updated: 2023/09/26 11:06:21 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include <math.h>
# include "mlx.h"
# include "stack.h"
# include "get_next_line.h"
# include "errors.h"
# include "keys.h"

enum
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3,
	FLOOR = 4,
	CEILING = 5,
};

typedef struct s_texture
{
	int	id;
	int	fd_texture;
}t_texture;

typedef struct s_color
{
	int	id;
	int	red;
	int	green;
	int	blue;
}t_color;

typedef struct s_map
{
	char	**map;
	int		max_x;
	int		max_y;
	int		player_x;
	int		player_y;
	}t_map;

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
	int		player_x;
	int		player_y;
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
void	debug_map(t_cube *cube);

/*********** MLX_MNGMENT **************/
void	ft_mlx_init(t_cube *cube);
void	my_pixel_put(t_img img, int x, int y, int colour);

/************** UTILS ****************/
void	create_struct(t_cube *cube);
void	free_double_pointer(char **matrix);
int		len_double_pointer(char **matrix);
int		is_num(char **rgb);
char	*process_line(int fd);
void	print_cube(t_cube *cube);
void	delete_struct(t_cube *cube);

#endif
