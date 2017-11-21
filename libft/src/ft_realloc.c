/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fblin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:51:55 by fblin             #+#    #+#             */
/*   Updated: 2017/11/14 16:57:42 by fablin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void **mem, size_t size)
{
	void	*realloc;

	realloc = NULL;
	if (!(realloc = (void *)malloc(size)))
		return (NULL);
	if (*mem)
	{
		ft_memcpy(realloc, *mem, size);
		free(*mem);
		*mem = realloc;
	}
	return (realloc);
}
