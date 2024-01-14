/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pre_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:03:31 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/14 17:24:43 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	divide_stack_a(t_stack **a, t_stack **b, int div, int nb_nodes)
{
	int	idx_to_push;
	int	idx_to_push_and_rotate;
	int	i;

	nb_nodes = node_nb(*a);
	i = 0;
	if (div > nb_nodes)
		div = nb_nodes;
	idx_to_push = ((nb_nodes / div) * 2) + find_smallest_index(*a)->index;
	idx_to_push_and_rotate = (nb_nodes / div) + find_smallest_index(*a)->index;
	while (i < nb_nodes)
	{
		if ((*a)->index <= idx_to_push)
		{
			pb(a, b);
			if ((*b)->index < idx_to_push_and_rotate) 
				rb(b, 1);
		}
		else
			ra(a, 1);
		i++;
	}
}

void	push_to_stack_b(t_stack **a, t_stack **b)
{
	int	nb_nodes;
	int	div;

	nb_nodes = node_nb(*a);
	if (nb_nodes < 250)
		div = 4;
	else
		div = 6;
	while (nb_nodes > 3)
	{
		divide_stack_a(a, b, div, nb_nodes);
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

void	push_swap(t_stack **a, t_stack **b)
{
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
