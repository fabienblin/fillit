/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fablin <fablin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:39:19 by fablin            #+#    #+#             */
/*   Updated: 2017/11/17 14:42:18 by fablin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_lst_len(t_list *lst)
{
	int i;

	i = 0;
	while(lst)
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
	while(i * i < required)
		i++;
	return (i);
}

char	**ft_new_grid(int y, int x)
{
	char	**grid;
	char	*line;
	int		i;

	if(!(grid = (char **)malloc(y * sizeof(char *))))
		return (NULL);
	i = 0;
	while(i < y)
	{
		if(!(line = (char *)malloc(x * sizeof(char))))
			return (NULL);
		ft_memset(line, '.', x);
		grid[i] = line;
		i++;
	}
	return (grid);
}

void printf_env(t_env *env)
{
	int i;
	int j;
	t_list *l = env->tetri_lst;
	while(l)
	{
		printf("order=%c\n",((t_tetri *)l->content)->order);
		printf("teri=\n");

		for(i = 0; i<4; i++)
		{
			for(j = 0; j<4; j++)
			{
				printf("%c",((t_tetri *)l->content)->data[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		l = l->next;
	}
	printf("grid_size=%d\n", env->grid_size);
	printf("lst_len=%d\n", ft_lst_len(env->tetri_lst));
	printf("grid=\n");
	char**line=env->grid;
	for(i=0; i<env->grid_size; i++)
	{
		printf("%s\n", *line);
		line++;
	}
}

void ft_set_env(t_env *env, char *file_name)
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

	printf_env(env);
}
