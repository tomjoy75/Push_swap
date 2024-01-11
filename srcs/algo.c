/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:03:31 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/11 12:34:56 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stack_b(t_stack **a, t_stack **b)
{
	int	nb_nodes;
	int	div;
	int	index_to_push;
	int	index_to_push_and_rotate;
	int	i;

	nb_nodes = node_nb(*a);
	if (nb_nodes < 250)
		div = 3;
	else
		div = 6;
	while (nb_nodes > 3)
	{
		i = 0;
		if (div > nb_nodes)
			div = nb_nodes;
		index_to_push = ((nb_nodes / div) * 2) + find_smallest_index(*a)->index;
		index_to_push_and_rotate = (nb_nodes / div) + find_smallest_index(*a)->index;
		while (i < nb_nodes)
		{
			if ((*a)->index <= index_to_push)
			{
				pb(a, b);
				if ((*b)->index < index_to_push_and_rotate) 
					rb(b, 1);
			}
			else
				ra(a, 1);
			i++;
		}
		nb_nodes = node_nb(*a);
	}
}

void	small_push_swap(t_stack **a)
{
	t_stack		*ptr;

	ptr = find_biggest_index(*a);
	if (ptr->position == 0)
		ra(a, 1);
	if (ptr->position == 1)
		rra(a, 1);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}
/*
void	back_to_a_temp(t_stack **a, t_stack **b)
{
	t_stack	*ptr;
	t_climb_up	best;

	while(*b)
	{
		ptr = find_biggest_index(*b);
		best = best_climb_up_b(ptr, node_nb(*b));
		// Nécris pas l'action...voir best_climb_up
		while (best.nb_steps)
		{
			best.f(b);
			best.nb_steps--;
		}
		pa(a, b);
	}
}
*/
void	move_ptr(t_stack *ptr, t_stack **a, t_stack **b)
{
	if (ptr->best_sol == 0)
	{
		if(ptr->r >= ptr->goal_node->r)
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
	else if (ptr->best_sol == 1)
	{
		if(ptr->rr >= ptr->goal_node->rr)
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
		move_ptr(ptr, a, b);
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


void	push_swap(t_stack **a, t_stack **b)
{
//	t_stack	*ptr;
//	t_climb_up	best;

	if (is_sorted(*a))
		return ;
	push_to_stack_b(a, b);
	if (node_nb(*a) == 3)
		small_push_swap(a);
	else if (node_nb(*a) == 2 && (*a)->index > (*a)->next->index)
		sa(a);
	back_to_a(a, b);
	finishing(a, find_node_by_index(*a, 0));
}
