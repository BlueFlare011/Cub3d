/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:57:53 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/16 21:04:52 by rgallego         ###   ########.fr       */
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
int		is_rgb(char *rgb);
char	*process_line(t_cube *cube, int fd);
void	free_cube(t_cube *cube);
int		check_bool_array(int *bool_array);
int		close_window_x(t_cube *cube);
char	**split_simple_comas(char *str);
int		ft_max(int nb1, int nb2);
int		ft_min(int a, int b);

#endif
