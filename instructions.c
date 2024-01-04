/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:26:43 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/04 10:04:12 by tjoyeux          ###   ########.fr       */
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
	(*stack)->position = 0;
	(*stack)->next->position = 1;
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (!*src)
		return ;
	temp = (*src)->next;
	stack_add_front(dest, *src);
	*src = temp;
	position_update(*src);
	position_update(*dest);
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
	position_update(*stack);
}

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
