/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fblin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:42:51 by fblin             #+#    #+#             */
/*   Updated: 2015/11/28 13:01:58 by fblin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	car;
	unsigned char	*d;
	unsigned char	*s;

	car = (unsigned char)c;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (n)
	{
		while (n--)
		{
			*d = *s;
			if (*s == car)
				return ((void *)d + 1);
			d++;
			s++;
		}
	}
	return (NULL);
}
