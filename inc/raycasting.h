/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blueflare011 <blueflare011@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:23:56 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/02 17:33:44 by blueflare01      ###   ########.fr       */
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
void	paint_ray(t_cube cube, int x);

#endif
