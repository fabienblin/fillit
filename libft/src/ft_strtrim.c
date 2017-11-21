/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fblin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 22:34:24 by fblin             #+#    #+#             */
/*   Updated: 2015/12/14 12:05:47 by fblin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhite(char c)
{
	return (c == ' ' || c == '\f' || c == '\n' ||
			c == '\r' || c == '\t' || c == '\v');
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	char	*s_origin;
	char	*s_end;

	str = NULL;
	if (s)
	{
		s_origin = (char *)s;
		s_end = (char *)s + ft_strlen(s) - 1;
		while (ft_iswhite(*s_origin) || ft_iswhite(*s_end))
		{
			if (ft_iswhite(*s_origin))
				s_origin++;
			if (ft_iswhite(*s_end))
				s_end--;
		}
		if (s_origin <= s_end)
		{
			if (!(str = ft_strsub(s, (s_origin - s), (s_end - s_origin + 1))))
				return (NULL);
		}
		else
			str = s_origin;
	}
	return (str);
}
