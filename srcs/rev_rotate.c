/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 23:24:10 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/15 20:41:33 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*sec_last;

	if (node_nb(*stack) < 2)
		return ;
	last = find_last_elem(*stack);
	sec_last = *stack;
	while (sec_last->next != last)
		sec_last = sec_last->next;
	sec_last->next = NULL;
	last->next = *stack;
	*stack = last;
	position_update(*stack);
}

void	rra(t_stack **a, int i)
{
	while (i)
	{
		rev_rotate(a);
		ft_printf("rra\n");
		i--;
	}
}

void	rrb(t_stack **b, int i)
{
	while (i)
	{
		rev_rotate(b);
		ft_printf("rrb\n");
		i--;
	}
}

void	rrr(t_stack **a, t_stack **b, int i)
{
	while (i)
	{
		rev_rotate(a);
		rev_rotate(b);
		ft_printf("rrr\n");
		i--;
	}
}
