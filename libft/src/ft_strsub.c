/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fblin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 20:54:39 by fblin             #+#    #+#             */
/*   Updated: 2015/12/13 17:43:50 by fblin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (!(ret = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ret[len] = 0;
	ret = ft_strncpy(ret, &(s[start]), len);
	return (ret);
}
