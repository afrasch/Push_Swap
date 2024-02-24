/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:45:02 by afrasch           #+#    #+#             */
/*   Updated: 2021/12/04 12:59:07 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Checks in a from a given node which direction to head is closer and rotates
   accordingly till node is head. */
void	rotate_shortest_direction_a(t_push_swap *stack, t_node *node)
{
	int	distance;

	distance = 1;
	while (1)
	{
		if (node == stack->head_a)
			break ;
		if (find_nearest_direction_to_head(stack->head_a, node, &distance)
			== NEXT_IS_CLOSER)
			op_rra(stack);
		else
			op_ra(stack);
	}
}

/* Reverse rotates both stacks till node_a and node_b are heads,
	using rrr as long as possible. */
void	double_rotate_direction_next(t_push_swap *stack, t_node *node_b)
{
	while (1)
	{
		if (node_b == stack->head_b || node_b->partner == stack->head_a)
			break ;
		op_rrr(stack);
	}
	if (node_b == stack->head_b)
	{
		while (node_b->partner != stack->head_a)
			op_rra(stack);
	}
	else if (node_b->partner == stack->head_a)
	{
		while (node_b != stack->head_b)
			op_rrb(stack);
	}
}

/* Rotates both stacks till node_a and node_b are heads,
	using rr as long as possible. */
void	double_rotate_direction_prev(t_push_swap *stack, t_node *node_b)
{
	while (1)
	{
		if (node_b == stack->head_b || node_b->partner == stack->head_a)
			break ;
		op_rr(stack);
	}
	if (node_b == stack->head_b)
	{
		while (node_b->partner != stack->head_a)
			op_ra(stack);
	}
	else if (node_b->partner == stack->head_a)
	{
		while (node_b != stack->head_b)
			op_rb(stack);
	}
}

void	rotate_a_up_b_down(t_push_swap *stack, t_node *node_b)
{
	while (node_b->partner != stack->head_a)
		op_ra(stack);
	while (node_b != stack->head_b)
		op_rrb(stack);
}

void	rotate_b_up_a_down(t_push_swap *stack, t_node *node_b)
{
	while (node_b->partner != stack->head_a)
		op_rra(stack);
	while (node_b != stack->head_b)
		op_rb(stack);
}
