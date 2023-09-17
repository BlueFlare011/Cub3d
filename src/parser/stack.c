/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:49:44 by rgallego          #+#    #+#             */
/*   Updated: 2023/09/18 00:55:57 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_node	*create_node(void)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		error_exit(strerror(errno), SYS_ERR);
	return (node);
}

void	push(t_node **stack, int y, int x)
{
	t_node	*node;

	if (is_repeated(*stack, x, y))
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		error_exit(strerror(errno), GENERAL_ERR);
	node->x = x;
	node->y = y;
	node->next = *stack;
	*stack = node;
}

t_node	*pop(t_node **stack)
{
	t_node	*aux;

	if (!*stack)
		return (NULL);
	aux = *stack;
	*stack = (*stack)->next;
	aux->next = NULL;
	return (aux);
}

void	delete_stack(t_node **stack)
{
	t_node	*aux;

	aux = *stack;
	while (aux)
	{
		*stack = (*stack)->next;
		free(aux);
		aux = *stack;
	}
	*stack = NULL;
}

int	is_repeated(t_node *stack, int x, int y)
{
	t_node	*aux;

	aux = stack;
	while (aux && (aux->x != x || aux->y != y))
		aux = aux->next;
	if (aux)
		return (1);
	return (0);
}
