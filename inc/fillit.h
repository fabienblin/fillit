/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/17 11:14:57 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 13:45:59 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft.h"
# define EXIT ft_exit("error")
# define SIZE env->grid_size
# define BUFFSIZE 20

typedef	struct	s_env
{
	int		grid_size;
	char	**grid;
	t_list	*tetri_lst;
}				t_env;

typedef struct	s_tetri
{
	char	**data;
	char	order;
	int		x;
	int		y;
}				t_tetri;

t_list			*ft_getlst(t_list *lst, int i);
int				ft_increment_grid(t_env *env);
int				ft_set_tetri_origin(char *data);
int				ft_set_tetri_end(char *data);
t_env			*ft_new_env(void);
void			ft_test_input(char *file_name);
void			ft_set_env(t_env *env, char *file_name);
int				ft_solve(t_env *env);
void			ft_print_solution(t_env *env);
t_list			*ft_save_tetriminos(char *file_name);
char			**ft_new_grid(int y, int x);

#endif
