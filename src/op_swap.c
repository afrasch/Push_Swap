/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:17:53 by afrasch           #+#    #+#             */
/*   Updated: 2021/12/06 15:25:15 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Swaps first two elements of stack a. */
void	op_sa(t_push_swap *stack)
{
	if (stack->head_a != NULL && stack->head_a->next != stack->head_a)
	{
		swap(&stack->head_a);
		write(STDOUT_FILENO, "sa\n", 3);
	}
}

/* Swaps first two elements of stack b. */
void	op_sb(t_push_swap *stack)
{
	if (stack->head_b != NULL && stack->head_b->next != stack->head_b)
	{
		swap(&stack->head_b);
		write(STDOUT_FILENO, "sb\n", 3);
	}
}

/* Swaps first two elements of stack a and stack b simultaneously. */
void	op_ss(t_push_swap *stack)
{
	swap(&stack->head_a);
	swap(&stack->head_b);
	write(STDOUT_FILENO, "ss\n", 3);
}

/* Swaps first two elements of the stack where head is pointing to. */
void	swap(t_node **head)
{
	int	temp;

	if (*head == NULL || head == NULL)
		return ;
	temp = (*head)->content;
	(*head)->content = (*head)->next->content;
	(*head)->next->content = temp;
}
