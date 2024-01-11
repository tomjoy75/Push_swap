/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:22:06 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/11 12:47:32 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*temp;

	if (node_nb(*stack) < 2)
		return ;
	temp = (*stack)->next;
	find_last_elem(*stack)->next = *stack;
	(*stack)->next = NULL;
	*stack = temp;
	position_update(*stack);
}

void	ra(t_stack **a, int i)
{
	while (i)
	{
		rotate(a);
		ft_printf("ra\n");
		i--;
	}
}

void	rb(t_stack **b, int i)
{
	while (i)
	{
		rotate(b);
		ft_printf("rb\n");
		i--;
	}
}

void	rr(t_stack **a, t_stack **b, int i)
{
	while (i)
	{
		rotate(a);
		rotate(b);
		ft_printf("rr\n");
		i--;
	}
}
