/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:34:45 by socana-b          #+#    #+#             */
/*   Updated: 2023/10/22 14:49:50 by rgallego         ###   ########.fr       */
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
# define INVALID_LINE "Invalid information in element: "
# define TO_MUCH_INFO "Too much information in one element"
# define NO_NUMBER "No number specified in RGB element"
# define NOT_VALID_NUM "The number must be between 0 and 255"

/* ********************************** MAP *********************************** */
# define TOO_MUCH_PLAYERS "The map must contain only one player"
# define INVALID_CHAR "The map can't contain other char than '1', '0' or ' '"
# define MAP_SEPARATED "The map can't contain empty lines"
# define MAP_NOT_CLOSED "The map is not closed"

/* ********************************** MLX *********************************** */
# define IMAGE_ERROR "There was an error with the image"

/* ********************************* ERROR ********************************** */
void	error_exit(char *message, int exit_code, t_cube *cube);

#endif
