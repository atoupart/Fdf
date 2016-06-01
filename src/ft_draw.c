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
			if (e->z1 != 0)
				e->z1 += e->alt;
			e->x1 = e->pix[y][x].x;
			e->y1 = e->pix[y][x].y;
			e->y1 -= e->z1;
			pts("e->z1 = ");ptn(e->z1);ptcn;
			pts("e->x1 = ");ptn(e->x1);ptcn;
			pts("e->y1 = ");ptn(e->y1);ptcn;ptcn;
			if ((x + 1 < X_MAX[y]))
			{	
				e->pix[y][x + 1].x += k;
				e->z2 = e->pix[y][x + 1].z;
				if (e->z2 != 0)
					e->z2 += e->alt;
				e->x2 = e->pix[y][x + 1].x;
				e->y2 = e->pix[y][x + 1].y;
				e->y2 -= e->z2;
				pte("---HORIZONTAL---");
				pts("e->z2 = ");ptn(e->z2);ptcn;
				pts("e->x2 = ");ptn(e->x2);ptcn;
				pts("e->y2 = ");ptn(e->y2);ptcn;ptcn;
				
// idée ! je pense faire un genre de e->z += e->z pour augmenter les negatif et positif en meme temps faut juste 
				que je rajoute le e->alt quelque part.



				ft_trace_line(e, e->pix[y][x].color);
			}
			if ((y + 1 < Y_MAX))
			{
				e->pix[y + 1][x].y += j;
				e->z2 = e->pix[y + 1][x].z;
				if (e->z2 != 0)
					e->z2 += e->alt;

				e->x2 = e->x1;
				e->y2 = e->pix[y + 1][x].y;
				e->y2 -= e->z2;
				pts("LOL = ");ptn(e->pix[y + 1][x].z);ptcn;ptcn;ptcn;

				pte("|||VERTICAL|||");
				pts("e->z2 = ");ptn(e->z2);ptcn;
				pts("e->x2 = ");ptn(e->x2);ptcn;
				pts("e->y2 = ");ptn(e->y2);ptcn;ptcn;

				ft_trace_line(e, e->pix[y][x].color);
			}
		}
	}
}
