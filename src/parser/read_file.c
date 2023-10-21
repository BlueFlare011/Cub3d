/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:34:32 by socana-b          #+#    #+#             */
/*   Updated: 2023/10/21 18:06:23 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	get_texture(t_cube *cube, char **data)
{
	char	*aux;
	int		id;

	if (!ft_strncmp(data[0], "NO", 3))
		id = NORTH;
	else if (!ft_strncmp(data[0], "SO", 3))
		id = SOUTH;
	else if (!ft_strncmp(data[0], "EA", 3))
		id = EAST;
	else if (!ft_strncmp(data[0], "WE", 3))
		id = WEST;
	else
		return (1);
	aux = ft_strtrim(data[1], "\n");
	if (!aux)
		error_exit(strerror(errno), SYS_ERR, cube);
	read_texture(*cube, aux, &(cube->texture[id]));
	free(aux);
	return (0);
}

int	get_color(t_cube *cube, char **data)
{
	char			**rgb;
	unsigned int	id;

	if (ft_strncmp(data[0], "C", 2) && ft_strncmp(data[0], "F", 2))
		return (1);
	rgb = ft_split(data[1], ',');
	if (!rgb)
		error_exit(strerror(errno), SYS_ERR, cube);
	id = 0;
	if (!ft_strncmp(data[0], "C", 2))
		id = SKY;
	else if (!ft_strncmp(data[0], "F", 2))
		id = FLOOR;
	if (!is_num(rgb))
		error_exit(NO_NUMBER, SYS_ERR, cube);
	cube->colour[id] = check_and_get_colour(0, ft_atoi(rgb[RED]),
			ft_atoi(rgb[GREEN]), ft_atoi(rgb[BLUE]));
	if (cube->colour[id] < 0)
		error_exit(NOT_VALID_NUM, SYS_ERR, cube);
	free_double_pointer(&rgb);
	return (0);
}

void	get_map(t_cube *cube, char *line, int fd)
{
	char	*super_string;
	char	*aux;

	super_string = line;
	line = get_next_line(fd);
	while (line && *line == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line && *line != '\n')
	{
		aux = ft_strjoin(super_string, line); // revisar
		free(line);
		free(super_string);
		super_string = aux;
		line = get_next_line(fd);
	}
	if (line)
		error_exit(MAP_SEPARATED, GENERAL_ERR, cube);
	else
		cube->map.map = ft_split(super_string, '\n');
	if (!cube->map.map)
		error_exit(strerror(errno), SYS_ERR, cube);
	free(super_string);
}

static int	analyse_line(t_cube *cube, char *line, int status, int fd)
{
	char	**data;

	if (*line == '\0')
		return (status);
	data = ft_split(line, ' ');
	if (!data)
		error_exit(strerror(errno), SYS_ERR, cube);
	if (len_double_pointer(data) != 2)
	{
		close(fd);
		free_double_pointer(&data);
		error_exit(TO_MUCH_INFO, GENERAL_ERR, cube);
	}
	if (!get_texture(cube, data) || !get_color(cube, data))
		status++;
	else
	{
		close(fd);
		free_double_pointer(&data);
		error_exit(INVALID_LINE, GENERAL_ERR, cube);
	}
	free_double_pointer(&data);
	return (status);
}

void	extract_file_info(t_cube *cube, char *file)
{
	char	*line;
	int		limit;
	int		fd;

	ft_mlx_init(cube);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit(strerror(errno), SYS_ERR, NULL);
	limit = 0;
	line = process_line(cube, fd);
	while (line && limit < 6)
	{
		limit = analyse_line(cube, line, limit, fd);
		free(line);
		line = process_line(cube, fd);
	}
	get_map(cube, line, fd);
	close(fd);
	valid_map(cube);
}
