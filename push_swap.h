/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:15:35 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/09 23:39:50 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_climb_up t_climb_up;
typedef struct s_stack
{
	int				data;
	int				index;
	int				position;
	char				stack;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	struct s_stack	*next;
	struct s_stack	*next_ix;
	struct s_stack	*prev_ix;
	struct s_stack	*goal_node;
	struct t_climb_up	*best;
}		t_stack;

struct s_climb_up
{
	int				nb_steps;
	void	(*f)(t_stack **)	;
	char	*instruction;
}	;//	t_climb_up;

typedef struct s_climb_both
{
	int				nb_steps_both;
	void	(*f_both)(t_stack **, t_stack **);
	int				nb_steps_solo;
	void	(*f_solo)(t_stack **);
}		t_climb_both;

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
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rev_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
// Index
void	index_nodes(t_stack *stack);
t_stack	*find_node_by_index(t_stack *stack, int n);
// Value_update
void	position_update(t_stack *stack);
// Push_swap_utils
void	show_stack(t_stack *stack, char *name);
void	position_update(t_stack *stack);
t_climb_up	best_climb_up(t_stack	*ptr, int	size);
void	small_push_swap(t_stack **a);
void    push_to_stack_b(t_stack **a, t_stack **b);
// Push_swap
/*void	simple_algo(t_stack **stack_a, t_stack **stack_b);
void	simple_algo2(t_stack **stack_a, t_stack **stack_b);
void	simple_algo3(t_stack **stack_a, t_stack **stack_b);
void	simple_algo4(t_stack **a, t_stack **b);*/
void	push_swap(t_stack **a, t_stack **b);
// Algo_utils
t_stack	*find_smallest_index(t_stack *stack);
t_stack	*find_biggest_index(t_stack *stack);
int	is_sorted(t_stack *a);
t_climb_up	best_climb_up_b(t_stack	*ptr, int	size);
void	set_goalnode(t_stack *a, t_stack *b);
#endif
