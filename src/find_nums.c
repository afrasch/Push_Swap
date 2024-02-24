/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nums.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:48:17 by afrasch           #+#    #+#             */
/*   Updated: 2021/12/03 22:18:05 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Finds and returns the smallest number on the given stack. */
int	find_smallest_num(t_node *head)
{
	int		num;
	t_node	*temp;

	num = head->content;
	temp = head;
	while (1)
	{
		if (temp->next->content < num)
			num = temp->next->content;
		temp = temp->next;
		if (temp == head)
			break ;
	}
	return (num);
}

/* Finds and returns the biggest number on the given stack. */
int	find_biggest_num(t_node *head)
{
	int		num;
	t_node	*temp;

	num = head->content;
	temp = head;
	while (1)
	{
		if (temp->next->content > num)
			num = temp->next->content;
		temp = temp->next;
		if (temp == head)
			break ;
	}
	return (num);
}

/* Finds and returns the node of the smallest number on the given stack. */
t_node	*find_smallest_num_node(t_node *head)
{
	int		num;
	t_node	*smallest;
	t_node	*temp;

	num = head->content;
	temp = head;
	smallest = temp;
	while (1)
	{
		if (temp->next->content < num)
		{
			smallest = temp->next;
			num = temp->next->content;
		}
		temp = temp->next;
		if (temp == head)
			break ;
	}
	return (smallest);
}
