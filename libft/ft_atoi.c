/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fblin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:51:55 by fblin             #+#    #+#             */
/*   Updated: 2015/12/01 03:25:16 by fblin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_issign(char c)
{
	return (c == '-' || c == '+');
}

static int	ft_iswhite(char c)
{
	return (c == ' ' || c == '\f' || c == '\n' ||
			c == '\r' || c == '\t' || c == '\v');
}

int			ft_atoi(const char *str)
{
	unsigned int	ret;
	int				sign;

	ret = 0;
	sign = 1;
	while (ft_iswhite(*str))
		str++;
	if (ft_issign(*str))
		sign = (*str++ == '-' ? -1 : 1);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return ((int)ret * sign);
		ret = (ret * 10) + (*str - '0');
		str++;
	}
	if (sign == -1)
		return ((int)-ret);
	return ((int)ret);
}
