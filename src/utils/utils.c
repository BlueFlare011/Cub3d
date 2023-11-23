/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:34:18 by socana-b          #+#    #+#             */
/*   Updated: 2023/11/23 20:54:43 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	len_double_pointer(char **matrix)
{
	int	i;

	if (!matrix)
		return (0);
	i = 0;
	while (matrix && matrix[i])
		i++;
	return (i);
}

void	free_double_pointer(char ***matrix)
{
	int	i;

	if (!*matrix)
		return ;
	i = 0;
	while ((*matrix)[i])
	{
		free((*matrix)[i]);
		i++;
	}
	if (*matrix)
		free(*matrix);
	*matrix = NULL;
}

void	init_cube(t_cube *cube)
{
	int	i;

	cube->map.map = NULL;
	cube->mlx.mlx = NULL;
	cube->mlx.win = NULL;
	cube->mlx.img.img = NULL;
	cube->mlx.img.addr = NULL;
	i = 0;
	while (i < 4)
	{
		cube->texture[i].img = NULL;
		i++;
	}
	cube->keys.a = 0;
	cube->keys.w = 0;
	cube->keys.s = 0;
	cube->keys.d = 0;
	cube->keys.left = 0;
	cube->keys.right = 0;
}

int	is_rgb(char *rgb)
{
	int	i;
	int	j;

	i = 0;
	while (rgb[i] && ft_strchr(" \t\n\v\f\r", rgb[i]))
		i++;
	if (rgb[i] == '+')
		i++;
	j = 0;
	while (rgb[i + j] && ft_isdigit(rgb[i + j]))
		j++;
	if (!j || j > 3)
		return (1);
	while (rgb[i + j] && ft_strchr(" \t\n\v\f\r", rgb[i]))
		i++;
	if (rgb[i + j])
		return (1);
	return (0);
}

char	*process_line(t_cube *cube, int fd)
{
	char			*line;
	char			*result;
	unsigned int	i;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	i = 0;
	while (line[i])
	{
		if (ft_strchr("\t\f\v\r", line[i]))
			line[i] = ' ';
		i++;
	}
	result = ft_strtrim(line, "\n");
	free(line);
	if (!result)
	{
		close(fd);
		error_exit(strerror(errno), SYS_ERR, cube);
	}
	return (result);
}
