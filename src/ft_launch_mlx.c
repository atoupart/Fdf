/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_mlx.c                                    :+:      :+:    :+:   */
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
	int k; // zoom horizontal
	int j; // zoom vertical
	int x;
	int y;
	j = 0;
	k = 0;
	y = -1;
	while (++y < Y_MAX)
	{ 
		j += 20;
		k = 0;
		x = -1;		
		ptn(X_MAX[y]);ptcn;
		pts("WHITE = ");ptn(WHITE);ptcn;
		pts("BLUE = ");ptn(BLUE);ptcn;
		while (++x < X_MAX[y])
		{	



			e->x1 = PIX[y][x].x;
			e->y1 = PIX[y][x].y;
			k += 20;
			if ((x + 1 < X_MAX[y]))
			{
				PIX[y][x + 1].x += k;
				e->x2 = PIX[y][x + 1].x;
				e->y2 = PIX[y][x + 1].y;
				// ptn(x);pts("  couleur  ");ptn(PIX[y][x].color);ptcn;
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

void			ft_draw_line(t_env *e) // debug
{
	int x1 = 0;
	int y1 = 0;
	int x2 = 999;
	int y2 = 0;
	int x = 0;
	while (y1 <= 600)
	{
		x = 0;
		while (x <= x2) // horizontale 
		{
			*(unsigned int *)(PIXEL + (BPP / 8 * x + SL * (y1+((y2-y1)*(x-x1))/(x2-x1)))) = 0x333333;
			x++;
		}
		y1  = y2 += 20;
	}	
}

void			ft_draw_dot(t_env *e) // debug
{
	int j = 0;
	int k;
	Y = -1;
	while (++Y < Y_MAX)
	{
		X = -1;
		k = 0;
		while (++X < X_MAX[Y])
		{
			X1 = k;
			if (X1 >= 0 && X1 <= SL)
				*(unsigned int *)(PIXEL + (BPP / 8 * X1 + SL * j)) = RED;
			k += 20;
		}

		j += 20;
	}
}
void			ft_launch_mlx(t_env *e, int userwidth, int userheight)
{
	WIDTH = (userwidth > 0 ? userwidth : 1500);
	HEIGHT = (userheight > 0 ? userheight : 1500);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIDTH, HEIGHT, "F_D_F"); // a proteger
	IMAGE = mlx_new_image(MLX, WIDTH, HEIGHT);// a proteger
	PIXEL = mlx_get_data_addr(IMAGE, &BPP, &SL, &e->endian); // a proteger

	ft_draw_line(e);

	ft_draw_fdf(e);

	ft_draw_dot(e);


	mlx_put_image_to_window(MLX, WIN, IMAGE, 200, 200);
	mlx_destroy_image(MLX, IMAGE);
	mlx_hook(WIN, 17, 1L << 17, ft_error, "Goodbye Boy !"); 
	mlx_hook(WIN, 2, 1L << 2, ft_key, e);
	mlx_loop(MLX);
}

