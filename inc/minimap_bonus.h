/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:20:21 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/11 14:20:37 by rgallego         ###   ########.fr       */
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

# define WALL_COLOUR 0x45B0B0B0
# define FLOOR_COLOUR 0x45000000
# define PLAYER_COLOUR 0x4500FF00
# define BORDER_COLOUR 0x45505050

void	print_minimap(t_cube *cube);

#endif
