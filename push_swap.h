/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:15:35 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/05 04:46:27 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stack
{
	int				data;
	int				index;
	int				position;
	struct s_stack	*next;
}		t_stack;

typedef struct s_climb_up
{
	int				nb_steps;
	void	(*f)(t_stack **)	;
	int	operation;
}		t_climb_up;

// Implementation 
t_stack	*parsing_argument(char **argv, int argc);
// Datastructure : manipulation of linked lists
t_stack	*create_elem(int i);
t_stack	*find_last_elem(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *node);
void	stack_add_front(t_stack **stack, t_stack *node);
int		node_nb(t_stack *stack);
// Memory : gestion of freeing mallocs
void	free_stack(t_stack *stack);
void	free_argv(char **argv, int argc);
// Instructions : manipulation of the stack
void	swap(t_stack **stack);
void	push(t_stack **src, t_stack **dest);
void	rotate(t_stack **stack);
void	rev_rotate(t_stack **stack);
// Index
void	index_nodes(t_stack *stack);
t_stack	*find_node_by_index(t_stack *stack, int n);
// Value_update
void	position_update(t_stack *stack);
// Algorithms
void	show_stack(t_stack *stack, char *name);
void	position_update(t_stack *stack);
void	simple_algo(t_stack **stack_a, t_stack **stack_b);
#endif
