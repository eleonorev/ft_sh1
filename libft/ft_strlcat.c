/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evoisin <evoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 19:20:35 by evoisin           #+#    #+#             */
/*   Updated: 2014/08/19 18:18:04 by evoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest;
	size_t	source;

	dest = 0;
	source = 0;
	while (size != 0 && *(dst + dest) != '\0')
	{
		dest++;
		size--;
	}
	if (size == 0)
		return (dest + ft_strlen(src));
	while (*src != '\0')
	{
		if (size != 1)
		{
			*(dst + dest) = *src;
			dst++;
			size--;
		}
		src++;
		source++;
	}
	*(dst + dest) = '\0';
	return (dest + source);
}
