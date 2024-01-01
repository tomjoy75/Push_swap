/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:51:50 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/01 14:11:15 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_argv(char **argv, int argc)
{
	char	**temp;

	temp = argv;
	if (argc == 2)
	{
		while (*temp)
		{
			free(*temp);
			temp++;
		}
		free(argv);
	}
}

void	error_msg(t_stack *stack, char **argv, int argc)
{
	free_argv(argv, argc);
	free_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	is_double(int n, t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->data == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	atoi_base(char *str, t_stack *stack, char **argv, int argc)
{
	int			sign;
	long long	n;

	sign = 1;
	n = 0;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			error_msg(stack, argv, argc);
		n = n * 10 + (*str - 48);
		if ((sign == 1 && n > INT_MAX) || (sign == -1 && n > -INT_MIN))
			error_msg(stack, argv, argc);
		str++;
	}
	if (is_double(((int)n * sign), stack))
		error_msg(stack, argv, argc);
	return ((int)n * sign);
}

t_stack	*parsing_argument(char **argv, int argc)
{
	t_stack	*stack;
	t_stack	*elem;
	int		i;

	i = 0;
	stack = NULL;
	while (argv[i])
	{
		elem = create_elem(atoi_base(argv[i], stack, argv, argc));
		if (!elem)
			return (NULL);
		stack_add_back(&stack, elem);
		i++;
	}
	return (stack);
}
