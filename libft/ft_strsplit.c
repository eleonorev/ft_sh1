/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evoisin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 23:24:03 by evoisin           #+#    #+#             */
/*   Updated: 2015/01/02 23:30:10 by evoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*create_chain(char *s, int c, int *idx)
{
	char	*result;
	int		i;

	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
		i++;
	result = (char*)malloc(i);
	i = -1;
	while (s[++i] != c && s[i] != '\0')
		result[i] = s[i];
	(*idx) = i;
	return (result);
}

char	**recurs(char *s, int c, int i)
{
	char	**tab;
	char	*data;
	int		idx;

	idx = 0;
	data = create_chain(s, c, &idx);
	while (s[idx] == c)
		idx++;
	if (s[idx] == '\0')
	{
		tab = (char**)malloc(sizeof(char*) * (i + 2));
		tab[i + 1] = '\0';
	}
	else
		tab = recurs(&s[idx], c, i + 1);
	tab[i] = data;
	return (tab);
}

char	**ft_strsplit(const char *s, int c)
{
	int		i;

	i = 0;
	if (s == NULL || c == 0)
		return (NULL);
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		return (NULL);
	return (recurs((char*)(s + i), c, 0));
}
