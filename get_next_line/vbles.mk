SRC_DIR = 			src/

INC_DIR =			inc/

SRCS	=			\
					$(addprefix $(SRC_DIR), \
					get_next_line.c \
					get_next_line_utils.c \
					)

OBJS	=			$(SRCS:.c=.o)

DPNDS	=			$(SRCS:.c=.d)

CC		=			gcc

RM		=			-rm -f

AR		=			ar rcs

CFLAGS	=			-Wall -Werror -Wextra -D BUFFER_SIZE=42 -MD

NAME	=			get_next_line.a
