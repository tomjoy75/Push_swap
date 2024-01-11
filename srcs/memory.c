/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:58:44 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/02 14:01:21 by tjoyeux          ###   ########.fr       */
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

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
