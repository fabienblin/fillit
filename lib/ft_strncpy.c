/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fblin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:56:52 by fblin             #+#    #+#             */
/*   Updated: 2015/12/06 16:54:40 by fblin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t src_len;

	src_len = ft_strlen(src);
	dst = (char *)ft_memcpy(dst, src, n);
	if (src_len < n)
		ft_bzero(&dst[src_len], n - src_len);
	return (dst);
}
