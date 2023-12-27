/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:51:50 by tjoyeux           #+#    #+#             */
/*   Updated: 2023/12/28 00:05:55 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*parsing_argument(char **argv, int argc)
{
	t_stack	*stack;
	t_stack *elem;
	int	i;

	i = 0;
	while (argv[i])
	{
		elem = create_elem(ft_atoi(argv[i]));
		if (!elem)
			return (NULL);//Il faudra liberer tous les autres elements
		stack_add_back(&stack, elem);
		i++;
	}
	return (stack);
}
