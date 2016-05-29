/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 18:58:47 by atoupart          #+#    #+#             */
/*   Updated: 2016/05/14 18:58:53 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void			ft_debug_line(t_env *e) // debug
{
	int x1 = 0;
	int y1 = 0;
	int x2 = 999;
	int y2 = 0;
	int x = 0;
	I++;
	pts("--------------inside debug line nb = ");ptn(I);pts("   e_>zoom = ");ptn(e->zoom);ptcn;ptcn;

	while (y1 <= 600)
	{
		x = 0;
		while (x <= x2) // horizontale 
		{
			*(unsigned int *)(PIXEL + (BPP / 8 * x + SL * (y1+((y2-y1)*(x-x1))/(x2-x1)))) = 0x333333;
			x++;
		}
		y1  = y2 += e->zoom;
	}	
}

void			ft_debug_dot(t_env *e) // debug
{
	int j = 0;
	int k;
	Y = -1;
	L++;
	pts("...............inside debug dot nb = ");ptn(L);pts("    e_>zoom = ");ptn(e->zoom);ptcn;ptcn;

	while (++Y < Y_MAX)
	{
		X = -1;
		k = 0;
		while (++X < X_MAX[Y])
		{
			X1 = k;
			if (X1 >= 0 && X1 <= SL)
				*(unsigned int *)(PIXEL + (BPP / 8 * X1 + SL * j)) = RED;
			k += e->zoom;
		}

		j += e->zoom;
	}
}

void		ft_draw_fdf(t_env *e)
{
	int k; // zoom horizontal
	int j; // zoom vertical
	int x;
	int y;


	j = 0;
	k = 0;
	y = -1;
	H++;
	pts("###############inside draw fdf nb = ");ptn(H);pts("   e_>zoom = ");ptn(e->zoom);ptcn;ptcn;
	while (++y < 2) // normalement Y_MAX
	{ 
		j += e->zoom;
		k = 0;
		x = -1;		
		while (++x < 5)  // normalement X_MAX[y]
		{	
			e->x1 = PIX[y][x].x;
			e->y1 = PIX[y][x].y;
			k += e->zoom;
			if ((x + 1 < X_MAX[y]))
			{
				PIX[y][x + 1].x += k;
				e->x2 = PIX[y][x + 1].x;
				e->y2 = PIX[y][x + 1].y;
				pts("k = ");ptn(k);ptcn;

				pts("e->x2 = ");ptn(e->x2);ptcn;

				ft_trace_line(e, PIX[y][x].color);
			}
			if ((y + 1 < Y_MAX))
			{	
				e->x2 = e->x1;
				PIX[y + 1][x].y += j;
				e->y2 = PIX[y + 1][x].y;
				ft_trace_line(e, PIX[y][x].color);
			}

		}
	}

}


