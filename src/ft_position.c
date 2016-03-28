#include "../inc/fillit.h"

int		ft_x_pos(int absolute_pos, t_env *env)
{
	return (absolute_pos % SIZE);
}

int		ft_y_pos(int absolute_pos, t_env *env)
{
	return (absolute_pos / SIZE);
}
