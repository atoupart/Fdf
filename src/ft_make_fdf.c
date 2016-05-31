/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 22:01:41 by atoupart          #+#    #+#             */
/*   Updated: 2016/05/29 22:01:47 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void			ft_launch_draw(t_env *e)
{
	mlx_clear_window(MLX, WIN);
	IMAGE = mlx_new_image(MLX, WIDTH, HEIGHT);
	PIXEL = mlx_get_data_addr(IMAGE, &BPP, &SL, &e->endian);

	ft_draw_fdf(e);

	mlx_put_image_to_window(MLX, WIN, IMAGE, 0, 0);
	mlx_destroy_image(MLX, IMAGE);

}

void			ft_init_mlx(t_env *e, int userwidth, int userheight)
{
	WIDTH = (userwidth > 0 ? userwidth : 1500);
	HEIGHT = (userheight > 0 ? userheight : 1500);
	e->lar = WIDTH / 4;
	e->lon = HEIGHT / 4;
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIDTH, HEIGHT, "F_D_F"); 
	ft_insert(WIN != NULL, "Program stopped : malloc WIN failed.");
	IMAGE = mlx_new_image(MLX, WIDTH, HEIGHT);
	ft_insert(IMAGE != NULL, "Program stopped : malloc IMAGE failed.");
	PIXEL = mlx_get_data_addr(IMAGE, &BPP, &SL, &e->endian); 
	ft_insert(WIN != NULL, "Program stooped : malloc PIXEL failed.");
}

void			ft_init_var(t_env *e)
{
	e->x1 = 0;
	e->y1 = 0;
	e->x2 = 0;
	e->y2 = 0;
	ft_reset_pix(e);
}

void			ft_make_fdf(t_env *e, int userwidth, int userheight)
{
	ft_init_mlx(e, userwidth, userheight);

	ft_launch_draw(e);




	mlx_hook(WIN, 17, 1L << 17, ft_error, "Goodbye Boy !"); 
	mlx_hook(WIN, 2, 1L << 2, ft_key, e);
	mlx_loop(MLX);
}
