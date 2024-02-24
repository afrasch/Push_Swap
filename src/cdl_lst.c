/* ************************************************************************ */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdl_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:21:08 by afrasch           #+#    #+#             */
/*   Updated: 2021/11/03 22:30:54 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Allocates space for node. Sets input as content. Returns node. */
t_node	*cdl_lst_create_node(t_node **head, t_node *node, int input)
{
	node = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!node)
		return (free_list(head));
	node->content = input;
	node->next = node;
	node->prev = node;
	return (node);
}

/* Iterates through a stack, counts up and returns the number of elements. */
int	cdl_lst_nb_elements(t_node *head)
{
	int		i;
	t_node	*temp;

	if (head == NULL)
		return (0);
	i = 0;
	temp = head;
	while (1)
	{
		i++;
		temp = temp->next;
		if (temp == head)
			break ;
	}
	return (i);
}

/* Adds a new node at the top of the stack. */
void	cdl_lst_add_node_next(t_node **head, int input)
{
	t_node	*temp;

	temp = NULL;
	temp = cdl_lst_create_node(head, temp, input);
	if ((*head) == NULL)
		(*head) = temp;
	else
	{
		temp->prev = (*head);
		temp->next = (*head)->next;
		(*head)->next->prev = temp;
		if (cdl_lst_nb_elements(*head) == 1)
			(*head)->prev = temp;
		(*head)->next = temp;
		(*head) = temp;
	}
}

/* Adds a new node at the bottom of the stack. */
void	cdl_lst_add_node_prev(t_node **head, int input)
{
	t_node	*temp;

	temp = NULL;
	temp = cdl_lst_create_node(head, temp, input);
	if (head == NULL)
		return ;
	if ((*head) == NULL)
		(*head) = temp;
	else
	{
		temp->prev = (*head)->prev;
		temp->next = (*head);
		temp->prev->next = temp;
		if (cdl_lst_nb_elements(*head) == 1)
			(*head)->next = temp;
		(*head)->prev = temp;
	}
}
