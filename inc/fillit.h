/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fablin <fablin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:14:57 by fablin            #+#    #+#             */
/*   Updated: 2017/11/21 14:16:53 by fablin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft.h"
# define EXIT ft_exit("error")
# define SIZE env->grid_size
# define BUFFSIZE 20

#include <stdio.h>
#include <errno.h>
#include <string.h>

typedef	struct	s_env
{
	int		grid_size;
	char	**grid;
	t_list	*tetri_lst;
}				t_env;

typedef struct	s_tetri
{
	char data[4][4];
	char order;
}				t_tetri;

void			ft_test_input(char *file_name);
void			ft_set_env(t_env *env, char *file_name);
int				ft_solve(t_env *env);
void			ft_print_solution(t_env *env);
int				ft_x_pos(int absolute_pos, t_env *env);
int				ft_y_pos(int absolute_pos, t_env *env);
t_env			*ft_new_env();
t_list			*ft_save_tetriminos(char *file_name);
char			**ft_new_grid(int y, int x);
#endif
