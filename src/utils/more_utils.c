/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:30:53 by socana-b          #+#    #+#             */
/*   Updated: 2023/11/11 15:28:50 by rgallego         ###   ########.fr       */
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
		return (ft_split(str, ','));
	return (NULL);
}

int	ft_max(int nb1, int nb2)
{
	if (nb1 > nb2)
		return (nb1);
	return (nb2);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
