/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:27:27 by afrasch           #+#    #+#             */
/*   Updated: 2021/12/06 22:52:37 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* defines */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* includes */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libs/libft/libft.h"

/* macros */
# define NO -1
# define YES 1
# define NEXT_IS_CLOSER 1
# define PREV_IS_CLOSER 2
# define BOTH_UP 0
# define BOTH_DOWN 1
# define A_UP_B_DOWN 2
# define A_DOWN_B_UP 3
# define STACK_A 0
# define STACK_B 1

/* structs */
typedef struct s_node
{
	int				content;
	struct s_node	*prev;
	struct s_node	*next;
	int				index;
	int				chunk;
	int				moves;
	struct s_node	*partner;
	int				best_combi;
}					t_node;

typedef struct s_push_swap
{
	t_node	*input_head;
	t_node	*head_b;
	t_node	*head_a;
	int		argc;
	int		op_count;
}			t_push_swap;

/* prototypes */
int		push_swap(t_push_swap *stack, int argc, char *argv[]);
void	check_input_and_create_stack(t_push_swap *stack, int argc, char **argv);
void	ranker(t_push_swap *stack);
int		is_sorted(t_node **head);
int		is_rev_sorted(t_node **head_one);
void	check_for_dups(t_push_swap *stack);
void	*free_list(t_node **head);
int		put_error(t_node *head_uno, t_node *head_due,
			t_node *head_tre, char **arr);
int		exit_free(t_node *head_uno, t_node *head_due,
			t_node *head_tre, char **arr);

t_node	*cdl_lst_create_node(t_node **head, t_node *node, int input);
int		cdl_lst_nb_elements(t_node *head);
void	cdl_lst_add_node_next(t_node **head, int input);
void	cdl_lst_add_node_prev(t_node **head, int input);

void	attach_node(t_node **head, t_node *node);
t_node	*detach_node(t_node **head, t_node *node);
void	op_pa(t_push_swap *stack);
void	op_pb(t_push_swap *stack);

void	swap(t_node **head);
void	op_sa(t_push_swap *stack);
void	op_sb(t_push_swap *stack);
void	op_ss(t_push_swap *stack);

void	rotate(t_node **head);
void	op_ra(t_push_swap *stack);
void	op_rb(t_push_swap *stack);
void	op_rr(t_push_swap *stack);

void	rev_rotate(t_node **head);
void	op_rra(t_push_swap *stack);
void	op_rrb(t_push_swap *stack);
void	op_rrr(t_push_swap *stack);

int		find_biggest_num(t_node *head);
int		find_smallest_num(t_node *head);
t_node	*find_smallest_num_node(t_node *head);
int		find_nearest_direction_to_head(t_node *head,
			t_node *node, int *distance);
t_node	*find_longest_chain(t_node *head, int *length);
t_node	*find_longest_sorted_chain(t_node *head, int *length);
t_node	*find_place(t_node *head, t_node *node);

void	double_rotate_direction_next(t_push_swap *stack, t_node *node_b);
void	double_rotate_direction_prev(t_push_swap *stack, t_node *node_b);
void	rotate_a_up_b_down(t_push_swap *stack, t_node *node_b);
void	rotate_b_up_a_down(t_push_swap *stack, t_node *node_b);
void	rotate_shortest_direction_a(t_push_swap *stack, t_node *node);
void	rotate_a_to_smallest_num(t_push_swap *stack);

void	push_a_to_b_in_chunks(t_push_swap *stack);
void	push_all_chunks(t_push_swap *stack);

void	get_index(t_node *head);
void	calculate_moves_loop(t_push_swap *stack);
t_node	*find_node_with_least_moves(t_push_swap *stack);
void	smart_push_back_to_a(t_push_swap *stack);

void	sort_two(t_push_swap *stack);
void	sort_three(t_push_swap *stack);
void	sort_five(t_push_swap *stack);

void	checker(t_push_swap *stack, int argc, char **argv);

#endif
