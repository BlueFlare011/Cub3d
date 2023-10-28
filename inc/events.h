/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:39:55 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/28 09:58:08 by socana-b         ###   ########.fr       */
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

# define SPEED 0.050
# define ALPHA_RATIO 64

int		key_down(int keycode, t_cube *cube);
int		key_release(int keycode, t_cube *cube);
int		event_management(t_cube *cube);

#endif
