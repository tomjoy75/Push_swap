/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:02:30 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/05 04:49:19 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_climb_up	best_climb_up(t_stack	**stack, int	size)
{
	t_climb_up	best;
	int		nb_r;
	int		nb_rr;

	nb_r = (*stack)->position;
	nb_rr = size - (*stack)->position;
	if (nb_r <= nb_rr)
	{
		best.nb_steps = nb_r;
		best.f = rotate;
		best.operation = 3;
	}
	else
	{
		best.nb_steps = nb_rr;
		best.f = rev_rotate;
		best.operation = 4;
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
		best = best_climb_up(stack_a, size_a);
		while (best.nb_steps > 0)
		{
			best.f(stack_a);
			best.nb_steps--;
			if (best.operation == 3)
				ft_printf("ra\n");
			if (best.operation == 4)
				ft_printf("rra\n");

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
	t_stack	*ptr;
	int		n;
	int		i;
	int		size_a;

	//Phase 1: on rotate jusqu'au + petit, ou au + grand et on met tout dans b tant qu'il y a + e deux elements dans a
	n = 0;
	size_a = node_nb(*stack_a);
	while (size_a > 2)
	{
		i = 0;
		ptr = find_node_by_index(*stack_a, n);
			while (size_a / 2 < ptr->position)
		{
			rev_rotate(stack_a);
			ft_printf("rra\n");
		}
		while (ptr->position > 0)
		{
			rotate(stack_a);
			ft_printf("ra\n");
		}
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

