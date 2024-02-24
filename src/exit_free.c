/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:53:00 by afrasch           #+#    #+#             */
/*   Updated: 2021/12/06 14:43:13 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Frees every element of the list that head is pointing to. Returns NULL.
   Does not free allocated content. */
void	*free_list(t_node **head)
{
	t_node	*current;
	t_node	*temp;

	if (head == NULL || *head == NULL)
		return (NULL);
	current = (*head)->next;
	while (1)
	{
		temp = current;
		current = current->next;
		if (current == (*head))
		{
			if (current == current->prev)
				free(current);
			else
			{
				free(temp);
				free(current);
			}
			(*head) = NULL;
			break ;
		}
		free(temp);
	}
	return (NULL);
}

/* Takes one of the heads of the lists or a pointer to arr and frees them
   respectively. (Pass NULL to what should not be freed.)
   Writes "Error" to stderr. Exits the programme with 1. */
int	put_error(t_node *head_uno, t_node *head_due, t_node *head_tre, char **arr)
{
	write (STDERR_FILENO, "Error\n", 6);
	if (head_uno != NULL)
		free_list(&head_uno);
	if (head_due != NULL)
		free_list(&head_due);
	if (head_tre != NULL)
		free_list(&head_tre);
	if (arr != NULL)
		ft_free_array(arr);
	exit(EXIT_FAILURE);
}

/* Takes one of the heads of the lists or a pointer to arr and frees them
   respectively. (Pass NULL to what should not be freed.)
   Exits the programme with 0. */
int	exit_free(t_node *head_uno, t_node *head_due, t_node *head_tre, char **arr)
{
	if (head_uno != NULL)
		free_list(&head_uno);
	if (head_due != NULL)
		free_list(&head_due);
	if (head_tre != NULL)
		free_list(&head_tre);
	if (arr != NULL)
		ft_free_array(arr);
	exit(EXIT_SUCCESS);
}
