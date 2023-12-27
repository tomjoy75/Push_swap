/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:14:22 by tjoyeux           #+#    #+#             */
/*   Updated: 2023/12/27 18:09:24 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d - ", stack->data);
		stack = stack->next;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || (argc == 2 && !*argv[1]))
		return (0);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (1);
	else
		argv++;
	stack_a = parsing_argument(argv, argc);	
	show_stack(stack_a);
	return (0);
}
