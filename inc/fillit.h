#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "../libft/includes/libft.h"
# define EXIT ft_exit("error")
# define SIZE env->grid_size

#include <stdio.h>

typedef	struct	s_env
{
	int		grid_size;
	char	*grid;
	t_list	*tetri_lst;
}				t_env;

void			ft_test_input(char *file_name);
void			ft_save_tetriminos(char *file_name, t_env *env);
void			ft_solve(t_env *env);
void			ft_print_solution(t_env *env);
int				ft_x_pos(int absolute_pos, t_env *env);
int				ft_y_pos(int absolute_pos, t_env *env);
#endif
