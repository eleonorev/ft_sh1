/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evoisin <evoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/21 15:00:47 by evoisin           #+#    #+#             */
/*   Updated: 2014/08/21 16:28:00 by evoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char *str1, char *str2)
{
	char	*new_str;

	if (str1 && str2)
	{
		new_str = ft_strnew(ft_strlen(str1) + ft_strlen(str2));
		if (new_str)
		{
			ft_strcpy(new_str, str1);
			ft_strcat(new_str, str2);
		}
		return (new_str);
	}
	return (NULL);
}
