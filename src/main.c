/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fablin <fablin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:39:46 by fablin            #+#    #+#             */
/*   Updated: 2017/11/19 20:37:10 by fablin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main (int argc, char **argv)
{
	t_env	*env;

	if (!(env = ft_new_env()))
		EXIT;
	if (!(argc == 2))
		EXIT;
	//ft_test_input(argv[1]);
	ft_set_env(env, argv[1]);

	ft_solve(env);
	//ft_print_solution(env);
	return (0);
}
