/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 18:58:47 by atoupart          #+#    #+#             */
/*   Updated: 2016/05/14 18:58:53 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int		expo_alt(t_env *e, int z)
{
	int		coeff;

	coeff = (z / 10) * (z / 10);
	z += e->alt * coeff;
	return (z);
}

static void		ft_draw_dot(t_env *e, int x, int y)
{
	e->z1 = e->pix[y][x].z;
	e->z1 = expo_alt(e, e->z1);
	e->x1 = e->pix[y][x].x;
	e->y1 = e->pix[y][x].y;
	e->y1 -= e->z1;
}

static void		ft_draw_horizontal(t_env *e, int k, int x, int y)
{
	e->pix[y][x + 1].x += k;
	e->z2 = e->pix[y][x + 1].z;
	e->z2 = expo_alt(e, e->z2);
	e->x2 = e->pix[y][x + 1].x;
	e->y2 = e->pix[y][x + 1].y;
	e->y2 -= e->z2;
	ft_trace_line(e, e->pix[y][x].color);
}

static void		ft_draw_vertical(t_env *e, int j, int x, int y)
{
	e->pix[y + 1][x].y += j;
	e->z2 = e->pix[y + 1][x].z;
	e->z2 = expo_alt(e, e->z2);
	e->x2 = e->x1;
	e->y2 = e->pix[y + 1][x].y;
	e->y2 -= e->z2;
	ft_trace_line(e, e->pix[y][x].color);
}

void			ft_draw_fdf(t_env *e)
{
	int k;
	int j;
	int x;
	int y;

	j = 0;
	k = 0;
	y = -1;
	while (++y < Y_MAX)
	{
		j += e->zoom;
		k = 0;
		x = -1;
		while (++x < X_MAX[y])
		{
			k += e->zoom;
			ft_draw_dot(e, x, y);
			if ((x + 1 < X_MAX[y]))
				ft_draw_horizontal(e, k, x, y);
			if ((y + 1 < Y_MAX))
				ft_draw_vertical(e, j, x, y);
		}
	}
}
