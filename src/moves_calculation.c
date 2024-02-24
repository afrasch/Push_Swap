/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_calculation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:34:49 by afrasch           #+#    #+#             */
/*   Updated: 2021/12/04 12:34:37 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Goes through all possiblities of combinations
   and saves the one with least moves. */
static void	get_best_combination(int *combinations, t_node *node_b)
{
	int	i;

	node_b->moves = -1;
	i = 0;
	while (i < 4)
	{
		if (combinations[i] < node_b->moves || node_b->moves == -1)
		{
			node_b->moves = combinations[i];
			node_b->best_combi = i;
		}
		i++;
	}
}

/* Calculates on the basis of the index the moves
   for all four rotation possibilities.
   (both up, both down, one up and one down and the other way round) */
static void	calculate_moves_combinations(t_push_swap *stack,
	t_node *node_a, t_node *node_b)
{
	int	combinations[4];
	int	stacksize[2];

	stacksize[STACK_A] = cdl_lst_nb_elements(stack->head_a);
	stacksize[STACK_B] = cdl_lst_nb_elements(stack->head_b);
	if (node_a->index > node_b->index)
		combinations[BOTH_UP] = node_a->index;
	else
		combinations[BOTH_UP] = node_b->index;
	if ((stacksize[STACK_A] - node_a->index)
		> (stacksize[STACK_B] - node_b->index))
		combinations[BOTH_DOWN] = (stacksize[STACK_A] - node_a->index);
	else
		combinations[BOTH_DOWN] = (stacksize[STACK_B] - node_b->index);
	combinations[A_UP_B_DOWN] = node_a->index
		+ (stacksize[STACK_B] - node_b->index);
	combinations[A_DOWN_B_UP] = (stacksize[STACK_A] - node_a->index)
		+ node_b->index;
	get_best_combination(combinations, node_b);
}

/* Calculates the moves combinations for every node_b and its partner. */
void	calculate_moves_loop(t_push_swap *stack)
{
	t_node	*node_b;

	node_b = stack->head_b;
	while (1)
	{
		node_b->partner = find_place(stack->head_a, node_b);
		calculate_moves_combinations(stack, node_b->partner, node_b);
		node_b = node_b->next;
		if (node_b == stack->head_b)
			break ;
	}
}

/* Give every node in a stack a position index. */
void	get_index(t_node *head)
{
	t_node	*temp;
	int		index_store;

	temp = head;
	index_store = 0;
	while (1)
	{
		temp->index = index_store;
		index_store++;
		temp = temp->next;
		if (temp == head)
			break ;
	}
}

/* Compares the moves for every node in stack b
   and returns the one with least operations. */
t_node	*find_node_with_least_moves(t_push_swap *stack)
{
	t_node	*temp;
	t_node	*the_best;

	temp = stack->head_b;
	the_best = temp;
	while (1)
	{
		if (temp->moves < the_best->moves)
			the_best = temp;
		temp = temp->next;
		if (temp == stack->head_b)
			break ;
	}
	return (the_best);
}
