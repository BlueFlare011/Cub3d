/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:34:28 by socana-b          #+#    #+#             */
/*   Updated: 2023/09/05 17:34:29 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	*error(char *message)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	return (NULL);
}

int		error_int(char *message, int returned)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	return (returned);
}

void	error_exit(char *message, t_info *info)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	delete_struct(info);

	exit (1);
}