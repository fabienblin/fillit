/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fblin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:09:38 by fblin             #+#    #+#             */
/*   Updated: 2015/12/18 17:10:05 by fblin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d >= s && d < s + len && len)
	{
		while (len)
		{
			*(d + len - 1) = *(s + len - 1);
			len--;
		}
	}
	else
		dst = ft_memcpy(dst, src, len);
	return (dst);
}
