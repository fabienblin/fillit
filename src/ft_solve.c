/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fablin <fablin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:39:26 by fablin            #+#    #+#             */
/*   Updated: 2017/11/21 13:22:41 by fablin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void printflst(t_list *lst) {
	while (lst)
	{
		printf("%c", ((t_tetri *)lst->content)->order);
		lst = lst->next;
	}
	printf("\n");
}

t_list *ft_getlst(t_list *lst, int i)
{
	t_list *getlst;
	int j;

	getlst = lst;
	j = 0;
	while (j < i)
	{
		getlst = getlst->next;
		j++;
	}
	return (getlst);
}

//test toutes les positions de tous les tetri dans une grille de taille fixe
int ft_nassim(t_env *env)
{
	(void)env;
	int	solved;
	solved = 0;
	return (solved);
}

//realloue la grille en incrementant sa taille de 1
int	ft_increment_grid(t_env *env)
{
	char	**new_grid;
	char	**old_grid;
	int		new_size;
	int		old_size;
	
	old_size = env->grid_size;
	new_size = old_size + 1;
	if(!(new_grid = ft_new_grid(new_size, new_size)))
		return (0);
	old_grid = env->grid;
	env->grid = new_grid;
	env->grid_size = new_size;
	//free old_grid
	while(old_size--)
	{
		free(*old_grid++);
	}
	//free(old_grid);
	return(1);
}

int	ft_solve(t_env *env)
{
	//int len = 3;
	(void)env;
	//t_list *lst = env->tetri_lst;
	//char lst[4] = "abc\0";
	//test les tetri et incremente la taille de la grille
	int limit = 5;
	while (ft_nassim(env) == 0 && limit--)
	{
		if(!(ft_increment_grid(env)))
			return (0);
		ft_putstr("grid (");
		ft_putnbr(SIZE);
		ft_putstr(")\n");
		ft_print_solution(env);
	}
	//printflst(lst);
	return (1);
}
