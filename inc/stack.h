/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:52:29 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/22 14:53:41 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include "errors.h"

typedef struct s_node
{
	int				x;
	int				y;
	struct s_node	*next;
}	t_node;

void	push(t_node **stack, int x, int y);
t_node	*pop(t_node **stack);
void	delete_stack(t_node **stack);
int		is_repeated(t_node *stack, int x, int y);

#endif
