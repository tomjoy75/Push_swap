/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:14:22 by tjoyeux           #+#    #+#             */
/*   Updated: 2023/12/26 16:37:48 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	show_stack(t_list *stack)
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
	t_list	*stack_a;
	t_list	*stack_b;
	int	i;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
//	else if (argc == 2)
//		argv = ft_split(argv[1], ' ');
	i = 0;
	ft_lstadd_front(&stack_a, ft_lstnew(argv[1]));
	show_stack(stack_a);
	return (0);
}
