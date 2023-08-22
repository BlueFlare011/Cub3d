-include vbles.mk

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(addprefix -I, $(INC_ALL)) -c $< -o $@

$(LIBFTNAME):
	$(MAKE) -C $(LIBFT)

$(NAME): $(OBJS) $(LDFLAGS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTNAME) $(addprefix -l, $(LIB_ALL)) -o $@
#-lmlx -framework OpenGL -framework AppKit
clean:
	$(RM) $(OBJS) $(DPNDS)
	$(MAKE) -C $(LIBFT) fclean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean bonus re
