#ifndef BFS_STACK_H
# define BFS_STACK_H

#include <stdlib.h>
#include "errors.h"

typedef struct s_node
{
	int	x;
	int	y;
	struct s_node *next;
}t_node;

t_node	*create_node(void);
void	push(t_node **stack, int x, int y);
t_node	*pop(t_node **stack);
void	delete_stack(t_node **stack);
int		is_repeated(t_node *stack, int x, int y);
void	print_stack(t_node *stack);
#endif
