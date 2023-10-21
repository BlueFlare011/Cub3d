/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:23:56 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/21 14:56:42 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <math.h>
# include <stdlib.h>
# include "mlx.h"
# include "cube.h"
# include "events.h"
# include "mlx_management.h"

# define WIN_X 1080
# define WIN_Y 720

# define X 0
# define Y 1
# define FOV 0.66

# define EPSILON 0.0000000001

void	raycasting(t_cube *cube);
int		check_and_get_colour(int t, int r, int g, int b);
void	paint_ray(t_cube cube, t_raycast raycast, int x);

#endif
