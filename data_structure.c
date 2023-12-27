/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:08:46 by tjoyeux           #+#    #+#             */
/*   Updated: 2023/12/27 18:44:15 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_elem(int i)
{
	t_stack	*elem;

	elem = malloc(sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem->data = i;
	elem->next = NULL;
	return (elem);
}

t_stack	*find_last_elem(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	stack_add_back(t_stack **stack, t_stack *node)
{
	t_stack	*last;

	if (!node)
		return;
	if (!*stack)
		*stack = node;
	else
	{
		last = find_last_elem(*stack);
		last->next = node;
	}
}
