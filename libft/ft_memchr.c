/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evoisin <evoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 11:12:35 by evoisin           #+#    #+#             */
/*   Updated: 2015/01/02 23:11:20 by evoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*s1;

	i = 0;
	s1 = (const unsigned char *)s;
	while (i < n && (unsigned char *)s)
	{
		if (s1[i] == (unsigned char)c)
			return ((void *)(s1 + i));
		else
			i++;
	}
	return (NULL);
}
