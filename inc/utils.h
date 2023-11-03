/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blueflare011 <blueflare011@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:57:53 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/02 17:03:15 by blueflare01      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"
# include "cube.h"
# include "errors.h"

void	init_cube(t_cube *cube);
void	free_double_pointer(char ***matrix);
int		len_double_pointer(char **matrix);
int		is_num(char **rgb);
char	*process_line(t_cube *cube, int fd);
void	free_cube(t_cube *cube);
int		check_bool_array(int *bool_array);
int		close_window_x(t_cube *cube);
char	**split_simple_comas(char *str);
#endif
