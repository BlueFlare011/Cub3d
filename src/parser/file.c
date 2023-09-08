/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:34:32 by socana-b          #+#    #+#             */
/*   Updated: 2023/09/05 17:54:15 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	get_texture_aux(t_info *info, char **data, int id)
{
	char	*aux;

	aux = ft_strtrim(data[1], "\n");
	if (!aux)
		error_exit(strerror(errno), info);
	info->texture[id].id = id;
	info->texture[id].fd_texture = open(aux, O_RDONLY);
	if (info->texture[id].fd_texture < 0)
	{
		free(aux);
		error_exit(strerror(errno), info); // Mensajito customizado
	}
	free(aux);
	return (0);
}

int	get_texture(t_info *info, char **data)
{
	if (!ft_strncmp(data[0], "NO", 3))
		return(get_texture_aux(info, data, NORTH));
	if (!ft_strncmp(data[0], "SO", 3))
		return(get_texture_aux(info, data, SOUTH));
	if (!ft_strncmp(data[0], "EA", 3))
		return(get_texture_aux(info, data, EAST));
	if (!ft_strncmp(data[0], "WE", 3))
		return(get_texture_aux(info, data, WEST));
	return (1);
}

int	get_color_aux(t_info *info, char **rgb, int id)
{
	if (is_num(rgb))
	{
		free_double_pointer(rgb);
		error_exit(NO_NUMBER, info);
	}
	info->color[id - 4].id = id;
	info->color[id - 4].red = ft_atoi(rgb[0]);
	info->color[id - 4].green = ft_atoi(rgb[1]);
	info->color[id - 4].blue = ft_atoi(rgb[2]);
	if ((info->color[id - 4].red < 0 || info->color[id - 4].red > 255) ||
		(info->color[id - 4].green < 0 || info->color[id - 4].green > 255) ||
			(info->color[id - 4].blue < 0 || info->color[id - 4].blue > 255))
	{
		free_double_pointer(rgb);
		error_exit(NOT_VALID_NUM, info);
	}
	free_double_pointer(rgb);
	return (0);
}

int	get_color(t_info *info, char **data)
{
	char	**rgb;

	rgb = ft_split(data[1], ',');
	if (!rgb)
		error_exit(strerror(errno), info);
	if (!ft_strncmp(data[0], "C", 2))
		return (get_color_aux(info, rgb, CEILING));
	else if (!ft_strncmp(data[0], "F", 2))
		return (get_color_aux(info, rgb, FLOOR));
	else
	{
		free_double_pointer(rgb);
		return (1);
	}
}

void	get_map(t_info *info, char *line, int fd)
{
	char	*super_string;
	char	*aux;

	super_string = line;
	while (line)
	{
		line = get_next_line(fd);
		if (line && *line == '\n')
		{
			free(line);
			free(super_string);
			return ;
		}
		if (line)
		{
			aux = ft_strjoin(super_string, line);
			free(line);
			free(super_string);
			super_string = aux;
		}
	}
	info->map = ft_split(super_string, '\n');
	free(super_string);
}

int	analyse_line(t_info *info, char *line, int status)
{
	char	**data;

	if (*line == '\0')
		return (status);
	data = ft_split(line, ' ');
	if (!data)
		error_exit(strerror(errno), info);
	if (len_double_pointer(data) != 2)
	{
		free_double_pointer(data);
		error_exit(TO_MUCH_INFO, info);
	}
	if (get_texture(info, data) == 0)
		status++;
	else if (get_color(info, data) == 0)
		status++;
	else
		error_exit(INVALID_LINE, info); // More info
	free_double_pointer(data);
	return (status);
}

void	get_attribbutes(t_info *info, int fd)
{
	char	*line;
	int		limit;

	limit = 0;
	line = get_next_line(fd);
	while (line && limit < 6 && limit != -1)
	{
		delete_meta_spaces(line);
		line = trim_line(line);
		if (!line)
			break;
		limit = analyse_line(info, line, limit);
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
	{
		close (fd);
		error_exit(strerror(errno), info);
	}
	get_map(info, line, fd);
	//valid_map(info);
}

t_info	*extract_file_info(char *file)
{
	t_info	*info;
	int		fd;

	info = malloc(sizeof(t_info));
	if (!info)
		error_exit(strerror(errno), info);
	if (create_struct(info))
	{
		free(info);
		exit(1);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(info);
		return(error(strerror(errno)));
	}
	get_attribbutes(info, fd);
	close(fd);
	return (info);
}
