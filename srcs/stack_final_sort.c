/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_final_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:25:02 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/15 21:24:44 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_a_and_b(t_stack *ptr, t_stack **a, t_stack **b)
{
	if (ptr->r >= ptr->goal_node->r)
	{
		rr(a, b, ptr->goal_node->r);
		rb(b, ptr->r - ptr->goal_node->r);
	}
	else
	{
		rr(a, b, ptr->r);
		ra(a, ptr->goal_node->r - ptr->r);
	}
}

static void	rev_rotate_a_and_b(t_stack *ptr, t_stack **a, t_stack **b)
{
	if (ptr->rr >= ptr->goal_node->rr)
	{
		rrr(a, b, ptr->goal_node->rr);
		rrb(b, ptr->rr - ptr->goal_node->rr);
	}
	else
	{
		rrr(a, b, ptr->rr);
		rra(a, ptr->goal_node->rr - ptr->rr);
	}
}

static void	move_to_a(t_stack *ptr, t_stack **a, t_stack **b)
{
	if (ptr->best_sol == 0)
		rotate_a_and_b(ptr, a, b);
	else if (ptr->best_sol == 1)
		rev_rotate_a_and_b(ptr, a, b);
	else if (ptr->best_sol == 2)
	{
		rb(b, ptr->r);
		rra(a, ptr->goal_node->rr);
	}
	else if (ptr->best_sol == 3)
	{
		ra(a, ptr->goal_node->r);
		rrb(b, ptr->rr);
	}
	pa(a, b);
}

void	back_to_a(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	while (*b)
	{
		counting_rotation(*a);
		counting_rotation(*b);
		ptr = best_combination(*b);
		move_to_a(ptr, a, b);
	}
}

void	finishing(t_stack **a, t_stack *ptr)
{
	int		nb_r;
	int		nb_rr;
	int		size;

	size = node_nb(*a);
	nb_r = ptr->position;
	nb_rr = size - ptr->position;
	if (nb_r <= nb_rr)
		ra(a, nb_r);
	else
		rra(a, nb_rr);
}
