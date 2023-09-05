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

# define ERROR_NUM_ARGS	"Wrong number of arguments"
# define NO_EXTENSION	"The file doesn't have extension"
# define NO_VALID_EXTENSION	"Not a valid extension"
# define INVALID_LINE	"The file is invalid"
# define INVALID_LINE_NUM	"Too much information in one element"
# define NO_NUMBER		"No number specified in RGB element"

void	*error(char *message);
int		error_int(char *message, int returned);

#endif
