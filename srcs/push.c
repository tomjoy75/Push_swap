/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 23:11:57 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/16 11:06:14 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"   

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

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	((*a)->stack)--;
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	((*b)->stack)++;
	ft_printf("pb\n");
}
