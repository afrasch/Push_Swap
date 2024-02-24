/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 16:41:29 by afrasch           #+#    #+#             */
/*   Updated: 2021/10/25 21:09:45 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Searches for the first occurrence of (typecasted char) c in str */
char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	size_t	l;

	if (!str)
		return (0);
	i = 0;
	l = ft_strlen((char *)str);
	while (i <= l)
	{
		if (str[i] == (unsigned char)c)
			return ((char *)str + i);
		else
			i++;
	}
	return (0);
}
