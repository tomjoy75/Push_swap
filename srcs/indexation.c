/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:28:26 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/16 11:05:33 by tjoyeux          ###   ########.fr       */
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

static void	parents_nodes(t_stack *stack)
{
	int		size_a;
	t_stack	*ptr;

	size_a = node_nb(stack);
	ptr = stack;
	while (ptr)
	{
		if (ptr->index < size_a - 1)
			ptr->next_ix = find_node_by_index(stack, ptr->index + 1);
		else
			ptr->next_ix = find_node_by_index(stack, 0);
		if (ptr->index > 0)
			ptr->prev_ix = find_node_by_index(stack, ptr->index - 1);
		else
			ptr->prev_ix = find_node_by_index(stack, size_a - 1);
		ptr->stack = 'a';
		ptr = ptr->next;
	}
}

void	index_nodes(t_stack *stack)
{
	int	c;
	int	nb;

	c = 0;
	nb = node_nb(stack);
	while (c < nb)
	{
		find_lowest_node(stack)->index = c;
		c++;
	}
	parents_nodes(stack);
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

void	position_update(t_stack *stack)
{
	int	c;

	c = 0;
	while (stack)
	{
		stack->position = c;
		c++;
		stack = stack->next;
	}
}
