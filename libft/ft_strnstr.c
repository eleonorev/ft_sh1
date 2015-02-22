/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evoisin <evoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 01:06:04 by evoisin           #+#    #+#             */
/*   Updated: 2014/08/20 00:04:43 by evoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[x] != '\0' && n > 0)
	{
		while (s1[x] == s2[y] && s1[x] != '\0' && n > 0)
		{
			x++;
			y++;
			n--;
		}
		if (s2[y] == '\0')
			return ((char *)&s1[x - y]);
		x = x - y;
		y = 0;
		x++;
		n--;
	}
	return (NULL);
}
