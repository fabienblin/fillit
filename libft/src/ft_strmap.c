/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fblin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:11:19 by fblin             #+#    #+#             */
/*   Updated: 2017/11/13 18:57:53 by fablin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *ret;
	char *ret_origin;

	if (!(ret = ft_strnew(ft_strlen(s))))
		return (NULL);
	ret_origin = ret;
	while (*s)
	{
		*ret = f(*s);
		ret++;
		s++;
	}
	return (ret_origin);
}
