#ifndef CUBE_H
# define CUBE_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"

enum{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3,
	FLOOR = 4,
	CEILING = 5,
};

typedef struct {
	int		id;
	char	*path;
}t_texture;

typedef struct {
	int		id;
	int		red;
	int		green;
	int		blue;
}t_color;

typedef struct
{
	char		**map;
	t_color		*color;
	t_texture	*texture;
}t_info;



/************** PARSER ***************/
t_info	*extract_file_info(char *file);

/************** UTILS ***************/
void	delete_meta_spaces(char *str);
int		create_struct(t_info *info);
void	free_double_pointer(void **matrix);

#endif