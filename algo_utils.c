/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:03:56 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/09 17:42:01 by tjoyeux          ###   ########.fr       */
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
	t_stack *ptr;

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

t_climb_up	best_climb_up_b(t_stack	*ptr, int	size)
{
	t_climb_up	best;
	int		nb_r;
	int		nb_rr;

	nb_r = ptr->position;
	nb_rr = size - ptr->position;
	if (nb_r <= nb_rr)
	{
		best.nb_steps = nb_r;
		best.f = rb;
	}
	else
	{
		best.nb_steps = nb_rr;
		best.f = rrb;
	}
	return (best);
}

void	set_goalnode(t_stack *a, t_stack *b)
{
	t_stack	*ptr;

	ptr = b;
	while (ptr->stack != 'a')
		ptr = ptr->next_ix;
	b->goal_node = ptr;
}


