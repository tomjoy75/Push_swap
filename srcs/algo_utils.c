/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:03:56 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/14 02:06:32 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	int	n;

	n = a->index;
	while (a)
	{
		if (a->index < n)
			return (0);
		n = a->index;
		a = a->next;
	}
	return (1);
}

t_stack	*find_smallest_index(t_stack *stack)
{
	t_stack	*ptr;

	if (!stack)
		return (NULL);
	ptr = stack;
	while (stack)
	{
		if (stack->index < ptr->index)
			ptr = stack;
		stack = stack->next;
	}
	return (ptr);
}

t_stack	*find_biggest_index(t_stack *stack)
{
	t_stack	*ptr;

	if (!stack)
		return (NULL);
	ptr = stack;
	while (stack)
	{
		if (stack->index > ptr->index)
			ptr = stack;
		stack = stack->next;
	}
	return (ptr);
}

void	set_goalnode(t_stack *b)
{
	t_stack	*ptr;

	ptr = b;
	while (ptr->stack != 'a')
		ptr = ptr->next_ix;
	b->goal_node = ptr;
}
