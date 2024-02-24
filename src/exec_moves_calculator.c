/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_moves_calculator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:32:34 by afrasch           #+#    #+#             */
/*   Updated: 2021/12/04 15:54:52 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Iterates through stack b and calculates the best moves for every node. */
static void	the_ultimate_moves_calculator(t_push_swap *stack)
{
	get_index(stack->head_a);
	get_index(stack->head_b);
	calculate_moves_loop(stack);
}

/* Looks if double rotations are possible or not.
   Calls rotate functions for both stacks accordingly.
   Pushes node_b to its place in stack a. */
static void	execute_rotation_and_push(t_push_swap *stack)
{
	t_node	*the_one;

	the_one = find_node_with_least_moves(stack);
	if (the_one->best_combi == BOTH_DOWN)
		double_rotate_direction_next(stack, the_one);
	else if (the_one->best_combi == BOTH_UP)
		double_rotate_direction_prev(stack, the_one);
	else if (the_one->best_combi == A_UP_B_DOWN)
		rotate_a_up_b_down(stack, the_one);
	else if (the_one->best_combi == A_DOWN_B_UP)
		rotate_b_up_a_down(stack, the_one);
	op_pa(stack);
}

/* My big_sort function.
   Calls the funcions for finding the best moves and executing them
   until stack b is empty. */
void	smart_push_back_to_a(t_push_swap *stack)
{
	while (cdl_lst_nb_elements(stack->head_b) > 0)
	{
		the_ultimate_moves_calculator(stack);
		execute_rotation_and_push(stack);
	}
	rotate_a_to_smallest_num(stack);
}
