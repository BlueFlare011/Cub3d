/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blueflare011 <blueflare011@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:48:57 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/28 22:04:47 by blueflare01      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>
# include "libft.h"
# include "cube.h"
# include "stack.h"
# include "errors.h"
# include "utils.h"
# include "mlx_management.h"
# include "get_next_line.h"

# define RED 0
# define GREEN 1
# define BLUE 2

# define OFFSET 2

/* ***************** DIR VECTORS***************** */
# define N_X 0.0
# define N_Y -1.0
# define E_X 1.0
# define E_Y 0.0
# define S_X 0.0
# define S_Y 1.0
# define W_X -1.0
# define W_Y 0.0

void	extract_file_info(t_cube *cube, char *file);
void	get_map(t_cube *cube	, int fd);
//void	floodfill(t_cube *cube);
void	get_texture(t_cube *cube, char *trimmed_line, int id, int fd);
void	check_arguments(int num, char **args);
int		check_and_get_colour(char **rgb);
void	shitty_check(t_cube *cube);

#endif
