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

static void		ft_draw_line(t_env *env)
{
	int x;

	BPP /= 8;
	Y = 0;
	X = 0;
	// while (++X <= X_MAX[Y])
	// {
	// 	if (X <= 5)
	// 		COLOR = RED;
	// 	if (X > 5 && X <= 10)
	// 		COLOR = GREEN;
	// 	if (X > 10 && X <= 15)
	// 		COLOR = YELLOW;
	// 	if (X > 15)
	// 		COLOR = PURPLE;	
		X1 = PIX[Y][X].x;
		Y1 = PIX[Y][X].y;
		X2 = PIX[Y][X + 1].x;
		Y2 = PIX[Y][X + 1].y;
		x = X1;
		COLOR = WHITE;			
		while (++x < X2 + 100) // horizontale 
		{
			if (x < 5 || (x > X2 + 95))
				COLOR = RED;
			else
				COLOR = WHITE;
			if ( x >= 0 && x <= SL)
				*(unsigned int *)(PIXEL + ((BPP * x) + SL * (Y1+((Y2-Y1)*(x-X1))/(X2-X1)))) = COLOR;
		}
		X = 1;
		X1 = PIX[Y][X].x;
		Y1 = PIX[Y][X].y;
		X2 = PIX[Y][X + 1].x;
		Y2 = PIX[Y][X + 1].y;
		x = X1;

		while (++x < X2 + 100) // horizontale 
		{
			if (x < 5 || (x > X2 + 95))
				COLOR = YELLOW;
			else
				COLOR = GREEN;
			if ( x >= 0 && x <= SL)
				*(unsigned int *)(PIXEL + ((BPP * x) + SL * (Y1+((Y2-Y1)*(x-X1))/(X2-X1)))) = COLOR;
		}
	// }
	

}

void			ft_launch_mlx(t_env *env, int userwidth, int userheight)
{
	WIDTH = (userwidth > 0 ? userwidth : 1000);
	HEIGHT = (userheight > 0 ? userheight : 1000);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIDTH, HEIGHT, "F_D_F");
	IMAGE = mlx_new_image(MLX, WIDTH, HEIGHT);
	PIXEL = mlx_get_data_addr(IMAGE, &BPP, &SL, &env->endian);

	ft_draw_line(env);

	mlx_key_hook(WIN, ft_key, 0);

	mlx_put_image_to_window(MLX, WIN, IMAGE, 200, 200);
	mlx_loop(MLX);
}
// static void		ft_draw_line(t_env *env)
// {
// 	int x;

// 	BPP /= 8;
// 	Y = -1;
// 	while (++Y < Y_MAX)
// 	{
// 		X = -1;
// 		while (++X < X_MAX[Y])
// 		{
// 			x = PIX[Y][X].x;
// 			while (x < (PIX[Y][X + 1].x)) // horizontale 
// 			{
// 				*(unsigned int *)(PIXEL + ((BPP * x * 10) + SL *
// 				 (PIX[Y][X].y+((PIX[Y][X+1].y-PIX[Y][X].y)*
// 				 	(x-PIX[Y][X].x))/(PIX[Y][X+1].x-PIX[Y][X].x)))) = 0xFF0000;				
// 				x++;
// 				pts("########");ptcn;ptn(x);ptcn;pte("########");
// 			}
// 		}
// 	}
// }
