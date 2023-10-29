/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:34:32 by socana-b          #+#    #+#             */
/*   Updated: 2023/10/29 16:14:46 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	get_attribute(char **data, int *bool_array)
{
	int	id;

	id = 0;
	if (!ft_strncmp(data[0], "C", 2))
		id = SKY;
	else if (!ft_strncmp(data[0], "F", 2))
		id = FLOOR;
	else if (!ft_strncmp(data[0], "NO", 3))
		id = NORTH + 2;
	else if (!ft_strncmp(data[0], "SO", 3))
		id = SOUTH + 2;
	else if (!ft_strncmp(data[0], "EA", 3))
		id = EAST + 2;
	else if (!ft_strncmp(data[0], "WE", 3))
		id = WEST + 2;
	else
		return (1);
	if (bool_array[id] == 1)
		return (1);
	bool_array[id] = 1;
	return (0);
}

static void	get_color(t_cube *cube, char **data, int fd)
{
	char			**rgb;
	unsigned int	id;

	if (ft_strncmp(data[0], "C", 2) && ft_strncmp(data[0], "F", 2))
		return ;
	rgb = ft_split(data[1], ',');
	if (!rgb)
		error_exit(strerror(errno), SYS_ERR, cube);
	if (len_double_pointer(rgb) != 3)
		error_exit(TOO_MANY_NUM, SYS_ERR, cube);
	id = 0;
	id = FLOOR;
	if (!ft_strncmp(data[0], "C", 2))
		id = SKY;
	if (!is_num(rgb))
		error_exit(NO_NUMBER, SYS_ERR, cube);
	cube->colour[id] = check_and_get_colour(0, ft_atoi(rgb[RED]),
			ft_atoi(rgb[GREEN]), ft_atoi(rgb[BLUE]));
	if (cube->colour[id] < 0)
	{
		close(fd);
		free_double_pointer(&data);
		error_exit(NOT_VALID_NUM, SYS_ERR, cube);
	}
	free_double_pointer(&rgb);
}

static void	analyse_line(t_cube *cube, char *line, int *bool_array, int fd)
{
	char	**data;

	if (*line == '\0')
		return ;
	data = ft_split(line, ' ');
	if (!data)
		error_exit(strerror(errno), SYS_ERR, cube);
	if (len_double_pointer(data) != 2)
	{
		close(fd);
		free_double_pointer(&data);
		error_exit(TO_MUCH_INFO, GENERAL_ERR, cube);
	}
	if (!get_attribute(data, bool_array))
	{
		get_texture(cube, data, fd);
		get_color(cube, data, fd);
	}
	else
	{
		close(fd);
		free_double_pointer(&data);
		error_exit(INVALID_LINE, GENERAL_ERR, cube);
	}
	free_double_pointer(&data);
}

void	extract_file_info(t_cube *cube, char *file)
{
	char	*line;
	int		*bool_array;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit(strerror(errno), SYS_ERR, NULL);
	bool_array = malloc(sizeof(int) * 6);
	if (!bool_array)
	{
		close(fd);
		error_exit(strerror(errno), SYS_ERR, cube);
	}
	ft_bzero(bool_array, sizeof(int) * 6);
	ft_mlx_init(cube);
	line = process_line(cube, fd);
	while (line && check_bool_array(bool_array))
	{
		analyse_line(cube, line, bool_array, fd);
		free(line);
		line = process_line(cube, fd);
	}
	free(bool_array);
	get_map(cube, line, fd);
}

void	check_arguments(int num, char **args)
{
	char	*extension;

	if (num != 2)
		error_exit(ERROR_NUM_ARGS, GENERAL_ERR, NULL);
	extension = ft_strrchr(args[1], '.');
	if (!extension)
		error_exit(NO_EXTENSION, GENERAL_ERR, NULL);
	if (ft_strncmp(extension, ".cub", 4))
		error_exit(NO_VALID_EXTENSION, GENERAL_ERR, NULL);
}
