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
	env.fd = open(argv[1], O_RDONLY);
	ft_test_input(&env);
	ft_save_tetriminos(argv[1], &env);
	ft_solve(&env);
	ft_putnbr(ft_x_pos(1, &env));ft_putchar('\n');
	ft_putnbr(ft_y_pos(1, &env));ft_putchar('\n');
	ft_print_solution(&env);
	close(env.fd);
	return (0);
}
