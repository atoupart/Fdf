/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 12:03:23 by atoupart          #+#    #+#             */
/*   Updated: 2016/05/14 12:03:31 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_insert(int verif, char *str)
{
	if (!verif)
	{
		ft_putstr_fd("\033[33m", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\033[0m\n", 2);
		exit(0);
	}
}
