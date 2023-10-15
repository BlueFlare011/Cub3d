# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vbles.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blueflare011 <blueflare011@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/16 23:30:56 by rgallego          #+#    #+#              #
#    Updated: 2023/10/13 16:33:20 by blueflare01      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		=		src/

INC_DIR		=		inc/

PARSER_DIR	=		parser/

RAYCASTING_DIR	=	raycasting/

UTILS_DIR	=		utils/

CUBE		=		main.c

UTILS		=		$(addprefix $(UTILS_DIR), \
						utils.c \
						errors.c \
						get_next_line.c \
						get_next_line_utils.c \
					)

RAYCASTING	=		$(addprefix $(RAYCASTING_DIR), \
						mlx_management.c \
						utils.c \
						raycasting.c \
					)

PARSER		=		$(addprefix $(PARSER_DIR), \
						file.c \
						map.c \
						floodfill.c \
						stack.c \
					)

SRCS		= 		$(addprefix $(SRC_DIR), \
						$(PARSER) \
						$(UTILS) \
						$(RAYCASTING) \
						main.c	\
					)

OBJS	=			$(SRCS:.c=.o)

DPNDS	=			$(SRCS:.c=.d)

CC		=			cc

RM		=			-rm -f

CFLAGS	=			-Wall -Werror -Wextra -MD -fsanitize=address -g3

LDFLAGS	=			\
					$(LIBFTNAME) \
					$(MLXNAME)

NAME	=			cub3d

INC_ALL	=			\
					$(INC_DIR) \
					$(LIBFT)$(INC_DIR) \
					$(MLX)

LIBFT	=			libft/

LIBFTNAME	=		$(LIBFT)libft.a

ifeq ($(shell uname), Linux)
	MLX	= 			mlx_linux/

	MLXNAME	=		mlx_linux/libmlx.a

	FRAMEWORK	=	-lXext -lX11 -lm

else
	MLX		=		mlx/

	MLXNAME	=		libmlx.dylib

	FRAMEWORK	=	$(addprefix -framework , \
					OpenGL \
					AppKit) \
					-lmlx
endif
