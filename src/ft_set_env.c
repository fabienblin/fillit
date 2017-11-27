/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_set_env.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/17 14:39:19 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 13:38:34 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

t_env	*ft_new_env(void)
{
	t_env	*new;

	if (!(new = (t_env *)malloc(sizeof(*new))))
		return (NULL);
	new->grid_size = 0;
	new->grid = NULL;
	new->tetri_lst = NULL;
	return (new);
}

int		ft_lst_len(t_list *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int		ft_grid_size(int lst_len)
{
	int required;
	int i;

	required = 4 * lst_len;
	i = 0;
	while (i * i < required)
		i++;
	return (i);
}

char	**ft_new_grid(int y, int x)
{
	char	**grid;
	char	*line;
	int		i;

	if (!(grid = (char **)malloc(y * sizeof(char *) + 1)))
		return (NULL);
	grid[y] = NULL;
	i = 0;
	while (i < y)
	{
		if (!(line = ft_strnew(x)))
			return (NULL);
		ft_memset(line, '.', x);
		grid[i] = line;
		i++;
	}
	return (grid);
}

void	ft_set_env(t_env *env, char *file_name)
{
	int		lst_len;
	int		grid_size;
	char	**grid;
	t_list	*tetri_lst;

	tetri_lst = ft_save_tetriminos(file_name);
	lst_len = ft_lst_len(tetri_lst);
	grid_size = ft_grid_size(lst_len);
	grid = ft_new_grid(grid_size, grid_size);
	env->grid_size = grid_size;
	env->grid = grid;
	env->tetri_lst = tetri_lst;
}
