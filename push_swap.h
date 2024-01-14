/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:15:35 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/14 21:47:05 by tjoyeux          ###   ########.fr       */
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
	char				stack;
	int				r;
	int				rr;
	int				combi[4];
	int				best_sol;
	int				best_cost;
	struct s_stack	*next;
	struct s_stack	*next_ix;
	struct s_stack	*prev_ix;
	struct s_stack	*goal_node;
}		t_stack;

//____________________IMPLEMENT PART_______________________
// Parsing 
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
// Index
void	index_nodes(t_stack *stack);
t_stack	*find_node_by_index(t_stack *stack, int n);
void	position_update(t_stack *stack);
//____________________SORTING PART______________________
// Stack_pre_sort
void	push_swap(t_stack **a, t_stack **b);
void	small_push_swap(t_stack **a);
void    push_to_stack_b(t_stack **a, t_stack **b);
// Stack_final_sort
void	back_to_a(t_stack **a, t_stack **b);
void	finishing(t_stack **a, t_stack *ptr);
// Algo_utils
t_stack	*find_smallest_index(t_stack *stack);
t_stack	*find_biggest_index(t_stack *stack);
int	is_sorted(t_stack *a);
void	set_goalnode(t_stack *b);
// Counting
void	counting_rotation(t_stack *stack);
t_stack	*best_combination(t_stack *b);
//____________________MOVING STACKS____________________
//void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
//void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
//void	rotate(t_stack **stack);
void	ra(t_stack **a, int i);
void	rb(t_stack **b, int i);
void	rr(t_stack **a, t_stack **b, int i);
//void	rev_rotate(t_stack **stack);
void	rra(t_stack **a, int i);
void	rrb(t_stack **b, int i);
void	rrr(t_stack **a, t_stack **b, int i);
#endif
