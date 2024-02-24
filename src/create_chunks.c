/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:23:25 by afrasch           #+#    #+#             */
/*   Updated: 2021/12/06 12:51:31 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	init_chunk_variable(t_push_swap *stack)
{
	t_node	*start;
	t_node	*temp;
	int		length;

	start = find_longest_chain(stack->head_a, &length);
	temp = start;
	while (length > 0)
	{
		start->chunk = 0;
		start = start->next;
		length--;
	}
	while (1)
	{
		if (start == temp)
			break ;
		start->chunk = -1;
		start = start->next;
	}
}

static void	assign_all_nodes_to_six_chunks(t_push_swap *stack, t_node *temp)
{
	int		stacksize;

	stacksize = stack->argc - 1;
	if (temp->content <= stacksize * 0.23)
		temp->chunk = 1;
	if (temp->content <= stacksize * 0.46 && temp->content > stacksize * 0.23)
		temp->chunk = 2;
	if (temp->content <= stacksize * 0.62 && temp->content > stacksize * 0.46)
		temp->chunk = 3;
	if (temp->content <= stacksize * 0.74 && temp->content > stacksize * 0.62)
		temp->chunk = 4;
	if (temp->content <= stacksize * 0.87 && temp->content > stacksize * 0.74)
		temp->chunk = 5;
	if (temp->content <= stacksize && temp->content > stacksize * 0.87)
		temp->chunk = 6;
}

static void	assign_all_nodes_to_four_chunks(t_push_swap *stack, t_node *temp)
{
	int		stacksize;

	stacksize = stack->argc - 1;
	if (temp->content <= stacksize * 0.25)
		temp->chunk = 1;
	if (temp->content <= stacksize * 0.5 && temp->content > stacksize * 0.25)
		temp->chunk = 2;
	if (temp->content <= stacksize * 0.75 && temp->content > stacksize * 0.5)
		temp->chunk = 3;
	if (temp->content <= stacksize && temp->content > stacksize * 0.75)
		temp->chunk = 4;
}

static void	assign_all_nodes_loop(t_push_swap *stack, int option)
{
	t_node	*temp;

	temp = stack->head_a;
	while (1)
	{
		if (temp->chunk != 0)
		{
			if (option == 1)
				assign_all_nodes_to_four_chunks(stack, temp);
			else if (option == 2)
				assign_all_nodes_to_six_chunks(stack, temp);
		}
		temp = temp->next;
		if (temp == stack->head_a)
			break ;
	}
}

void	push_a_to_b_in_chunks(t_push_swap *stack)
{
	init_chunk_variable(stack);
	if (stack->argc <= 300)
		assign_all_nodes_loop(stack, 1);
	else
		assign_all_nodes_loop(stack, 2);
	push_all_chunks(stack);
}
