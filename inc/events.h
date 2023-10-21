/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:39:55 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/21 18:04:34 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include <math.h>
# include <stdlib.h>
# include "mlx.h"
# include "cube.h"
# include "utils.h"
# include "raycasting.h"
# include "keys.h"

# define SPEED 0.025
# define ALPHA (M_PI / 64)

int		key_down(int keycode, t_cube *cube);
int		key_release(int keycode, t_cube *cube);
int		event_management(t_cube *cube);

# endif
