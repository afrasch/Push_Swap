/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_or_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:44:39 by afrasch           #+#    #+#             */
/*   Updated: 2021/12/04 13:02:23 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Simply swaps if input == "2 1". Exits the programme.
   Returns if stack size is greater 2. */
void	sort_two(t_push_swap *stack)
{
	if (stack->argc <= 3)
	{
		if (is_rev_sorted(&stack->head_a) == YES)
			op_sa(stack);
		exit_free(stack->head_a, stack->input_head, NULL, NULL);
	}
	else
		return ;
}

/* An algorithm that sorts three numbers.
   Calls sort_two if input is only two numbers. */
void	sort_three(t_push_swap *stack)
{
	t_node	*temp;

	sort_two(stack);
	if (cdl_lst_nb_elements(stack->head_a) != 3)
		return ;
	temp = stack->head_a;
	if (is_sorted(&temp->next) == YES)
	{
		op_ra(stack);
		return ;
	}
	if ((temp->content < temp->prev->content)
		|| (temp->content > temp->prev->content
			&& temp->content > temp->next->content))
		op_sa(stack);
	if (is_sorted(&temp->next) == YES)
		op_ra(stack);
	if (is_sorted(&temp->prev) == YES)
		op_rra(stack);
}
