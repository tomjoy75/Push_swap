/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:02:30 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/04 17:01:24 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_algo(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*ptr;
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

