/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blueflare011 <blueflare011@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:34:45 by socana-b          #+#    #+#             */
/*   Updated: 2023/11/25 13:33:55 by blueflare01      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <stdio.h>
# include <string.h>
# include <errno.h>
# include "libft.h"
# include "mlx.h"
# include "cube.h"

/* ******************************* ERROR CODES ****************************** */
# define GENERAL_ERR 1
# define SYS_ERR -1

/* ******************************** FILENAME ******************************** */
# define ERROR_NUM_ARGS "Wrong number of arguments"
# define NO_EXTENSION "The file doesn't have extension"
# define NO_VALID_EXTENSION "Not a valid extension"

/* ******************************** ELEMENTS ******************************** */
# define INVALID_ELEMENT "Invalid element in file"
# define INVALID_TEXTURE "Invalid texture element"
# define INVALID_COLOR "Invalid color element"

/* ********************************** MAP *********************************** */
# define TOO_MUCH_PLAYERS "The map must contain only one player"
# define INVALID_CHAR "The map can't contain other char than '1', '0' or ' '"
# define MAP_NOT_CLOSED "The map is not closed"

/* ********************************** MLX *********************************** */
# define IMAGE_ERROR "There was an error with the image"

/* ********************************* ERROR ********************************** */
void	error_exit(char *message, int exit_code, t_cube *cube);

#endif
