#ifndef BFS_STACK_H
# define BFS_STACK_H

#include <stdlib.h>
#include <stdio.h>
#include "errors.h"

typedef struct s_node
{
	int	x;
	int	y;
	struct s_node *next;
}t_node;

typedef t_node *t_stack;

void	create_stack(t_stack *stack);
void	push(t_stack *stack, int x, int y);
t_node	*pop(t_stack *stack);
void	deleteStack(t_stack *stack);
int		is_repeated(t_stack *stack, int x, int y);
void	printStack(t_stack *stack);
#endif