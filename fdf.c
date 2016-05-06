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

//-framework OpenGl -framework AppKit

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

#define pte ft_putendl 
#define ptn ft_putnbr
#define pts ft_putstr
#define ptcn ft_putchar('\n')
typedef struct s_en
{
	int x;
	int y;
	void *mlx;
	void *win;
	void *image;
	char *pixel;
	int bpp;
	int size_line;
	int endian;
}	t_env;	

int	ft_exit(int keycode, void *param)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int click_square(int button, int x, int y, t_env *e)
{
	e->x = 0;
	while (e->x < 150)
	{
		e->y = 0;
		while (e->y < 150)
		{
				mlx_pixel_put(e->mlx, e->win, x - e->x, y - e->y, 0xFF0000 + y - e->y + x - e->x);
				e->y++;
		}
		e->x++;
	}
	return (0);
}


int	main(void)
{
	t_env *e;

	int x = 10;
	int y = 10;

	void *mlx2;
	e->x = 15;
	e->y = 15;

	pte("passage 1");
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 1000, 1000, "mlx 42");

	pte("passage 2");


	pte("passage 3");

	mlx_key_hook(e->win, ft_exit, e);
	pte("passage 4");
	mlx_mouse_hook(e->win, click_square, e);
	// pte("passage 5");

	// e->image = mlx_new_image(e->mlx, 500, 500);
	// pte("passage 6");
	// e->pixel = mlx_get_data_addr(e->image, &(e->bpp), &(e->size_line), &(e->endian));
	// pte("passage 7");
	// *(unsigned int *)(e->pixel + (e->bpp / 8 * x + e->size_line * y)) = 0xFF0000;
	// pte("passage 8");
	// mlx_put_image_to_window(e->mlx, e->win, e->image, 20, 20);
	pte("passage 9");
	mlx_loop(e->mlx);
	return(0);
}	

























