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
# define X_MAX 	e->x_max
# define Y_MAX 	e->y_max
# define Z 		e->z
# define X		e->x
# define Y		e->y
# define X1		e->x1
# define Y1		e->y2
# define Y2     e->y2
# define X2     e->x2
# define FD 	e->fd
# define MLX	e->mlx
# define WIN	e->win
# define IMAGE 	e->image
# define PIXEL	e->pixel
# define BPP	e->bpp
# define SL		e->size_line
# define COLOR 	e->color
# define WIDTH  e->width
# define HEIGHT e->height
# define TAB 	e->tab
# define PIX 	e->pix
# define I 		e->i
# define L 		e->l
# define H 		e->h

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
	int 		dx;
	int 		dy;
	int 		xinc;
	int 		yinc;
	int 		cumul;



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

void 			ft_trace_line(t_env *e, int color);
void			ft_draw_line(t_env *e);
void				ft_insert(int verif, char *str);
void			ft_launch_mlx(t_env *e, int width, int height);
void			ft_fill_pix(char *file, t_env *e);
int				ft_key(int keycode, t_env *e);

#endif
 