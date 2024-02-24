/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_chain.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:46:01 by afrasch           #+#    #+#             */
/*   Updated: 2021/12/04 12:55:15 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Helper function to find_longest_chain.
   Counts up through next ascending chain and
   compares the length with the last result. */
static void	count_chain_length(t_node *temp,
	t_node **start_last_longest, int *last_longest)
{
	t_node	*start_current_longest;
	int		current_longest;

	start_current_longest = *start_last_longest;
	current_longest = 1;
	while (1)
	{
		if (temp->next->content > temp->content
			&& temp->prev->content > temp->content)
			start_current_longest = temp;
		if (temp->next->content > temp->content)
		{
			current_longest++;
			temp = temp->next;
		}
		else
		{
			if (current_longest > *last_longest)
				*start_last_longest = start_current_longest;
			if (current_longest > *last_longest)
				*last_longest = current_longest;
			current_longest = 1;
			break ;
		}
	}
}

/* Returns a pointer to the start of the longest ascending chain of numbers.
   Takes the address of an int to store the length of the chain.
   Loops twice through the stack, so it also finds a chain passing the head */
t_node	*find_longest_chain(t_node *head, int *length)
{
	int		last_longest;
	t_node	*start_last_longest;
	t_node	*temp;
	t_node	*temp2;

	last_longest = 1;
	temp = head;
	temp2 = temp;
	start_last_longest = temp;
	while (1)
	{
		while (1)
		{
			count_chain_length(temp, &start_last_longest, &last_longest);
			temp = temp->next;
			if (temp == head)
				break ;
		}
		temp2 = temp2->next;
		if (temp2 == temp)
			break ;
	}
	*length = last_longest;
	return (start_last_longest);
}

/* Helper function to find_longest_sorted_chain.
   Counts up through next sorted chain and
   compares the length with the last result. */
static void	count_sorted_chain_length(t_node *temp,
	t_node **start_last_longest, int *last_longest)
{
	t_node	*start_current_longest;
	int		current_longest;

	start_current_longest = *start_last_longest;
	current_longest = 1;
	while (1)
	{
		if ((temp->next->content - temp->content) == 1
			&& (temp->content - temp->prev->content) != 1)
			start_current_longest = temp;
		if ((temp->next->content - temp->content) == 1)
		{
			current_longest++;
			temp = temp->next;
		}
		else
		{
			if (current_longest >= *last_longest)
				*start_last_longest = start_current_longest;
			if (current_longest >= *last_longest)
				*last_longest = current_longest;
			current_longest = 1;
			break ;
		}
	}
}

/* Returns a pointer to the start of the longest sorted chain of numbers.
   Takes an int pointer that stores the length of the chain.
   Loops twice through the stack, so it also finds a chain passing the head. */
t_node	*find_longest_sorted_chain(t_node *head, int *length)
{
	int		last_longest;
	t_node	*start_last_longest;
	t_node	*temp;
	t_node	*temp2;

	last_longest = 1;
	temp = head;
	temp2 = temp;
	start_last_longest = temp;
	while (1)
	{
		while (1)
		{
			count_sorted_chain_length(temp, &start_last_longest, &last_longest);
			temp = temp->next;
			if (temp == head)
				break ;
		}
		temp2 = temp2->next;
		if (temp2 == temp)
			break ;
	}
	*length = last_longest;
	return (start_last_longest);
}
