/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:30:53 by socana-b          #+#    #+#             */
/*   Updated: 2023/10/28 11:31:34 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int	check_bool_array(int *bool_array)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (bool_array[i] == 0)
			return (1);
		i++;
	}
	return (0);
}

int	close_window_x(t_cube *cube)
{
	free_cube(cube);
	exit(0);
}
