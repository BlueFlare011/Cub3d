# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vbles.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/16 23:30:56 by rgallego          #+#    #+#              #
#    Updated: 2023/09/17 17:18:47 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		=		src/

INC_DIR		=		inc/

PARSER_DIR	=		parser/

UTILS_DIR	=		utils/

CUBE		=		main.c

UTILS		=		$(addprefix $(UTILS_DIR), \
						utils.c \
						errors.c \
						get_next_line.c \
						get_next_line_utils.c \
					)

PARSER		=		$(addprefix $(PARSER_DIR), \
						file.c \
						map.c \
						stack.c \
					)

SRCS		= 		$(addprefix $(SRC_DIR), \
						$(PARSER) \
						$(UTILS) \
						main.c	\
					)

OBJS	=			$(SRCS:.c=.o)

DPNDS	=			$(SRCS:.c=.d)

CC		=			gcc

RM		=			-rm -f

CFLAGS	=			-Wall -Werror -Wextra -MD -fsanitize=address -g3

LDFLAGS	=			\
					$(LIBFTNAME) \
					$(MLXNAME)

NAME	=			cube3D

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
