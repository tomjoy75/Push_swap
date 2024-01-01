/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:15:35 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/01 00:14:19 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
//# include "ft_printf/ft_printf.h"
#define INT_MIN -2147483648
#define INT_MAX 2147483647
typedef struct	s_stack
{
	int			data;
	struct s_stack	*next;
}		t_stack;
//char	**ft_split(char const *s, char c);
t_stack	*create_elem(int i);
t_stack	*find_last_elem(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *node);
t_stack	*parsing_argument(char **argv, int argc);
void	free_stack(t_stack *stack);
void	free_argv(char **argv, int argc);

#endif
