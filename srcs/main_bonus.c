/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:55:53 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/15 16:39:36 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_mov_table(t_conv *tab)
{
	tab[0] = (t_conv){"ra/n", ra}
	tab[1] = (t_conv){"rb/n", rb}
	tab[2] = (t_conv){"rr/n", rr}
}

void	check_instructions(t_stack **a, t_stack **b)
{
	char	*next_line;

	while (1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break;
		
		free(next_line);
	}
	if (is_sorted(*a) && *b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
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
//	push_swap(&stack_a, &stack_b);
	check_instructions(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
