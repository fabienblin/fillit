/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fblin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 11:52:54 by fblin             #+#    #+#             */
/*   Updated: 2017/11/15 15:58:42 by fablin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *content, size_t content_size)
{
	free(content);
	(void)content_size;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*lstmap;

	if (!lst || !f)
		return (NULL);
	if (!(newlst = ft_lstdup(lst)))
		return (NULL);
	ft_lstdel(&lst, del);
	lstmap = newlst;
	while (newlst)
	{
		if (!(newlst = f(newlst)))
			return (NULL);
		newlst = newlst->next;
	}
	return (lstmap);
}
