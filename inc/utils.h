/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:57:53 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/21 17:59:39 by rgallego         ###   ########.fr       */
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

#endif
