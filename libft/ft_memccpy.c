/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evoisin <evoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 04:36:37 by evoisin           #+#    #+#             */
/*   Updated: 2015/01/02 23:15:03 by evoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char		*convert_s1;
	unsigned char		*convert_s2;
	size_t				i;

	i = 0;
	convert_s1 = s1;
	convert_s2 = (unsigned char *)s2;
	while (n--)
	{
		convert_s1[i] = convert_s2[i];
		if (convert_s2[i] == (unsigned char)c)
		{
			i++;
			return (convert_s1 + i);
		}
		i++;
	}
	return (NULL);
}
