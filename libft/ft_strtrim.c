/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evoisin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 23:18:33 by evoisin           #+#    #+#             */
/*   Updated: 2015/01/02 23:19:05 by evoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	int			i;
	int			j;
	char		*strim;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s) - 1;
	while (ft_isblank(s[i]) && s[i] != '\0')
		i++;
	while (j > -1 && ft_isblank(s[j]))
		j--;
	if (j < 0)
		return (ft_strdup(""));
	strim = ft_strsub(s, i, (j + 1 - i));
	return (strim);
}
