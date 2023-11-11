/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:20:21 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/11 15:54:18 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_BONUS_H
# define MINIMAP_BONUS_H

# include <math.h>
# include "cube.h"
# include "errors.h"
# include "mlx_management.h"
# include "utils.h"

# define MINIMAP_SIZE 4
# define CELL_SIZE 20
# define PLAYER_SIZE 2
# define PERSP_SIZE 1

# define WALL_COLOUR 0xB0B0B0
# define FLOOR_COLOUR 0x000000
# define PLAYER_COLOUR 0x00FF00
# define BORDER_COLOUR 0x505050
# define PERSP_COLOUR 0x3BA8F9

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_bresen
{
	int		variation;
	t_point	step;
	t_point	d;
}	t_bresen;

void	print_minimap(t_cube *cube);
void	prepare_bresenham(t_cube *cube, double x, double y);

#endif
