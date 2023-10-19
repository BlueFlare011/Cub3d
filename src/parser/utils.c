/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:47:26 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/19 18:52:51 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	set_keys(t_cube *cube)
{
	cube->keys.a = 0;
	cube->keys.w = 0;
	cube->keys.s = 0;
	cube->keys.d = 0;
	cube->keys.left = 0;
	cube->keys.right = 0;
	return (0);
}
