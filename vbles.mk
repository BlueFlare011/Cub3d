# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vbles.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/16 23:30:56 by rgallego          #+#    #+#              #
#    Updated: 2023/10/24 23:12:36 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		=		src/

INC_DIR		=		inc/

STACK_DIR	=		stack/

PARSER_DIR	=		parser/

RAYCASTING_DIR	=	raycasting/

MLX_MANAGEMENT_DIR	=	mlx_management/

EVENTS_DIR	=		events/

UTILS_DIR	=		utils/

CUBE		=		main.c

STACK	=			$(addprefix $(STACK_DIR), \
						stack.c \
					)

PARSER		=		$(addprefix $(PARSER_DIR), \
						floodfill.c \
						read_file.c \
						read_map.c \
						read_textures.c \
					)

RAYCASTING	=		$(addprefix $(RAYCASTING_DIR), \
						texture.c \
						raycasting.c \
					)

MLX_MANAGEMENT	=	$(addprefix $(MLX_MANAGEMENT_DIR), \
						mlx_management.c \
					)

EVENTS	=		$(addprefix $(EVENTS_DIR), \
						events.c \
					)

UTILS		=		$(addprefix $(UTILS_DIR), \
						utils.c \
						errors.c \
					)

SRCS		= 		$(addprefix $(SRC_DIR), \
						$(STACK) \
						$(PARSER) \
						$(RAYCASTING) \
						$(MLX_MANAGEMENT) \
						$(EVENTS) \
						$(UTILS) \
						main.c	\
					)

OBJS	=			$(SRCS:.c=.o)

DPNDS	=			$(SRCS:.c=.d)

CC		=			cc

RM		=			-rm -f

CFLAGS	=			-Wall -Werror -Wextra -MD -fsanitize=address -g3

LDFLAGS	=			\
					$(LIBFTNAME) \
					$(GNLNAME) \
					$(MLXNAME)

NAME	=			cub3d

INC_ALL	=			\
					$(INC_DIR) \
					$(LIBFT)$(INC_DIR) \
					$(GNL)$(INC_DIR) \
					$(MLX)

LIBFT	=			libft/

LIBFTNAME	=		$(LIBFT)libft.a

GNL		=			get_next_line/

GNLNAME	=			$(GNL)get_next_line.a

ifeq ($(shell uname), Linux)
	MLX	= 			mlx_linux/

	MLXNAME	=		$(MLX)libmlx.a

	FRAMEWORK	=	-lXext -lX11 -lm

else
	MLX		=		mlx_mac/

	MLXNAME	=		$(MLX)libmlx.a

	FRAMEWORK	=	$(addprefix -framework , \
					OpenGL \
					AppKit) \
					-lmlx
endif
