/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fblin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:34:38 by fblin             #+#    #+#             */
/*   Updated: 2015/12/18 17:36:50 by fblin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				ret;
	unsigned char	*str1;
	unsigned char	*str2;

	ret = 0;
	if (n)
	{
		str1 = (unsigned char *)s1;
		str2 = (unsigned char *)s2;
		while (*str1 && *str2 && --n)
		{
			if (*str1 != *str2)
				return (*str1 - *str2);
			str1++;
			str2++;
		}
		ret = *str1 - *str2;
	}
	return (ret);
}
