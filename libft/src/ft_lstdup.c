/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fablin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 09:40:36 by fablin            #+#    #+#             */
/*   Updated: 2017/11/15 13:33:15 by fablin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *lst)
{
	t_list	*new;
	t_list	*lstdup;

	new = NULL;
	lstdup = NULL;
	while (lst)
	{
		if (!(new = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		ft_lstadd(&lstdup, new);
		lst = lst->next;
	}
	return (lstdup);
}
