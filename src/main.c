/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:51:15 by afrasch           #+#    #+#             */
/*   Updated: 2021/12/06 15:24:41 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Takes argc and argv and passes them on to push_swap.
   Directly returns if there is no or one argument. */
int	main(int argc, char **argv)
{
	t_push_swap	stack;

	if (argc == 1)
		return (0);
	push_swap(&stack, argc, argv);
	return (0);
}
