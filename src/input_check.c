/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:42:56 by afrasch           #+#    #+#             */
/*   Updated: 2021/12/06 12:59:28 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Checks if the list that head is pointing to is sorted.
   Returns the respective macro (YES, sorted: 1, NO, not sorted: -1). */
int	is_sorted(t_node **head)
{
	t_node	*temp;

	if (*head == NULL || head == NULL || (*head)->next == *head)
		return (YES);
	temp = (*head);
	while (temp->next != (*head))
	{
		if (temp->next->content > temp->content)
			temp = temp->next;
		else
			return (NO);
	}
	return (YES);
}

/* Checks if the list that head is pointing to is reverse sorted.
   Returns the respective macro
   (YES (reverse sorted) = 1. NO (not reverse sorted) = -1). */
int	is_rev_sorted(t_node **head)
{
	t_node	*temp;

	if (*head == NULL || head == NULL || (*head)->next == *head)
		return (YES);
	temp = (*head);
	if (temp->next->content > temp->content)
		return (NO);
	if (cdl_lst_nb_elements(*head) == 2)
		return (YES);
	while (1)
	{
		while (temp->next->content < temp->content)
			temp = temp->next;
		if (temp == *head)
			break ;
		else
			return (NO);
	}
	return (YES);
}

/* Checks if there are any duplicate numbers in the input.
   Calls put_error when it finds one. */
void	check_for_dups(t_push_swap *stack)
{
	t_node	*temp;
	t_node	*temp2;

	temp = stack->input_head;
	while (temp)
	{
		temp2 = temp;
		while (temp2)
		{
			temp2 = temp2->next;
			if (temp2 == temp)
				break ;
			if (temp2->content == temp->content)
				put_error(stack->input_head, NULL, NULL, NULL);
		}
		temp = temp->next;
		if (temp == stack->input_head)
			break ;
	}
}

/* Iterates through argv's. Splits them in case there are several numbers
   in one string (in case argv looks like "..."). Checks for valid input
   (only integers and no duplicates). Creates a stack with one node per
   input number, first one at the top, adding to the bottom. */
void	check_input_and_create_stack(t_push_swap *stack, int argc, char **argv)
{
	int		error;
	int		i;
	int		j;
	int		input;
	char	**arr;

	i = 1;
	error = 1;
	while (i < argc)
	{
		arr = ft_split(argv[i], ' ');
		if (!arr || !arr[0])
			put_error(NULL, NULL, stack->input_head, arr);
		j = 0;
		while (arr[j])
		{
			input = ft_atoi(arr[j], &error);
			if (error == -1)
				put_error(stack->input_head, NULL, NULL, arr);
			cdl_lst_add_node_prev(&stack->input_head, input);
			j++;
		}
		i++;
		ft_free_array(arr);
	}
}
