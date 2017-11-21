/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fblin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 21:24:11 by fblin             #+#    #+#             */
/*   Updated: 2016/01/24 11:07:53 by fblin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *ret;

	ret = NULL;
	if (s1 || s2)
	{
		if (!s1)
			return (ft_strdup(s2));
		if (!s2)
			return (ft_strdup(s1));
		if (!(ret = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (NULL);
		ret = ft_strcpy(ret, s1);
		ret = ft_strcat(ret, s2);
	}
	return (ret);
}
