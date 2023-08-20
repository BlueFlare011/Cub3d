SRC_DIR		=		src/

INC_DIR		=		inc/

PARSER_DIR	=		parser/

UTILS_DIR	=		utils/

CUBE		=		main.c

UTILS		=		$(addprefix $(UTILS_DIR), \
						utils.c \
						get_next_line.c \
						get_next_line_utils.c \
					)

PARSER		=		$(addprefix $(PARSER_DIR), \
						file.c \
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

CFLAGS	=			-Wall -Werror -Wextra -MD

LDFLAGS	=			$(LIBFTNAME)

NAME	=			cube3D

INC_ALL	=			\
					$(INC_DIR) \
					$(LIBFT)$(INC_DIR)

LIBFT	=			libft/

LIBFTNAME	=		$(LIBFT)libft.a
