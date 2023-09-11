#include "bfs_stack.h"

void	create_stack(t_stack *stack)
{
	*stack = NULL;
}

void	push(t_stack *stack, int y, int x)
{
	t_node	*node;

	if (is_repeated(stack, x, y))
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		error_exit(strerror(errno), GENERAL_ERR);
	node->x = x;
	node->y = y;
	node->next = *stack;
	*stack = node;
}

t_node	*pop(t_stack *stack)
{
	t_node	*node;
	t_node	*result;

	node = *stack;
	if (!node)
	{
		*stack = NULL;
		return (NULL);
	}
	if (!node->next)
	{
		*stack = NULL;
		return (node);
	}
	while (node->next->next)
		node = node->next;
	result = node->next;
	node->next = NULL;
	return (result);
}

void	deleteStack(t_stack *stack)
{
	t_node	*aux;

	aux = *stack;
	while (aux)
	{
		aux = aux->next;
		free(*stack);
		*stack = aux;
	}
	free(stack);
}

int	is_repeated(t_stack *stack, int x, int y)
{
	t_node	*aux;

	aux = *stack;
	while (aux)
	{
		if (aux->x == x && aux->y == y)
			return (1);
		aux = aux->next;
	}
	return (0);
}

void	printStack(t_stack *stack)
{
	t_node	*aux;

	aux = *stack;
	while (aux)
	{
		printf("Position X: %d / Position Y: %d\n", aux->x, aux->y);
		aux = aux->next;
	}
}
