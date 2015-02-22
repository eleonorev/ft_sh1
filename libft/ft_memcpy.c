/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evoisin <evoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 20:46:05 by evoisin           #+#    #+#             */
/*   Updated: 2014/08/20 00:00:34 by evoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t		i;
	char		*dest2;
	const char	*src2;

	dest2 = s1;
	src2 = s2;
	i = 0;
	while (n > i)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest2);
}
