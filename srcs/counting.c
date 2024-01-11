/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:39:00 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/10 22:19:23 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	counting_rotation(t_stack *stack)
{
	int	size;

	size = node_nb(stack);
	while (stack)
	{
		stack->r = stack->position;
		if (stack->position > 0)
			stack->rr = size - stack->position;
		else
			stack->rr = 0;
		stack = stack->next;
	}
}

void	counting_combination(t_stack *b)
{
		if (b->r >= b->goal_node->r)
			b->combi[0] = b->r;
		else
			b->combi[0] = b->goal_node->r;
		b->best_sol = 0;
		if (b->rr >= b->goal_node->rr)
			b->combi[1] = b->rr;
		else
			b->combi[1] = b->goal_node->rr;
		if (b->combi[1] < b->combi[b->best_sol])
			b->best_sol = 1;
		b->combi[2] = b->r + b->goal_node->rr;
		if (b->combi[2] < b->combi[b->best_sol])
			b->best_sol = 2;
		b->combi[3] = b->rr + b->goal_node->r;
		if (b->combi[3] < b->combi[b->best_sol])
			b->best_sol = 3;
		b->best_cost = b->combi[b->best_sol];
}

t_stack	*best_combination(t_stack *b)
{
	t_stack	*ptr;

	ptr = b;
	while (b)
	{
		set_goalnode(b);
		counting_combination(b);
		if (b->best_cost < ptr->best_cost)
			ptr = b;
		b = b->next;
	}
	return (ptr);
}
