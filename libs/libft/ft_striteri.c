/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:54:06 by afrasch           #+#    #+#             */
/*   Updated: 2021/10/25 21:09:28 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Applies the function ft to each character of str,
   passing to ft the characters index as first argument. */
void	ft_striteri(char *str, void (*ft)(unsigned int, char*))
{
	unsigned int	i;

	if (!str || !ft)
		return ;
	i = 0;
	while (str[i])
	{
		ft(i, &str[i]);
		i++;
	}
}
