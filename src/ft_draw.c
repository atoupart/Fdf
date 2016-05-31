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

void		ft_draw_fdf(t_env *e)
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
			e->z1 = e->pix[y][x].z;
			e->x1 = e->pix[y][x].x;
			e->y1 = e->pix[y][x].y;
			e->y1 -= e->z1;
			if ((x + 1 < X_MAX[y]))
			{	
				e->pix[y][x + 1].x += k;
				e->z2 = e->pix[y][x + 1].z;
				e->x2 = e->pix[y][x + 1].x;
				e->y2 = e->pix[y][x + 1].y;
				e->y2 -= e->z2;
				pte("---HORIZONTAL---");
				pts("e->")

				ft_trace_line(e, e->pix[y][x].color);
			}
			if ((y + 1 < Y_MAX))
			{	
				e->pix[y + 1][x].y += j;
				e->z2 = e->pix[y][x + 1].z;


				e->x2 = e->x1;
				e->y2 = e->pix[y + 1][x].y;
				e->y2 -= e->z2;


				ft_trace_line(e, e->pix[y][x].color);
			}
		}
	}
}
