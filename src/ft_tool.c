/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 11:51:24 by atoupart          #+#    #+#             */
/*   Updated: 2016/05/14 11:51:27 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int				ft_key2(int keycode, t_env *e)
{
	if (keycode == 126)
		e->lon -= 100;
	if (keycode == 125)
		e->lon += 100;
	if (keycode == 123)
		e->lar -= 100;
	if (keycode == 124)
		e->lar += 100;
	if (keycode == 24)
		e->alt += 2;
	if (keycode == 27)
		e->alt -= 2;
	return (0);
}

int				ft_key(int keycode, t_env *e)
{
	ft_key2(keycode, e);
	if (keycode == 53)
	{
		ft_putstr("\033[32mProgram stopped properly, congratulations boy !\n");
		exit(EXIT_SUCCESS);
	}
	if (keycode == 69 || keycode == 78)
	{
		e->zoom += (keycode == 69) ? 2 : -2;
		if (e->zoom <= 0)
			e->zoom = 2;
	}
	if (keycode == 15)
	{
		e->lar = WIDTH / 4;
		e->lon = HEIGHT / 3;
		e->zoom = 20;
		e->alt = 0;
		e->iso = -1;
	}
	if (keycode == 34)
		e->iso *= -1;
	ft_reset_pix(e);
	ft_launch_draw(e);
	return (0);
}

void			ft_insert(int verif, char *str)
{
	if (!verif)
	{
		ft_error(str);
	}
}

void			ft_reset_pix(t_env *e)
{
	int y;
	int x;

	y = -1;
	while (++y < Y_MAX)
	{
		x = -1;
		while (++x <= X_MAX[y])
		{
			PIX[y][x].x = 0;
			PIX[y][x].y = 0;
		}
	}
}
