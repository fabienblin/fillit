#include "../inc/fillit.h"
#include <stdio.h>

int		main (int argc, char **argv)
{

	t_env	*env;

	if(!(env = ft_new_env()))
		EXIT;
	if (!(argc == 2))
		EXIT;
	ft_test_input(argv[1]);
	ft_set_env(env, argv[1]);

	ft_solve(env);
	//ft_print_solution(env);
	return (0);
}
