/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:34:41 by socana-b          #+#    #+#             */
/*   Updated: 2023/10/21 13:48:55 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

enum e_direction
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3,
};

enum e_color
{
	FLOOR = 0,
	SKY = 1,
};

typedef struct s_raycast
{
	double	camera;
	int		start;
	int		end;
	int		height;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_x;
	double	delta_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	int		collided_side;
	double	dist;
}	t_raycast;

typedef struct s_texture
{
	int	width;
	int	height;
	int **img;
}	t_texture;

typedef struct s_map
{
	char	**map;
	int		max_x;
	int		max_y;
	double	player_x;
	double	player_y;
	double	dir_x;
	double	dir_y;
}	t_map;

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	*img;
	void	*floor;
	void	*wall;
	int		size;
}	t_mlx;

typedef struct s_keys
{
	int	a;
	int	w;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_keys;

typedef struct s_cube
{
	t_map		*map;
	t_mlx		*mlx;
	int			colour[2];
	t_texture	texture[4];
	t_keys		keys;
}	t_cube;

#endif
