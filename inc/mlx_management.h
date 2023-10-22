/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_management.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:36:12 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/22 15:16:02 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_MANAGEMENT_H
# define MLX_MANAGEMENT_H

# include "mlx.h"
# include "cube.h"
# include "errors.h"

# define WIN_X 1080
# define WIN_Y 720

void	ft_mlx_init(t_cube *cube);
void	my_pixel_put(t_img img, int x, int y, int colour);
char	*mlx_get_texture(t_cube cube, t_img *img, t_texture *texture,
	char *file_name);

#endif
