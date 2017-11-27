/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/17 14:39:46 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 11:36:51 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_env	*env;

	if (!(env = ft_new_env()))
		EXIT;
	if (!(argc == 2))
		ft_exit("usage: fillit source_file");
	ft_test_input(argv[1]);
	ft_set_env(env, argv[1]);
	ft_solve(env);
	ft_print_solution(env);
	return (0);
}
