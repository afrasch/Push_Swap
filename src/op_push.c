/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:08:10 by afrasch           #+#    #+#             */
/*   Updated: 2021/12/06 15:24:52 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Takes the first element at the top of a and puts it at the top of b.
   Does nothing if a is empty. */
void	op_pb(t_push_swap *stack)
{
	if (stack->head_a != NULL)
	{
		attach_node(&stack->head_b, detach_node(&stack->head_a, stack->head_a));
		write(STDOUT_FILENO, "pb\n", 3);
	}
}

/* Takes the first element at the top of b and puts it at the top of a.
   Does nothing if b is empty. */
void	op_pa(t_push_swap *stack)
{
	if (stack->head_b != NULL)
	{
		attach_node(&stack->head_a, detach_node(&stack->head_b, stack->head_b));
		write(STDOUT_FILENO, "pa\n", 3);
	}
}

/* Attaches node to the stack where head points to.
   If there is no second stack yet, node will point to itself. */
void	attach_node(t_node **head, t_node *node)
{
	if ((*head) == NULL)
	{
		node->next = node;
		node->prev = node;
	}
	else
	{
		(*head)->prev->next = node;
		node->prev = (*head)->prev;
		(*head)->prev = node;
		node->next = (*head);
	}
	(*head) = node;
}

/* Detaches the first node from the stack where head points to.
   node is the head node that needs to be detached.
   Returns the detached node. Flo */
t_node	*detach_node(t_node **head, t_node *node)
{
	node->next->prev = node->prev;
	node->prev->next = node->next;
	if (*head == node && (*head)->next == *head)
		*head = NULL;
	else if (*head == node)
		*head = node->next;
	return (node);
}
