/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 22:16:34 by afrasch           #+#    #+#             */
/*   Updated: 2021/12/04 15:23:14 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Rotating the sorted stack a to smallest num. */
void	rotate_a_to_smallest_num(t_push_swap *stack)
{
	rotate_shortest_direction_a(stack, find_smallest_num_node(stack->head_a));
}

/* Checks from a given node on in which direction head is closer.
   Returns 1 if node is closer to the bottom of the stack,
   2 if it's closer to the top of the stack.
   Counts up the smallest possible distance. */
int	find_nearest_direction_to_head(t_node *head, t_node *node, int *distance)
{
	int	total_length;

	*distance = 0;
	total_length = cdl_lst_nb_elements(head);
	while (1)
	{
		node = node->next;
		(*distance)++;
		if (node == head)
			break ;
	}
	if (*distance <= total_length / 2)
		return (NEXT_IS_CLOSER);
	else
	{
		*distance = total_length - *distance;
		return (PREV_IS_CLOSER);
	}
}

/* Takes a node and the head pointer of a stack.
   In this stack it finds and returns the equivalent node,
   that carries the following number after the input node. */
t_node	*find_next_neighbour(t_node *head, t_node *node)
{
	t_node	*temp;

	temp = head;
	while (1)
	{
		if (temp->content - node->content == 1)
			return (temp);
		temp = temp->next;
		if (temp == head)
			break ;
	}
	return (NULL);
}

/* Finds in the stack a where node belongs inbetween.
   Returns the next node to node. */
t_node	*find_place(t_node *head, t_node *node)
{
	t_node	*temp;

	if (head == NULL)
		return (NULL);
	if (node->content < find_smallest_num(head)
		|| node->content > find_biggest_num(head))
	{
		temp = find_smallest_num_node(head);
		return (temp);
	}
	temp = head;
	while (1)
	{
		if ((temp->content - node->content == 1)
			|| (temp->content > node->content
				&& temp->prev->content < node->content)
			|| (node->content - temp->prev->content == 1))
			break ;
		temp = temp->next;
	}
	return (temp);
}
