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


# define X		env->x
# define Y		env->y
# define Y2     env->y2
# define X2     env->x2
# define FD 	env->fd
# define MLX	env->mlx
# define WIN	env->win
# define IMAGE 	env->image
# define PIX	env->pixel
# define BPP	env->bpp
# define SL		env->size_line
# define COLOR 	env->color
# define WIDTH  env->width
# define HEIGHT env->height
# define TAB 	env->tab

typedef struct	s_env
{
	int 		x;
	int			y;
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
}				t_env;	

void			ft_insert(int verif, char *str);
void			ft_launch_mlx(t_env *env, int width, int height);
int				ft_key(int keycode, void *env);
void			ft_check_create_tab(char *str, t_env *env);
void			ft_check_name(char *name, t_env *env);


#endif
