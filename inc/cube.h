/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:34:41 by socana-b          #+#    #+#             */
/*   Updated: 2023/09/05 17:38:34 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include <math.h>
# include <string.h>
// # include <mlx.h>
# include "errors.h"
# include "get_next_line.h"

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

typedef struct s_info
{
	char		**map;
	t_color		*color;
	t_texture	*texture;
}t_info;

/************** PARSER ***************/
t_info	*extract_file_info(char *file);
void	valid_map(t_info *map);

/************** UTILS ****************/
void	delete_meta_spaces(char *str);
int		create_struct(t_info *info);
void	free_double_pointer(char **matrix);
int		len_double_pointer(char **matrix);
int		is_num(char **rgb);
char	*trim_line(char *line);
void	print_info(t_info *info);
void	delete_struct(t_info *info);

/*************** ERROR ****************/
void	*error(char *message);
int		error_int(char *message, int returned);
void	error_exit(char *message, t_info *info);

#endif