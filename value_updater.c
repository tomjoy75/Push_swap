/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_updater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:51:20 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/04 09:55:06 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	position_update(t_stack *stack)
{
	int	c;

	c = 0;
	while (stack)
	{
		stack->position = c;
		c++;
		stack = stack->next;
	}
}

