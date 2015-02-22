/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evoisin <evoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/09 19:42:38 by evoisin           #+#    #+#             */
/*   Updated: 2014/09/28 18:52:08 by evoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *str, const char *to_find)
{
	int		x;
	int		y;
	char	*s1;

	s1 = (char *)str;
	x = 0;
	y = 0;
	if (to_find[0] == '\0')
		return (s1);
	while (str[x] != '\0')
	{
		while (str[x] == to_find[y] && str[x] != '\0')
		{
			x++;
			y++;
		}
		if (to_find[y] == '\0')
			return (&s1[x - y]);
		x = x - y;
		y = 0;
		x++;
	}
	return (0);
}
