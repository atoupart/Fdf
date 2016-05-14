/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 11:51:24 by atoupart          #+#    #+#             */
/*   Updated: 2016/05/14 11:51:27 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		main(int ac, char **av)
{
	t_env *env;

	env = (t_env*)malloc(sizeof(t_env));
	ft_insert(env != NULL, "Program stopped : Malloc of env failed.");

	ft_insert(ac >= 2, "Usage: ./fdf map.fdf [width] [height]");
	ft_check_create_tab(av[1], env);
	if (ac == 4)
		ft_launch_mlx(env, ft_atoi(av[2]), ft_atoi(av[3]));
	else if (ac == 3)
		ft_launch_mlx(env, ft_atoi(av[2]), 0);
	else
		ft_launch_mlx(env, 0, 0);
	return (0);
}
