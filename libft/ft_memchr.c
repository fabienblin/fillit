/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fblin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:22:08 by fblin             #+#    #+#             */
/*   Updated: 2015/12/01 03:29:43 by fblin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	car;
	unsigned char	*str;

	i = 0;
	car = (unsigned char)c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == car)
			return ((void *)str + i);
		i++;
	}
	return (NULL);
}
