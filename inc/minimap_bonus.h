#ifndef BONUS_H
# define BONUS_H

# include <math.h>
# include "cube.h"
# include "errors.h"
# include "mlx_management.h"
# include "utils.h"

# define MINIMAP_SIZE 180
# define CUBE_SIZE 20

# define WALL_COLOUR 0x45B0B0B0
# define FLOOR_COLOUR 0x45000000
# define PLAYER_COLOUR 0x4500FF00
# define BORDER_COLOUR 0x45505050

void	print_minimap(t_cube *cube);

#endif
