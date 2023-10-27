#include "events.h"

int check_bool_array(int *bool_array)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (bool_array[i] == 0)
			return (1);
		i++;
	}
	return (0);
}

int	close_window_x(t_cube *cube)
{
	free_cube(cube);
	exit(0);
}