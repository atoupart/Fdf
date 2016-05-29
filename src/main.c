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
	t_env *e;

	e = (t_env*)malloc(sizeof(t_env));
	ft_insert(e != NULL, "Program stopped : Malloc of struct failed.");
	ft_insert(ac >= 2, "Usage: ./fdf map.fdf [width] [height]");
	ft_check_name(av[1], e);
	ft_malloc_pix(av[1], e);
	ft_fill_pix(av[1], e);
	pte("\033[32m parseur accomplited\033[31m");

	e->zoom = 20;
	I = 0;
	L = 0;
	H = 0;
	if (ac == 4)
		ft_make_fdf(e, ft_atoi(av[2]), ft_atoi(av[3]));
	else if (ac == 3)
		ft_make_fdf(e, ft_atoi(av[2]), 0);
	else
		ft_make_fdf(e, 0, 0);
	return (0);
}
