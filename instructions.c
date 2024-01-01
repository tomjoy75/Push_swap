/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:26:43 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/01 19:02:37 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*temp;

	if (node_nb(*stack) < 2)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack *temp;

	if (!*src)
		return ;
	temp = (*src)->next;
	stack_add_front(dest, *src);
	*src = temp;
}

void	rotate(t_stack **stack)
{
	t_stack	*temp;

	if (node_nb(*stack) < 2)
		return ;
	temp = (*stack)->next;
	find_last_elem(*stack)->next = *stack;
	(*stack)->next = NULL;
	*stack = temp; 
}

void	rev_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack *sec_last;

	if (node_nb(*stack) < 2)
		return ;
	last = find_last_elem(*stack);
	sec_last = *stack;
	while (sec_last->next != last)
		sec_last = sec_last->next;
	sec_last->next = NULL;
	last->next = *stack;
	*stack = last;
}
