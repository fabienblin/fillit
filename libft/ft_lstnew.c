/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fblin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:24:40 by fblin             #+#    #+#             */
/*   Updated: 2016/02/03 18:43:21 by fblin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(*new))))
		return (NULL);
	new->content = NULL;
	new->content_size = 0;
	if (content)
	{
		new->content = ft_memcpy((void *)malloc(content_size),
				content, content_size);
		if (!new->content)
			return (NULL);
		new->content_size = content_size;
		new->next = NULL;
	}
	return (new);
}
