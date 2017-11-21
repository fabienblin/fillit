/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fblin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:48:39 by fblin             #+#    #+#             */
/*   Updated: 2015/12/13 15:06:57 by fblin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	s_len;

	s_len = (size_t)ft_strlen(s1);
	if (!(dup = (char *)malloc(sizeof(char) * (s_len + 1))))
		return (NULL);
	dup[s_len] = 0;
	dup = ft_strcpy(dup, s1);
	return (dup);
}
