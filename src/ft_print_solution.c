#include "../inc/fillit.h"

void	ft_print_solution(t_env *env)
{
	int	i;
	int	len;

	i = 0;
	len = SIZE * SIZE;
	while (i < len)
	{
		write(1, &env->grid[i], 1);
		i++;
		if (i % SIZE == 0)
			ft_putchar('\n');
	}
}
