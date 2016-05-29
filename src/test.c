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


// void	draw_pixel(t_img *img, int x, int y)
// {
// 	if (x + origine < WIDTH && y + y_origine < HEIGHT &&
// 			x + x_origine > 0 && y + y_origine > 0)
// 		*(unsigned int*)(pxl_ptr + ((bit_per_pxl / 8 *
// 			(x_origine + x)) + size_line *
// 				(y_origine + y))) = color;
// }

// void	draw_line(t_img *img)
// {
// 	double	m;
// 	double	p;

// 	i = 0;
// 	dist = x2 - x1;
// 	m = (y2 - y1) / (x2 - x1);
// 	p = y1 - m * x1;
// 	if (m <= 1 && m >= -1)
// 		while (i != dist)
// 		{
// 			draw_pixel(x1 + i, y1);
// 			x1 < x2 ? i++ : i--;
// 			x1 < x2 ? (y1 += m) : (y1 -= m);
// 		}
// 	else
// 	{
// 		m = (x2 - x1) / (i2 - y1);
// 		dist = y2 - y1;
// 		while (i != dist)
// 		{
// 			draw_pixel(x1, y1 + i);
// 			y1 < y2 ? i++ : i--;
// 			y1 < y2 ? (x1 += m) : (x1 -= m);
// 		}
// 	}
// }
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
