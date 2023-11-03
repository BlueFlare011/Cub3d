/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blueflare011 <blueflare011@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:30:53 by socana-b          #+#    #+#             */
/*   Updated: 2023/11/02 17:05:12 by blueflare01      ###   ########.fr       */
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

char	**split_simple_comas(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count == 2)
		return(ft_split(str, ','));
	return (NULL);
}
