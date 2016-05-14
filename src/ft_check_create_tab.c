/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_create_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 18:58:47 by atoupart          #+#    #+#             */
/*   Updated: 2016/05/14 18:58:53 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int		ft_take_nb_elem(char *str)
{
	int			nb;

	nb = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			++nb;
			while (*str && ft_isdigit(*str))
				++str;
		}
		else
			++str;
	}
	return (nb);
}

void			ft_check_create_tab(char *str, t_env *env)
{
	char		*tmp;

	X = 0;
	Y = 0;
	ft_check_name(str, env);
	FD = open(str, O_RDWR);
	ft_insert(FD >= 0, "Open error : Couldn't retrive the filename.");
	while (get_next_line(FD, &tmp))
		{
			Y = ft_take_nb_elem(tmp);
			X++;
		}
	TAB = (int**)malloc(sizeof(int*) * (X + 1));
	ft_insert(TAB != NULL, "Program stopped : Malloc of TAB failed.");
	ft_insert(close(FD) != -1, "Close error : Couldn't close the file.");



finir de comprendre comment ne pas essaye de faire deux appelle a get next line en sainer de hanouna
}
