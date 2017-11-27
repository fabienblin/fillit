/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_set_tetri_ext.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 13:40:11 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 13:40:53 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_set_tetri_origin(char *data)
{
	int	xorigin;
	int	yorigin;
	int	i;

	xorigin = 4;
	yorigin = 3;
	i = 0;
	while (i < 20)
	{
		if (data[i] == '#')
		{
			if (i % 5 < xorigin)
				xorigin = i % 5;
			if (i / 5 < yorigin)
				yorigin = i / 5;
		}
		i++;
	}
	return (xorigin + 5 * yorigin);
}

int		ft_set_tetri_end(char *data)
{
	int xend;
	int yend;
	int i;

	xend = 0;
	yend = 0;
	i = 0;
	while (i < 20)
	{
		if (data[i] == '#')
		{
			if (i % 5 > xend)
				xend = i % 5;
			if (i / 5 > yend)
				yend = i / 5;
		}
		i++;
	}
	return (xend + 5 * yend);
}