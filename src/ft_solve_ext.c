/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_solve_ext.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 13:44:18 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 13:45:26 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_getlst(t_list *lst, int i)
{
	t_list	*getlst;
	int		j;

	getlst = lst;
	j = 0;
	while (j < i)
	{
		getlst = getlst->next;
		j++;
	}
	return (getlst);
}

int		ft_increment_grid(t_env *env)
{
	char	**new_grid;
	char	**old_grid;
	int		new_size;
	int		old_size;

	old_size = env->grid_size;
	new_size = old_size + 1;
	if (!(new_grid = ft_new_grid(new_size, new_size)))
		return (0);
	old_grid = env->grid;
	env->grid = new_grid;
	env->grid_size = new_size;
	while (old_size--)
	{
		free(*old_grid++);
	}
	old_grid = NULL;
	return (1);
}