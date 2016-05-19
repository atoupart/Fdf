/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 18:35:45 by atoupart          #+#    #+#             */
/*   Updated: 2016/05/14 18:35:47 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_key(int keycode, void *param)
{
	param = 0;
	if (keycode == 53)
	{
		ft_putstr("\033[32mProgram stopped properly, congratulations boy !\n");
		exit(EXIT_SUCCESS);
	}
	return (0);
}
