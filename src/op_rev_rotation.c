/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:11:29 by afrasch           #+#    #+#             */
/*   Updated: 2021/12/06 15:25:46 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* The last element of stack a becomes the first. */
void	op_rra(t_push_swap *stack)
{
	rev_rotate(&stack->head_a);
	write(STDOUT_FILENO, "rra\n", 4);
}

/* The last element of stack b becomes the first. */
void	op_rrb(t_push_swap *stack)
{
	rev_rotate(&stack->head_b);
	write(STDOUT_FILENO, "rrb\n", 4);
}

/* The last elements of both stack a and stack b become the first. */
void	op_rrr(t_push_swap *stack)
{
	rev_rotate(&stack->head_a);
	rev_rotate(&stack->head_b);
	write(STDOUT_FILENO, "rrr\n", 4);
}

/* Rotates the stack in a way that the last element becomes the first. */
void	rev_rotate(t_node **head)
{
	if (*head == NULL || head == NULL)
		return ;
	(*head) = (*head)->prev;
}
