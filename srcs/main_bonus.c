/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:55:53 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/15 23:49:59 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotation(t_stack **a, t_stack **b, char *str)
{
	int	bool;

	bool = 1;
	if (!ft_strncmp(str, "ra\n", 3))
		rotate(a);
	else if (!ft_strncmp(str, "rb\n", 3))
		rotate(b);
	else if (!ft_strncmp(str, "rr\n", 3))
	{
		rotate(a);
		rotate(b);
	}
	else if (!ft_strncmp(str, "rra\n", 4))
		rev_rotate(a);
	else if (!ft_strncmp(str, "rrb\n", 4))
		rev_rotate(b);
	else if (!ft_strncmp(str, "rrr\n", 4))
	{
		rev_rotate(a);
		rev_rotate(b);
	}
	else
		bool = 0;
	return (bool);
}

void	apply_instruction(t_stack **a, t_stack **b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		swap(a);
	else if (!ft_strncmp(str, "sb\n", 3))
		swap(b);
	else if (!ft_strncmp(str, "ss\n", 3))
	{
		swap(a);
		swap(b);
	}
	else if (!ft_strncmp(str, "pb\n", 3))
		push(a, b);
	else if (!ft_strncmp(str, "pa\n", 3))
		push(b, a);
	else if (rotation(a, b, str))
	{
	}
	else
	{
		free_stack(*a);
		free_stack(*b);
		get_next_line(0, 1);
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	check_instructions(t_stack **a, t_stack **b)
{
	char	*next_line;

	while (1)
	{
		next_line = get_next_line(0, 0);
		if (next_line == NULL)
			break ;
		apply_instruction(a, b, next_line);
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
	check_instructions(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
