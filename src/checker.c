/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:01:39 by afrasch           #+#    #+#             */
/*   Updated: 2021/12/06 15:31:53 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Compares next_line if it's a rotation symbol, performs the operation.
   Puts an error if input is none of the operations. */
static void	match_op_rotation(t_push_swap *stack, char *next_line)
{
	if (ft_strcmp(next_line, "ra\n") == 0)
		rotate(&stack->head_a);
	else if (ft_strcmp(next_line, "rb\n") == 0)
		rotate(&stack->head_b);
	else if (ft_strcmp(next_line, "rra\n") == 0)
		rev_rotate(&stack->head_a);
	else if (ft_strcmp(next_line, "rrb\n") == 0)
		rev_rotate(&stack->head_b);
	else if (ft_strcmp(next_line, "rrr\n") == 0)
	{
		rev_rotate(&stack->head_b);
		rev_rotate(&stack->head_a);
	}
	else if (ft_strcmp(next_line, "rr\n") == 0)
	{
		rotate(&stack->head_b);
		rotate(&stack->head_a);
	}
	else
		put_error(stack->head_a, stack->head_b, stack->input_head, NULL);
}

/* Compares next_line if it's the symbol for swap or push, performs
   the operations. Goes on to part two, if it's none of them. */
static void	match_op_push_swap(t_push_swap *stack, char *next_line)
{
	if (ft_strcmp(next_line, "pa\n") == 0)
		attach_node(&stack->head_a, detach_node(&stack->head_b, stack->head_b));
	else if (ft_strcmp(next_line, "pb\n") == 0)
		attach_node(&stack->head_b, detach_node(&stack->head_a, stack->head_a));
	else if (ft_strcmp(next_line, "sa\n") == 0)
		swap(&stack->head_a);
	else if (ft_strcmp(next_line, "sb\n") == 0)
		swap(&stack->head_b);
	else if (ft_strcmp(next_line, "ss\n") == 0)
	{
		swap(&stack->head_a);
		swap(&stack->head_b);
	}
	else
		match_op_rotation(stack, next_line);
}

/* Takes one of the heads of the lists or a pointer to arr and frees them
   respectively. (Pass NULL to what should not be freed.)
   Exits the programme with 1 (EXIT_FAILURE). */
static int	checker_put_ko(t_node *head_uno, t_node *head_due, t_node *head_tre)
{
	ft_putendl_fd("KO", STDERR_FILENO);
	if (head_uno != NULL)
		free_list(&head_uno);
	if (head_due != NULL)
		free_list(&head_due);
	if (head_tre != NULL)
		free_list(&head_tre);
	exit(EXIT_FAILURE);
}

void	checker(t_push_swap *stack, int argc, char **argv)
{
	char	*next_line;

	check_input_and_create_stack(stack, argc, argv);
	check_for_dups(stack);
	ranker(stack);
	stack->argc = cdl_lst_nb_elements(stack->head_a) + 1;
	while (1)
	{
		next_line = get_next_line(STDIN_FILENO);
		if (next_line == NULL)
			break ;
		match_op_push_swap(stack, next_line);
	}
	if (is_sorted(&stack->head_a) == YES
		&& cdl_lst_nb_elements(stack->head_b) == 0)
	{
		ft_putendl_fd("OK", STDOUT_FILENO);
		exit_free(stack->head_a, stack->head_b, stack->input_head, NULL);
	}
	else
		checker_put_ko(stack->input_head, stack->head_a, stack->head_b);
}

int	main(int argc, char **argv)
{
	t_push_swap	stack;

	if (argc == 1)
		return (0);
	checker(&stack, argc, argv);
	return (0);
}
