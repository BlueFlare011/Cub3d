/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blueflare011 <blueflare011@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:34:41 by socana-b          #+#    #+#             */
/*   Updated: 2023/09/18 17:53:55 by blueflare01      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include <math.h>
# include "mlx.h"
# include "stack.h"
# include "get_next_line.h"
# include "errors.h"

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

typedef struct s_cube
{
	t_map		*map;
	t_color		*color;
	t_texture	*texture;
}	t_cube;

/************** PARSER ***************/
t_cube	*extract_file_info(char *file);
void	valid_map(t_cube *map);
void	floodfill(t_cube *cube);

/************** DEBUG ****************/
void	debug_map(t_cube *cube);

/************** UTILS ****************/
void	create_struct(t_cube *cube);
void	free_double_pointer(char **matrix);
int		len_double_pointer(char **matrix);
int		is_num(char **rgb);
char	*process_line(int fd);
void	print_cube(t_cube *cube);
void	delete_struct(t_cube *cube);

#endif
