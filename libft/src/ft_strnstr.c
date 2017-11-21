/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fblin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:56:17 by fblin             #+#    #+#             */
/*   Updated: 2015/11/28 18:49:56 by fblin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	ret = NULL;
	while (i < (int)n && s1[i])
	{
		j = 0;
		while (s1[i] == s2[j] && s2[j] && s1[i] && i < (int)n)
		{
			i++;
			j++;
		}
		i -= j;
		if (!s2[j])
			return ((char *)s1 + i);
		i++;
	}
	if (!*s1 && !*s2)
		ret = (char *)s1;
	return (ret);
}
