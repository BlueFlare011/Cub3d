/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:49:32 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/24 23:10:40 by rgallego         ###   ########.fr       */
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
	while (cube->map.map[i])
	{
		j = 0;
		while (cube->map.map[i][j])
		{
			if (ft_strchr("NESW", cube->map.map[i][j]))
				settle_player(cube, &num_player, i, j);
			if (!ft_strchr("NESW10 ", cube->map.map[i][j]))
				break;
			j++;
		}
		if (!cube->map.map[i][j] && j > cube->map.max_x)
			cube->map.max_x = j - 1;
		if (!ft_strchr("NESW10 ", cube->map.map[i][j]))
			break;
		i++;
	}
	if (cube->map.map[i] && cube->map.map[i][j])
		error_exit(INVALID_CHAR, GENERAL_ERR, cube);
	else if (num_player != 1)
		error_exit(TOO_MUCH_PLAYERS, GENERAL_ERR, cube);
	cube->map.max_y = i - 1;
}

static char	*read_true_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (!ft_strchr(line, '1') && !ft_strncmp(line, "\n", 2))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!ft_strchr(line, '1'))
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static void	read_map(t_cube *cube, char **super_string, char *line, int fd)
{
	char	*aux;

	aux = line;
	while (line && *line != '\n' && aux)
	{
		aux = ft_strjoin(*super_string, line);
		if (aux)
		{
			free(line);
			free(*super_string);
			*super_string = aux;
			line = get_next_line(fd);
		}
	}
	if (line)
	{
		free(line);
		error_exit(MAP_SEPARATED, GENERAL_ERR, cube);
	}
	if (!aux)
		error_exit(strerror(errno), SYS_ERR, cube);
}

void	get_map(t_cube *cube, int fd)
{
	char	*super_string;
	char	*line;

	line = read_true_line(fd);
	if (!line)
		error_exit(INVALID_LINE, GENERAL_ERR, cube);
	read_map(cube, &super_string, line, fd);
	cube->map.map = ft_split(super_string, '\n');
	free(super_string);
	close(fd);
	if (!cube->map.map)
		error_exit(strerror(errno), SYS_ERR, cube);
	cube->map.player_x = 0;
	cube->map.player_y = 0;
	check_chars(cube, 0, 0, 0);
	floodfill(cube);
}
