/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:28:26 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/04 09:51:14 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_lowest_node(t_stack *stack)
{
	t_stack	*node;

	node = NULL;
	while (stack)
	{
		if (stack->index == -1)
			if (!node || stack->data < node->data) 
				node = stack;
		stack = stack->next;
	}
	return (node);
}

void	index_nodes(t_stack *stack)
{
	int	c;
	int	nb;

	c = 0;
	nb = node_nb(stack);
//	ft_printf("node nb = %d\n", nb);
	while (c < nb)
	{
		find_lowest_node(stack)->index = c;
		c++;
	}
}

t_stack	*find_node_by_index(t_stack *stack, int n)
{
	while (stack)
	{
		if (stack->index == n)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
