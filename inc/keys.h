/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:39:36 by rgallego          #+#    #+#             */
/*   Updated: 2023/09/16 23:47:29 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# define ON_KEYDOWN 2

/* **************************** KEY CODES MACOS ***************************** */
// # define MASK 0

// # define KEY_Z 6
// # define KEY_X 7
// # define KEY_E 14
// # define KEY_R 15
// # define KEY_O 31
// # define KEY_U 32
// # define KEY_I 34
// # define KEY_P 35
// # define KEY_ESC 53
// # define KEY_LEFT 123
// # define KEY_RIGHT 124
// # define KEY_DOWN 125
// # define KEY_UP 126#

/* *************************** KEY CODES WINDOWS **************************** */
# define MASK 1L << 0

# define KEY_Z 122
# define KEY_X 120
# define KEY_E 101
# define KEY_R 114
# define KEY_O 111
# define KEY_U 117
# define KEY_I 105
# define KEY_P 112
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_UP 65362

#endif
