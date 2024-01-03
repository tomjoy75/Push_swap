/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:02:30 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/03 16:56:59 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_algo(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*ptr;
	int		n;
	int		size_a;

	//Phase 1: on rotate jusqu'au + petit et on met tout dans b tant qu'il y a + e deux elements dans a
	n = 0;
	size_a = node_nb(stack_a);
	while (n < size_a)
	{
		ptr = find_node_by_index(stack_a, n);

		n++;
	}
	//Ph 1bis: on rotate a si besoin
	//Phase 2: on remet tout dans a
}
