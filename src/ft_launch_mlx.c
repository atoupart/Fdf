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

void		ft_draw_fdf(t_env *env)
{
	int k; // zoom horizontal
	int j; // zoom vertical
	int x;
	Y = 0;
	j = 0;
	BPP /= 8;
	X = 0;
	k = 0;
	x = 0;

		while (++X < X_MAX[Y])
		{	
			k += 20;
			j += 20;
			X1 = PIX[Y][X].x;
			Y1 = PIX[Y][X].y;
			X2 = PIX[Y][X + 1].x + k;
			Y2 = PIX[Y][X + 1].y;
			x = -1;
			while (++x <= X2) // horizontal
				*(unsigned int *)(PIXEL + (BPP * x + SL * (Y1+((Y2-Y1)*(x-X1))/(X2-X1)))) = 0x009900;

			// x = -1;
			// X1 = 0;
			// Y1 = 0;
			// X2 = 0;
			// Y2 = j;
			// while (++x <= Y2) // verticale
			// {
			// 	pte("debug4");
			// 	*(unsigned int *)(PIXEL + (BPP * X1+((X2-X1)*(x-Y1))/(Y2-Y1) + SL * x)) = 0x009900;
			// 	pte("debug5");
			// }
			// int x1 = PIX[Y][X].x;
			// int y1 = PIX[Y][X].y;	
			// int x2 = PIX[Y + 1][X].x;
			// int y2 = PIX[Y + 1][X].y + j;
			// x = 0;
			// while (x <= y2) // verticale
			// {
			// 	*(unsigned int *)(PIXEL + (BPP * x1+((x2-x1)*(x-y1))/(y2-y1) + SL * x)) = 0xDDAAEE;
			// 	x++;
			// }

			env->x1 = PIX[Y][X].x;
			env->y1	= PIX[Y][X].y;	
			env->x2 = PIX[Y + 1][X].x;
			env->y2 = PIX[Y + 1][X].y + j;
			x = 0;
			while (x <= env->y2) // verticale
			{
				*(unsigned int *)(PIXEL + (BPP * env->x1+((env->x2-env->x1)*(x-env->y1))/(env->y2-env->y1) + SL * x)) = 0xDDAAEE;
				x++;
			}
	}
}
void			ft_draw_line(t_env *env) // debug
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

void			ft_draw_dot(t_env *env)
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
				*(unsigned int *)(PIXEL + (BPP * X1 + SL * j)) = YELLOW;
			k += 20;
		}

		j += 20;
	}
}
void			ft_launch_mlx(t_env *env, int userwidth, int userheight)
{
	WIDTH = (userwidth > 0 ? userwidth : 1500);
	HEIGHT = (userheight > 0 ? userheight : 1500);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIDTH, HEIGHT, "F_D_F"); // a proteger
	IMAGE = mlx_new_image(MLX, WIDTH, HEIGHT);// a proteger
	PIXEL = mlx_get_data_addr(IMAGE, &BPP, &SL, &env->endian); // a proteger

	ft_draw_line(env);

	ft_draw_fdf(env);

	ft_draw_dot(env);

	mlx_hook(WIN, 2, 1L << 2, ft_key, env);

	*(unsigned int *)PIXEL = RED;

	mlx_put_image_to_window(MLX, WIN, IMAGE, 200, 200);
	mlx_destroy_image(MLX, IMAGE);
	
	mlx_loop(MLX);
}		// X = -1;
		// k = 0;
		// while (++X < X_MAX[0])
		// {
		// 	X1 = PIX[0][X].x + k;
		// 	if (X1 >= 0 && X1 <= SL)
		// 		*(unsigned int *)(PIXEL + (BPP * X1 + SL * j)) = RED;
		// 	k += 20;
		// }
		// j += 20;
		// X = -1;
		// k = 0;
		// while (++X < X_MAX[6])
		// {
		// 	X1 = PIX[6][X].x + k;
		// 	if (X1 >= 0 && X1 <= SL)
		// 		*(unsigned int *)(PIXEL + (BPP * X1 + SL * j)) = RED;
		// 	k += 20;
		// }
		// j += 20;
		// X = -1;
		// k = 0;
		// while (++X < X_MAX[12])
		// {
		// 	X1 = PIX[12][X].x + k;
		// 	if (X1 >= 0 && X1 <= SL)
		// 		*(unsigned int *)(PIXEL + (BPP * X1 + SL * j)) = RED;
		// 	k += 20;
		// }
		// j += 20;
		// X = -1;
		// k = 0;
		// while (++X < X_MAX[19])
		// {
		// 	X1 = PIX[19][X].x + k;
		// 	if (X1 >= 0 && X1 <= SL)
		// 		*(unsigned int *)(PIXEL + (BPP * X1 + SL * j)) = RED;
		// 	k += 20;
		// }
