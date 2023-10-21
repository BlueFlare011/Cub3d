/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:48:57 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/21 14:47:31 by rgallego         ###   ########.fr       */
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
void	valid_map(t_cube *map);
void	floodfill(t_cube *cube);
void	read_texture(t_cube cube, char *file_name, t_texture *texture);
int		check_and_get_colour(int t, int r, int g, int b);

# endif
