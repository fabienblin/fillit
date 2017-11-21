/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fablin <fablin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:29:51 by fablin            #+#    #+#             */
/*   Updated: 2017/11/17 14:42:38 by fablin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_env	*ft_new_env()
{
	t_env	*new;

	if(!(new = (t_env *)malloc(sizeof(*new))))
		return (NULL);
	new->grid_size = 0;
	new->grid = NULL;
	new->tetri_lst = NULL;
	return (new);
}
