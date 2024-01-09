/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:03:31 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/09 17:30:27 by tjoyeux          ###   ########.fr       */
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
					rb(b);
			}
			else
				ra(a);
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
		ra(a);
	if (ptr->position == 1)
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

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
	back_to_a_temp(a, b);
}
