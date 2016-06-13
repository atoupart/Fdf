/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 17:11:42 by atoupart          #+#    #+#             */
/*   Updated: 2016/04/21 17:11:45 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_exit(int keycode, void *param)
{
	param = 0;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int	main(void)
{
	t_env *e;
	e = (t_env*)ft_memalloc(sizeof(t_env));
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, 1000, 1000, "testit");
	mlx_key_hook(WIN, ft_exit, 0);
	IMAGE = mlx_new_image(MLX, 1000, 1000);
	PIXEL = mlx_get_data_addr(IMAGE, &BPP, &SL, &e->endian);
	COLOR =	mlx_get_color_value(MLX, 0xFF0000);
	int x1 = 0;
	int y1 = 0;
	int x2 = 999;
	int y2 = 999;
	int x = y1;
	BPP /= 8;
	while (x <= y2) // diagonale basse
	{
		*(unsigned int *)(PIXEL + (BPP * x + SL * (y1+((y2-y1)*(x-x1))/(x2-x1)))) = COLOR;

		x++;
	}
	x = x1 = y2 = 0;
	x2 = y1 = 999;

	x = 0;
	x1 = 0;
	y1 = 999;
	x2 = 999;
	y2 = 0;
	while (x <= x2) //diagonale haute
	{
		*(unsigned int *)(PIXEL + (BPP * x + SL * (y1+((y2-y1)*(x-x1))/(x2-x1)))) = 0x33EE11;
		x++;
	}
	x = x1 = 0;
	y1 = y2 = 500;
	x2 = 999;
	while (x <= x2) // horizontale 
	{
		*(unsigned int *)(PIXEL + (BPP * x + SL * (y1+((y2-y1)*(x-x1))/(x2-x1)))) = 0xFFA500;
		x++;
	}
	x = y1 = 0;
	x1 = x2 = 500;
	y2 = 999;
	while (x <= y2) // verticale
	{
		*(unsigned int *)(PIXEL + (BPP * x1+((x2-x1)*(x-y1))/(y2-y1) + SL * x)) = 0xDDAAEE;
		x++;
	}
	x1 = y1 = 500;
	int r = 400;
	int a = 0;


	while (a <= 360)  // cercle|| r <= 500)
	{
		x2 = x1+(r*cos(a));
		y2 = y1+(r*sin(a));
		*(unsigned int *)(PIXEL + (BPP * x2 + SL * y2)) = 0xFFFFFF;
		a++;
		// r++;
	}

	mlx_put_image_to_window(MLX, WIN, IMAGE, 0, 0);
	mlx_loop(MLX);
	return(0);
}	


void			ft_debug_line(t_env *e) // debug
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
		y1  = y2 += e->zoom;
	}	
}

void			ft_debug_dot(t_env *e) // debug
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
			k += e->zoom;
		}

		j += e->zoom;
	}
}














void		ft_p_pixel_image(t_a *a, int y, int x, int color)
{
	if (x >= 0 && x < MAX_X && y >= 0 && y < MAX_Y)
		*(unsigned int*)(a->e.data + (x * (a->e.bpp)) + (y * a->e.sl)) = color;
}

static void		ligne_if(t_a *a, int color)
{
	a->b.cumul = a->b.dx / 2;
	a->b.i = 0;
	while (++a->b.i <= a->b.dx)
	{
		a->b.x += a->b.xinc;
		a->b.cumul += a->b.dy;
		if (a->b.cumul >= a->b.dx)
		{
			a->b.cumul -= a->b.dx;
			a->b.y += a->b.yinc;
		}
		ft_p_pixel_image(a, a->b.y, a->b.x, color);
	}
}

static void		ligne_else(t_a *a, int color)
{
	a->b.cumul = a->b.dy / 2;
	a->b.i = 0;
	while (++a->b.i <= a->b.dy)
	{
		a->b.y += a->b.yinc;
		a->b.cumul += a->b.dx;
		if (a->b.cumul >= a->b.dy)
		{
			a->b.cumul -= a->b.dy;
			a->b.x += a->b.xinc;
		}
		ft_p_pixel_image(a, a->b.y, a->b.x, color);
	}
}

void			ligne(t_a *a, int color)
{
	a->b.x = a->p1.x;
	a->b.y = a->p1.y;
	a->b.dx = a->p2.x - a->p1.x;
	a->b.dy = a->p2.y - a->p1.y;
	a->b.xinc = (a->b.dx > 0) ? 1 : -1;
	a->b.yinc = (a->b.dy > 0) ? 1 : -1;
	a->b.dx = abs(a->b.dx);
	a->b.dy = abs(a->b.dy);
	ft_p_pixel_image(a, a->b.y, a->b.x, color);
	if (a->b.dx > a->b.dy)
		ligne_if(a, color);
	else
		ligne_else(a, color);
}
































































