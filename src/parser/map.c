/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:49:32 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/24 18:03:19 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	settle_player(t_cube *cube, int *num_player, int i, int j)
{
	(*num_player)++;
	cube->map.player_x = (double)j + 0.5;
	cube->map.player_y = (double)i + 0.5;
	if (cube->map.map[i][j] == 'N')
	{
		cube->map.dir_x = N_X;
		cube->map.dir_y = N_Y;
	}
	else if (cube->map.map[i][j] == 'E')
	{
		cube->map.dir_x = E_X;
		cube->map.dir_y = E_Y;
	}
	else if (cube->map.map[i][j] == 'S')
	{
		cube->map.dir_x = S_X;
		cube->map.dir_y = S_Y;
	}
	else if (cube->map.map[i][j] == 'W')
	{
		cube->map.dir_x = W_X;
		cube->map.dir_y = W_Y;
	}
}

static void	check_chars(t_cube *cube, int num_player, int i, int j)
{
	while (cube->map.map[i] && (!i || !cube->map.map[i - 1][j]))
	{
		j = 0;
		while (cube->map.map[i][j]
			&& ft_strchr("NESW10 ", cube->map.map[i][j]) && num_player <= 1)
		{
			if (ft_strchr("NESW", cube->map.map[i][j]))
				settle_player(cube, &num_player, i, j);
			if (ft_strchr("NESW10 ", cube->map.map[i][j]))
				j++;
		}
		if (!cube->map.map[i][j] && j > cube->map.max_x)
			cube->map.max_x = j - 1;
		if (!cube->map.map[i][j])
			i++;
	}
	if (num_player != 1)
		error_exit(TOO_MUCH_PLAYERS, GENERAL_ERR, cube);
	else if (cube->map.map[i])
		error_exit(INVALID_CHAR, GENERAL_ERR, cube);
	cube->map.max_y = i - 1;
}

// void	get_map(t_cube *cube, char *line, int fd)
// {
// 	char	*super_string;
// 	char	*aux;

// 	aux = line;
// 	line = get_next_line(fd);
// 	while (line && *line == '\n')
// 	{
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	if (line)
// 		super_string = ft_strjoin(aux, line);
// 	while (line && super_string && *line != '\n')
// 	{
// 		free(line);
// 		free(aux);
// 		aux = super_string;
// 		line = get_next_line(fd);
// 		if (line)
// 			super_string = ft_strjoin(aux, line);
// 	}
// 	if (super_string)
// 		cube->map.map = ft_split(super_string, '\n');
// 	if (line)
// 		error_exit(MAP_SEPARATED, GENERAL_ERR, cube);
// 	close(fd);
// 	if (super_string)
// 		free(super_string);
// 	if (!cube->map.map || !super_string)
// 		error_exit(strerror(errno), SYS_ERR, cube);
// }

static char	*read_true_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && *line == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

void	get_map(t_cube *cube, char *line, int fd)
{
	char	*super_string;
	char	*aux;

	super_string = line;
	line = read_true_line(fd);
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
	close(fd);
	cube->map.player_x = 0;
	cube->map.player_y = 0;
	check_chars(cube, 0, 0, 0);
	floodfill(cube);
}
