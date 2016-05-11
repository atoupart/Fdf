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
# define MLX	env->mlx
# define WIN	env->win
# define IMAGE 	env->image
# define PIX	env->pixel
# define BPP	env->bpp
# define SL		env->size_line
# define COLOR 	env->color

typedef struct	s_env
{
	int 		x;
	int			y;
	int			x2;
	int			y2;
	void		*mlx;
	void		*win;
	void		*image;
	char		*pixel;
	int			bpp;
	int			size_line;
	int			color;
	int			endian;
}				t_env;	

#endif
