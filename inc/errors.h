/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:34:45 by socana-b          #+#    #+#             */
/*   Updated: 2023/09/05 17:36:08 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <stdio.h>
# include <errno.h>
# include "libft.h"

/******************** FILENAME *************************/
# define ERROR_NUM_ARGS	"Wrong number of arguments"
# define NO_EXTENSION	"The file doesn't have extension"
# define NO_VALID_EXTENSION	"Not a valid extension"

/******************** ELEMENTS *************************/
# define INVALID_LINE	"Invalid information in element: "
# define TO_MUCH_INFO	"Too much information in one element"
# define NO_NUMBER		"No number specified in RGB element"
# define NOT_VALID_NUM	"The number must be between 0 and 255"

/********************** MAP ****************************/
# define MAP_SEPARATED	"The map can't contain empty lines"
# define MAP_NOT_CLOSED	"The map is not closed"

#endif
