/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
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
	t_env *env;
	env = (t_env*)ft_memalloc(sizeof(t_env));
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, 1000, 1000, "testit");
	mlx_key_hook(WIN, ft_exit, 0);
	IMAGE = mlx_new_image(MLX, 1000, 1000);
	PIX = mlx_get_data_addr(IMAGE, &BPP, &SL, &env->endian);
	COLOR =	mlx_get_color_value(MLX, 0xFF0000);
	int x1 = 0;
	int y1 = 0;
	int x2 = 999;
	int y2 = 999;
	int x = y1;
	while (x <= y2) // diagonale basse
	{
		*(unsigned int *)(PIX + (BPP / 8 * x + SL * (y1+((y2-y1)*(x-x1))/(x2-x1)))) = COLOR;

		x++;
	}
	x = x1 = y2 = 0;
	x2 = y1 = 999;
	while (x <= x2) //diagonale haute
	{
		*(unsigned int *)(PIX + (BPP / 8 * x + SL * (y1+((y2-y1)*(x-x1))/(x2-x1)))) = 0x33EE11;
		x++;
	}
	x = x1 = 0;
	y1 = y2 = 500;
	x2 = 999;
	while (x <= x2) // horizontale 
	{
		*(unsigned int *)(PIX + (BPP / 8 * x + SL * (y1+((y2-y1)*(x-x1))/(x2-x1)))) = 0xFFA500;
		x++;
	}
	x = y1 = 0;
	x1 = x2 = 500;
	y2 = 999;
	while (x <= y2) // verticale
	{
		*(unsigned int *)(PIX + (BPP / 8 * x1+((x2-x1)*(x-y1))/(y2-y1) + SL * x)) = 0xDDAAEE;
		x++;
	}
	x1 = y1 = 500;
	int r = 100;
	int a = 0;


	ptn(sizeof(x2));ptcn;
	ptn(sizeof(y2));ptcn;

	while (a <= 360)  // cercle|| r <= 500)
	{
		x2 = x1+(r*cos(a));
		y2 = y1+(r*sin(a));
		*(unsigned int *)(PIX + (BPP / 8 * x2 + SL * y2)) = 0xEEBBEA + 1000*a;
		a++;
		// r++;
	}















	mlx_put_image_to_window(MLX, WIN, IMAGE, 0, 0);
	mlx_loop(MLX);
	return(0);
}	
