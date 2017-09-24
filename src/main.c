#include "../inc/fillit.h"
#include <stdio.h>

int		main (int argc, char **argv)
{
	t_env	env;

	ft_bzero(&env, sizeof(t_env));
	if (!(argc == 2))
		EXIT;
	ft_test_input(argv[1]);
	set_env(&env, argv[1]);
	printf("grid_size=%d\ngrid=%s",env.grid_size,env.grid);
	//ft_solve(&env);
	//ft_print_solution(&env);
	return (0);
}
