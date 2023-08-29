#ifndef CUBE_H
#define CUBE_H
#include <math.h>
#include <string.h>
// # include <mlx.h>
#include "errors.h"
#include "get_next_line.h"

enum
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3,
	FLOOR = 4,
	CEILING = 5,
};

typedef struct
{
	int id;
	int fd_texture;
} t_texture;

typedef struct
{
	int id;
	int red;
	int green;
	int blue;
} t_color;

typedef struct
{
	char **map;
	t_color *color;
	t_texture *texture;
} t_info;

/************** PARSER ***************/
t_info *extract_file_info(char *file);

/************** UTILS ****************/
void 	delete_meta_spaces(char *str);
int 	create_struct(t_info *info);
void	 free_double_pointer(char **matrix);
int 	len_double_pointer(char **matrix);
int 	is_num(char **rgb);
char	*trim_line(char *line);
void	print_info(t_info *info);
void	delete_struct(t_info *info);

#endif