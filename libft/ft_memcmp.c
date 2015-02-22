/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evoisin <evoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 11:54:16 by evoisin           #+#    #+#             */
/*   Updated: 2013/12/01 00:07:12 by evoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*blop1;
	const unsigned char	*blop2;

	blop1 = s1;
	blop2 = s2;
	while (n > 0)
	{
		if (*blop1 != *blop2)
			return ((int)(*blop1 - *blop2));
		blop1++;
		blop2++;
		n--;
	}
	return (0);
}
