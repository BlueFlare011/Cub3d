#ifndef BONUS_H
# define BONUS_H

# include "cube.h"
# include "errors.h"
# include "mlx_management.h"
# include "utils.h"

# define MINIMAP_SIZE 180
# define CUBE_SIZE 20

# define WALL_COLOUR 0xB0B0B0
# define FLOOR_COLOUR 0x000000
# define PLAYER_COLOUR 0x00FF00

void	print_minimap(t_cube *cube);

#endif
