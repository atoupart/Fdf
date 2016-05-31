/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 14:40:23 by atoupart          #+#    #+#             */
/*   Updated: 2016/05/25 14:40:26 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void		ft_put_pixel(t_env *e, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{

		*(unsigned int*)(PIXEL + (x * (BPP / 8)) + (y * SL)) = color;
	}
}

static void		ft_trace_line_if(t_env *e, int color)
{
	e->cumul = e->dx / 2;
	e->i = 0;
	while (++e->i <= e->dx)
	{
		e->x += e->xinc;
		e->cumul += e->dy;
		if (e->cumul >= e->dx)
		{
			e->cumul -= e->dx;
			e->y += e->yinc;
		}
		ft_put_pixel(e, e->x + e->lar, e->y + e->lon, color);  // normal sans iso

		// ft_put_pixel(e, e->x + e->y / 3 + e->lar, e->y - e->x / 3+ e->lon, color); // iso >>



	}
}

static void		ft_trace_line_else(t_env *e, int color)
{
	e->cumul = e->dy / 2;
	e->i = 0;
	while (++e->i <= e->dy)
	{
		e->y += e->yinc;
		e->cumul += e->dx;
		if (e->cumul >= e->dy)
		{
			e->cumul -= e->dy;
			e->x += e->xinc;
		}
		ft_put_pixel(e, e->x + e->lar, e->y + e->lon, color);  // normal sans iso

		// ft_put_pixel(e, e->x + e->y / 3 + e->lar, e->y - e->x / 3 + e->lon, color); // iso >>




	}
}

void		ft_trace_line(t_env *e, int color)
{
	e->x = e->x1;
	e->y = e->y1;
	e->dx = e->x2 - e->x1;
	e->dy = e->y2 - e->y1;
	e->xinc = (e->dx > 0) ? 1 :  -1;
	e->yinc = (e->dy > 0) ? 1 :  -1;
	e->dx = abs(e->dx);
	e->dy = abs(e->dy);

	ft_put_pixel(e, e->x + e->lar, e->y + e->lon, color);  // normal sans iso

	// ft_put_pixel(e, e->x + e->y / 3 + e->lar, e->y - e->x  / 3+ e->lon, color);  // iso >>




	if (e->dx > e->dy)
		ft_trace_line_if(e, color);
	else
		ft_trace_line_else(e, color);
}
