/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:14:22 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/11 11:01:28 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_stack(t_stack *stack, char *name)
{
	int i;

	i = 1;
	ft_printf("---%s---\n", name);
	while (stack)
	{
		ft_printf("Node %d | position %d : value %d : index %d\n", i, stack->position, stack->data, stack->index);
//		ft_printf("next node value %d : prev node value %d\n", stack->next_ix->data, stack->prev_ix->data);
		stack = stack->next;
		i++;
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
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (1);
	}
	else
		argv++;
	stack_a = parsing_argument(argv, argc);
	free_argv(argv, argc);
	index_nodes(stack_a);
//	show_stack(stack_a, "STACK A");
/*	swap(&stack_a);
	show_stack(stack_a);

	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	show_stack(stack_a);
	show_stack(stack_b);
	rotate(&stack_a);
	rev_rotate(&stack_b);*/
//	ft_printf("---SIMPLE_ALGO---\n");
//	small_push_swap(&stack_a);
//	simple_algo4(&stack_a, &stack_b);
	push_swap(&stack_a, &stack_b);
//	show_stack(stack_a, "STACK_A");
//	show_stack(stack_b, "STACK_B");
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
