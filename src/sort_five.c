/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:21:45 by afrasch           #+#    #+#             */
/*   Updated: 2021/12/04 15:52:05 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Finds the partner node for head_b, rotates there in a and pushes
   until b is empty. Rotates a back to smallest number in the end. */
static void	insertion_sort(t_push_swap *stack)
{
	t_node	*temp;

	while (cdl_lst_nb_elements(stack->head_b) > 0)
	{
		temp = find_place(stack->head_a, stack->head_b);
		rotate_shortest_direction_a(stack, temp);
		op_pa(stack);
	}
	rotate_a_to_smallest_num(stack);
}

/* Checks for increasing chains with length 3 or 4. */
static int	check_for_chains(t_push_swap *stack)
{
	t_node	*temp;
	int		length;

	temp = find_longest_sorted_chain(stack->head_a, &length);
	if (length == 3)
	{
		rotate_shortest_direction_a(stack, temp->prev->prev);
		op_sa(stack);
		rotate_a_to_smallest_num(stack);
		return (YES);
	}
	else
	{
		temp = find_longest_chain(stack->head_a, &length);
		if (length == 4)
		{
			rotate_shortest_direction_a(stack, temp->prev);
			op_pb(stack);
			insertion_sort(stack);
			rotate_a_to_smallest_num(stack);
			return (YES);
		}
	}
	return (NO);
}

/* Pushes the two smallest numbers to b, calls sort_three and pushes back. */
void	sort_five(t_push_swap *stack)
{
	if (stack->argc <= 4)
		return (sort_three(stack));
	if (check_for_chains(stack) == YES)
		return ;
	while (cdl_lst_nb_elements(stack->head_a) > 3)
	{
		while (1)
		{
			if (find_smallest_num_node(stack->head_a) == stack->head_a)
				break ;
			rotate_a_to_smallest_num(stack);
		}
		if (is_sorted(&stack->head_a) == YES)
			break ;
		op_pb(stack);
	}
	sort_three(stack);
	if (stack->argc <= 4)
		return ;
	while (cdl_lst_nb_elements(stack->head_a) < stack->argc - 1)
		op_pa(stack);
}
