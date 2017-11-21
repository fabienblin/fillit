/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fblin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:11:19 by fblin             #+#    #+#             */
/*   Updated: 2015/12/13 14:31:15 by fblin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	char			*ret_origin;
	unsigned int	i;

	if (!(ret = ft_strnew(ft_strlen(s))))
		return (NULL);
	ret_origin = ret;
	i = 0;
	while (*s)
		*ret++ = f(i++, *s++);
	return (ret_origin);
}
