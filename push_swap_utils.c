/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:02:30 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/05 19:17:17 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_climb_up	best_climb_up(t_stack	*ptr, int	size)
{
	t_climb_up	best;
	int		nb_r;
	int		nb_rr;

	nb_r = ptr->position;
	nb_rr = size - ptr->position;
	if (nb_r <= nb_rr)
	{
		best.nb_steps = nb_r;
		best.f = rotate;
		best.instruction = "r";
	}
	else
	{
		best.nb_steps = nb_rr;
		best.f = rev_rotate;
		best.instruction = "rr";
	}
	return (best);
}

void	simple_algo(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*ptr;
	t_climb_up	best;
	int		n;
	int		i;
	int		size_a;

	//Phase 1: on rotate jusqu'au + petit et on met tout dans b tant qu'il y a + e deux elements dans a
	n = 0;
	size_a = node_nb(*stack_a);
	while (size_a > 2)
	{
		i = 0;
		ptr = find_node_by_index(*stack_a, n);
		best = best_climb_up(ptr, size_a);
		while (best.nb_steps > 0)
		{
			best.f(stack_a);
			best.nb_steps--;
			ft_printf("%sa\n", best.instruction);

		}
/*			while (size_a / 2 < ptr->position)
		{
			rev_rotate(stack_a);
			ft_printf("rra\n");
		}
		while (ptr->position > 0)
		{
			rotate(stack_a);
			ft_printf("ra\n");
		}*/
		push(stack_a, stack_b);
		ft_printf("pb\n");
		size_a--;
		n++;
	}
	//Ph 1bis: on swap a si besoin
	if ((*stack_a)->data > (*stack_a)->next->data)
	{
		swap(stack_a);
		ft_printf("sa\n");
	}
	//Phase 2: on remet tout dans a
	while (node_nb(*stack_b))
	{
		push(stack_b, stack_a);
		ft_printf("pa\n");
	}
}

void	simple_algo2(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*low_ptr;
	t_stack	*high_ptr;
	t_stack *ptr;
	int	low_index;
	int	high_index;
	t_climb_up	best;
	int		n;
	int		size_a;

	//Phase 1: on rotate jusqu'au + petit et on met tout dans b tant qu'il y a + e deux elements dans a
	n = 0;
	size_a = node_nb(*stack_a);
	if ((*stack_a)->index > 0)
		low_index = ((*stack_a)->index - 1);
	else
		low_index = size_a - 1;
	if ((*stack_a)->index >= size_a - 1)
		high_index = 0;
	else
		high_index = ((*stack_a)->index + 1);
	push(stack_a, stack_b);
	ft_printf("pb\n");
	size_a--;
	
	while (size_a > 2)
	{
		low_ptr = find_node_by_index(*stack_a, low_index);
		high_ptr = find_node_by_index(*stack_a, high_index);
		if ((best_climb_up(low_ptr, size_a).nb_steps) >=  (best_climb_up(high_ptr, size_a).nb_steps))
		{
			best = best_climb_up(high_ptr, size_a);
			if (high_index < size_a - 1)
				high_index++;
			else
				high_index = 0;
		}
		else
		{
			best = best_climb_up(low_ptr, size_a);
			if (low_index > 0)
				low_index--;
			else
				low_index = size_a - 1;
		}
		while (best.nb_steps > 0)
		{
			best.f(stack_a);
			best.nb_steps--;
			ft_printf("%sa\n", best.instruction);

		}
		push(stack_a, stack_b);
		ft_printf("pb\n");
		if ((*stack_b)->index < (*stack_b)->next->index)
		{
			rotate(stack_b);
			ft_printf("rb\n");
		}
		size_a--;
		n++;
	}
	//Ph 1bis: on swap a si besoin
	if ((*stack_a)->data > (*stack_a)->next->data)
	{
		swap(stack_a);
		ft_printf("sa\n");
	}
	//Phase 2: on remet tout dans a
	while (node_nb(*stack_b))
	{
		push(stack_b, stack_a);
		ft_printf("pa\n");
	}
	//Phase 3: on rotate la stack a pour avoir le bon ordre
	
	ptr = find_node_by_index(*stack_a, 0);
	best = best_climb_up(ptr, node_nb(*stack_a));

	while (best.nb_steps > 0)
	{
		best.f(stack_a);
		best.nb_steps--;
		ft_printf("%sa\n", best.instruction);
	}
}
