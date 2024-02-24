/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 22:19:58 by afrasch           #+#    #+#             */
/*   Updated: 2021/12/06 13:16:39 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Iterates through the list with all original input numbers and creates
   a new list with only the respective indices of the input numbers. */
void	ranker(t_push_swap *stack)
{
	t_node	*temp;
	t_node	*temp2;
	int		counter;

	temp2 = stack->input_head;
	while (1)
	{
		counter = 1;
		temp = stack->input_head;
		while (1)
		{
			if (temp->content < temp2->content)
				counter++;
			temp = temp->next;
			if (temp == stack->input_head)
				break ;
		}
		cdl_lst_add_node_prev(&stack->head_a, counter);
		temp2 = temp2->next;
		if (temp2 == stack->input_head)
			break ;
	}
}

/* A programme that sorts a stack of random integers with as least operations
   as possible. Does input check. Creates a doubly linked list with the
   interger ranks. Calls the different algorithms for different stack sizes.
   Checks in the end if sorted. */
int	push_swap(t_push_swap *stack, int argc, char **argv)
{
	check_input_and_create_stack(stack, argc, argv);
	check_for_dups(stack);
	if (is_sorted(&stack->input_head) == YES)
		exit_free(stack->input_head, NULL, NULL, NULL);
	ranker(stack);
	stack->argc = cdl_lst_nb_elements(stack->head_a) + 1;
	if (stack->argc <= 6)
		sort_five(stack);
	else
	{
		push_a_to_b_in_chunks(stack);
		smart_push_back_to_a(stack);
	}
	if (is_sorted(&stack->head_a) == NO)
		put_error(stack->input_head, stack->head_a, stack->head_b, NULL);
	else if (is_sorted(&stack->head_a) == YES)
		exit_free(stack->head_a, stack->head_b, stack->input_head, NULL);
	return (0);
}
