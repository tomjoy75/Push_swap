/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:51:50 by tjoyeux           #+#    #+#             */
/*   Updated: 2023/12/27 18:28:21 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*parsing_argument(char **argv, int argc)
{
	t_stack	*stack;

	while (argv)
	{
		stack = create_elem(ft_atoi(*argv));
		if (!stack)
			return (NULL);//Il faudra liberer tous les autres elements
	}
	return (stack);
}
