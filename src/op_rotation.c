/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:48:46 by afrasch           #+#    #+#             */
/*   Updated: 2021/12/06 15:25:06 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* The first element of stack a becomes the last. */
void	op_ra(t_push_swap *stack)
{
	rotate(&stack->head_a);
	write(STDOUT_FILENO, "ra\n", 3);
}

/* The first element of stack b becomes the last. */
void	op_rb(t_push_swap *stack)
{
	rotate(&stack->head_b);
	write(STDOUT_FILENO, "rb\n", 3);
}

/* The first elements of both stack a and stack b become the last. */
void	op_rr(t_push_swap *stack)
{
	rotate(&stack->head_a);
	rotate(&stack->head_b);
	write(STDOUT_FILENO, "rr\n", 3);
}

/* Rotates the stack in a way, that the first element becomes the last. */
void	rotate(t_node **head)
{
	if (*head == NULL || head == NULL)
		return ;
	(*head) = (*head)->next;
}
