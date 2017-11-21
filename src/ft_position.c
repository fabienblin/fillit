/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fablin <fablin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:38:59 by fablin            #+#    #+#             */
/*   Updated: 2017/11/17 14:42:29 by fablin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_x_pos(int absolute_pos, t_env *env)
{
	return (absolute_pos % SIZE);
}

int		ft_y_pos(int absolute_pos, t_env *env)
{
	return (absolute_pos / SIZE);
}
