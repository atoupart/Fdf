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

// int click_square(int button, int x, int y, t_env *e)
// {
// 	e->x = 0;
// 	while (e->x < 150)
// 	{
// 		e->y = 0;
// 		while (e->y < 150)
// 		{
// 				mlx_pixel_put(e->mlx, e->win, x - e->x, y - e->y, 0x0000FFFF - y + e->y - x + e->x);
// 				e->y++;
// 		}
// 		e->x++;
// 	}
// 	return (0);
// }


int	main(void)
{
	// t_env *e;


	// void *mlx2;
	// e->x = 15;
	// e->y = 15;
	// pte("passage 1");
	// e->mlx = mlx_init();
	// e->win = mlx_new_window(e->mlx, 1000, 1000, "mlx 42");
	// mlx_mouse_hook(e->win, click_square, e);	
	// mlx_key_hook(win, ft_exit, e);
	int x;
	int y;
	void *mlx;
	void *win;
	void *image;
	char *pixel;
	int bpp;
	int size_line;
	int endian;
	int color;


	x = 1;
	y = 1;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "testit");
	mlx_key_hook(win, ft_exit, 0);
	image = mlx_new_image(mlx, 500, 500);
	

	pixel = mlx_get_data_addr(image, &bpp, &size_line, &endian);



	ptn(bpp);ptcn;
	ptn(size_line);ptcn;



	*(unsigned int *)(pixel + (bpp / 8 * x + size_line * y)) = 0xFFA500;

	color =	mlx_get_color_value(mlx, 0x00000F);
	ptn(color);ptcn;
	
	mlx_put_image_to_window(mlx, win, image, 0, 0);

	mlx_loop(mlx);
	return(0);
}	
	

























