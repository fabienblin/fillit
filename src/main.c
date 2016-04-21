#include "../inc/fillit.h"

void	ft_set_test_env(t_env *env)
{
	env->grid_size = 2;
	env->grid = "abcd";
}

int		main (int argc, char **argv)
{
	t_env	env;

	ft_bzero(&env, sizeof(t_env));
	ft_set_test_env(&env);
	if (!(argc == 2))
		EXIT;
	ft_test_input(argv[1]);
	ft_solve(&env);
	ft_print_solution(&env);
	return (0);
}
