/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_solve.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/17 14:39:26 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 13:45:18 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_isvalidpos(char **grid, int pos, t_tetri *tetri, int s)
{
	char	**d;
	int		i;
	int		j;
	int		isvalidpos;

	d = tetri->data;
	isvalidpos = 0;
	i = 0;
	if ((s - pos % s < tetri->x || s - pos / s < tetri->y))
		return (0);
	while (d[i])
	{
		j = 0;
		while (d[i][j])
		{
			if (d[i][j] == '#' && grid[i + pos / s][j + pos % s] == '.')
				isvalidpos++;
			if (d[i][j] == '#' && ft_isalpha(grid[i + pos / s][j + pos % s]))
				return (0);
			j++;
		}
		i++;
	}
	return (isvalidpos == 4 ? 1 : 0);
}

void	ft_place_tetri(char **grid, int pos, t_tetri *tetri, int size)
{
	char	**d;
	int		i;
	int		j;

	d = tetri->data;
	i = 0;
	while (d[i])
	{
		j = 0;
		while (d[i][j])
		{
			if (d[i][j] == '#' && grid[i + pos / size][j + pos % size] == '.')
				grid[i + pos / size][j + pos % size] = tetri->order;
			j++;
		}
		i++;
	}
}

void	ft_remove_tests(char **grid, t_tetri *tetri, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (grid[i][j] >= tetri->order && ft_isalnum(grid[i][j]))
				grid[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		ft_recurse(char **grid, t_list *lst, int size)
{
	int		pos;
	int		volume;
	t_tetri	*tetri;

	if (lst)
	{
		pos = 0;
		volume = size * size;
		tetri = (t_tetri *)lst->content;
		while (pos < volume)
		{
			if (ft_isvalidpos(grid, pos, tetri, size))
			{
				ft_place_tetri(grid, pos, tetri, size);
				if (ft_recurse(grid, lst->next, size) == 0)
					ft_remove_tests(grid, tetri, size);
				else
					return (1);
			}
			pos++;
		}
		return (0);
	}
	return (1);
}

int		ft_solve(t_env *env)
{
	while (ft_recurse(env->grid, env->tetri_lst, env->grid_size) == 0)
	{
		if (!(ft_increment_grid(env)))
			return (0);
	}
	return (1);
}
