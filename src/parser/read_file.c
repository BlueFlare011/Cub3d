/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:34:32 by socana-b          #+#    #+#             */
/*   Updated: 2023/11/16 21:12:35 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	get_attribute(char *line, int *bool_array)
{
	int	id;

	id = 0;
	if (!ft_strncmp(line, "C ", 2))
		id = SKY;
	else if (!ft_strncmp(line, "F ", 2))
		id = FLOOR;
	else if (!ft_strncmp(line, "NO ", 3))
		id = NORTH + 2;
	else if (!ft_strncmp(line, "SO ", 3))
		id = SOUTH + 2;
	else if (!ft_strncmp(line, "EA ", 3))
		id = EAST + 2;
	else if (!ft_strncmp(line, "WE ", 3))
		id = WEST + 2;
	else
		return (1);
	if (bool_array[id])
		return (1);
	bool_array[id] = 1;
	return (0);
}

static void	get_color(t_cube *cube, char **rgb, int fd, int type)
{
	unsigned int	id;

	if (len_double_pointer(rgb) != 3)
	{
		close(fd);
		free_double_pointer(&rgb);
		error_exit(TOO_MANY_NUM, SYS_ERR, cube);
	}
	id = FLOOR;
	if (!type)
		id = SKY;
	cube->colour[id] = check_and_get_colour(rgb);
	free_double_pointer(&rgb);
	if (cube->colour[id] < 0)
	{
		close(fd);
		error_exit(NOT_VALID_NUM, SYS_ERR, cube);
	}
}

static void	analyse_line(t_cube *cube, char *line, int *bool_array, int fd)
{
	char	*trimmed_line;

	if (*line == '\0')
		return ;
	if (get_attribute(line, bool_array))
	{
		close(fd);
		error_exit(INVALID_LINE, GENERAL_ERR, cube);
	}
	trimmed_line = ft_strtrim(ft_strchr(line, ' ') + 1, " \t\n\v\f\r");
	if (!trimmed_line)
	{
		close(fd);
		free(line);
		error_exit(strerror(errno), SYS_ERR, cube);
	}
	if (!ft_strncmp(line, "C ", 2) || !ft_strncmp(line, "F ", 2))
		get_color(cube, ft_split(trimmed_line, ','), fd,
			ft_strncmp(line, "C ", 2));
	else
		get_texture(cube, trimmed_line, fd, line);
	free(trimmed_line);
	free(line);
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
		if (check_bool_array(bool_array))
			line = process_line(cube, fd);
	}
	free(bool_array);
	get_map(cube, fd);
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
