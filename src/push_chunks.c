/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:06:40 by afrasch           #+#    #+#             */
/*   Updated: 2021/12/03 21:58:05 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	check_if_chunks_pushed(t_node *node, int chunk)
{
	t_node	*temp;

	temp = node;
	while (1)
	{
		if (temp->chunk == chunk || temp->chunk == chunk + 1)
			return (NO);
		temp = temp->next;
		if (temp == node)
			break ;
	}
	return (YES);
}

static void	push_chunk(t_push_swap *stack, int chunk)
{
	while (check_if_chunks_pushed(stack->head_a, chunk) == NO)
	{
		if (stack->head_a->chunk == chunk)
			op_pb(stack);
		else if (stack->head_a->chunk == chunk + 1)
		{
			op_pb(stack);
			op_rb(stack);
		}
		else
			op_ra(stack);
	}
}

void	push_all_chunks(t_push_swap *stack)
{
	push_chunk(stack, 1);
	push_chunk(stack, 3);
	push_chunk(stack, 5);
	push_chunk(stack, 7);
}
