/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evoisin <evoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 22:42:23 by evoisin           #+#    #+#             */
/*   Updated: 2014/09/09 19:45:38 by evoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*mem;

	if (size < 1)
		return (NULL);
	if (!(mem = malloc(sizeof(void) * size)))
		return (0);
	ft_bzero(mem, size);
	return (mem);
}
