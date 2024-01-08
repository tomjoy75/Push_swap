/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:14:06 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/08 17:03:12 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// Cheapest way for a node to go up the stack b using rotations
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
//		best.instruction = "r";
	}
	else
	{
		best.nb_steps = nb_rr;
		best.f = rrb;
//		best.instruction = "rr";
	}
	return (best);
}

void	small_push_swap(t_stack **a)
{
	t_stack		*ptr;

	ptr = find_biggest_index(*a);
	if (ptr->position == 0)
		ra(a);
	if (ptr->position == 1)
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

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

void	push_to_stack_b(t_stack **a, t_stack **b)
{
//	t_stack	*ref;
	int	nb_nodes;
	int	div;
	int	index_to_push;
	int	i;

	div = 10;//Attention, div ne doit pas etre superieur a node_nb sinon nb_nodes / div = 0
	nb_nodes = node_nb(*a);
	while (nb_nodes > 3)
	{
//		ref = *a;
		i = 0;
		ra(a);//J'aurais aussi pu selectionner le dernier node
		index_to_push = ((nb_nodes / div) * 2) + find_smallest_index(*a)->index;
		while (i < nb_nodes)
		{
			if ((*a)->index <= ((nb_nodes / div) * 2) + find_smallest_index(*a)->index)
			{
				pb(a, b);
				if ((*b)->index < (nb_nodes / div + find_smallest_index(*a)->index))
					rb(b);
			}
			else
				ra(a);
			i++;
		}
/*		if ((*a)->index < ((nb_nodes / div) * 2) + find_smallest_index(*a)->index)
		{
			pb(a, b);
			if ((*b)->index < (nb_nodes / div + find_smallest_index(*a)->index))
				rb(b);
		}
		else
			ra(a);*/
		nb_nodes = node_nb(*a);
	}
}

void	back_to_a1(t_stack **a, t_stack **b)
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

void	find_goal_in_a(t_stack *a, t_stack *b)
{
	t_stack	*ptr;

	ptr = b;
	while (ptr->stack != 'a')
		ptr = ptr->next_ix;
	b->goal_node = ptr;
}

int	calculate_cost(t_stack *ptr)
{
	t_climb_up	best_a;
	t_climb_up	best_b;
	t_climb_both	best;
	int		cost;

	ptr->best = best_climb_up(ptr);
	ptr->goal_node->best = best_climb_up(ptr->goal_node);
	cost = ptr->best.nb_steps + ptr->goal_node->best.nb_steps;
	return (cost);
}

void	back_to_a2(t_stack **a, t_stack **b)
{
	t_climb_up	best;
	t_stack		*ptr;	
	int		cost;

	ptr = *b;
	while (*b)
	{
		find_goal_in_a(*a, *b);
		best = calculate_cost(*b);
		if (cost < ptr
		operate
		*b = (*b)->next;
	}
}

void	simple_algo4(t_stack **a, t_stack **b)
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
	back_to_a2(a, b);
}
