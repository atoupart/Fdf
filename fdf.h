/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 14:31:26 by atoupart          #+#    #+#             */
/*   Updated: 2016/05/03 14:31:28 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <math.h>
# include <mlx.h>

# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define YELLOW 0xFFFF00
# define BLACK 0x000000
# define PURPLE 0x800080
# define CYAN 0x00ffff
# define X_MAX 	env->x_max
# define Y_MAX 	env->y_max
# define Z 		env->z
# define X		env->x
# define Y		env->y
# define X1		env->x1
# define Y1		env->y2
# define Y2     env->y2
# define X2     env->x2
# define FD 	env->fd
# define MLX	env->mlx
# define WIN	env->win
# define IMAGE 	env->image
# define PIXEL	env->pixel
# define BPP	env->bpp
# define SL		env->size_line
# define COLOR 	env->color
# define WIDTH  env->width
# define HEIGHT env->height
# define TAB 	env->tab
# define PIX 	env->pix
# define I 		env->i
# define L 		env->l
# define H 		env->h

typedef struct 	s_pix
{
	int 		x;
	int 		y;
	int 		z;
	int 		color;

} 				t_pix;

typedef struct	s_env
{
	int 		*x_max;
	int 		y_max;
	int 		l;
	int 		h;
	int 		i;
	int 		z;
	int 		x;
	int 		y;
	int 		x1;
	int			y1;
	int			x2;
	int			y2;
	int 		fd;
	void		*mlx;
	void		*win;
	void		*image;
	char		*pixel;
	int			bpp;
	int			size_line;
	int			color;
	int			endian;
	int 		width;
	int 		height;
	int 		**tab;
	t_pix		**pix;
}				t_env;


void		ft_draw_line(t_env *env);
void			ft_insert(int verif, char *str);
void			ft_launch_mlx(t_env *env, int width, int height);
void			ft_fill_pix(char *file, t_env *env);
int				ft_key(int keycode, t_env *env);

#endif
 