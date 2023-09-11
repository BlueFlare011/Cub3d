/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:34:41 by socana-b          #+#    #+#             */
/*   Updated: 2023/09/12 00:02:44 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include <math.h>
// # include <mlx.h>
# include "bfs_stack.h"
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

typedef struct s_cube
{
	char		**map;
	t_color		*color;
	t_texture	*texture;
}	t_cube;

/************** PARSER ***************/
t_cube	*extract_file_info(char *file);
void	valid_map(t_cube *map);

/************** UTILS ****************/
void	create_struct(t_cube *cube);
void	free_double_pointer(char **matrix);
int		len_double_pointer(char **matrix);
int		is_num(char **rgb);
char	*process_line(int fd);
void	print_cube(t_cube *cube);
void	delete_struct(t_cube *cube);

#endif
