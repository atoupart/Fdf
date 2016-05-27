/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 11:51:24 by atoupart          #+#    #+#             */
/*   Updated: 2016/05/14 11:51:27 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int		ft_take_nb_elem(char *str)
{
	int			nb;
	int 		k;

	k = 0;
	nb = 0;
	ft_insert(str[k] != '\0', "Program stopped : wrong line length.");
	while (str[k])
	{
		if (!(ft_isspace(str[k])) && str[k] != ',' && !(ft_isdigit(str[k])) 
			&& str[k] != '-' && str[k] != 'x'
			&& !(str[k] >= 'A' && str[k] <= 'F') && !(str[k])
			&& ((str[k] == '-' && str[k + 1] == '-') ||
				 (str[k] == 'x' && str[k + 1] == 'x')))
			ft_insert(0, "Program stopped : character incorrect.");
		else if (ft_isdigit(str[k]) || str[k] == '-')
		{	
			nb++;
			while (str[k] && !(str[k] == ' '))
				k++;
		}
		if (str[k])
			k++;
	}
	return (nb);
}


static void			ft_get_max_x_y(char *file, t_env *e)
{
	char 	*line;
	
	Y_MAX = 0;
	FD = open(file, O_RDONLY);
	ft_insert(FD >= 0, "Open error : Couldn't retrive the filename.");
	while ((I = get_next_line(FD, &line)) && ++Y_MAX)
		ft_insert(I != -1, "Program stopped : reading file failed.");	
	e->x_max = (int*)malloc(sizeof(int) * (Y_MAX + 1));
	ft_insert(X_MAX != NULL, "Program stopped : Malloc of X_MAX failed.");
	ft_insert(close(FD) != -1, "Close error : Couldn't close the file.");
	FD = open(file, O_RDONLY);
	ft_insert(FD >= 0, "Open error : Couldn't retrive the filename.");
	I = -1;
	while (get_next_line(FD, &line) && ++I <= Y_MAX)
		e->x_max[I] = ft_take_nb_elem(line);
	ft_insert(close(FD) != -1, "Close error : Couldn't close the file.");
	ft_strdel(&line);
}

static void		ft_malloc_pix(char *file, t_env *e)
{
	Y = -1;
	ft_get_max_x_y(file, e);
	PIX = (t_pix**)malloc(sizeof(t_pix*) * (Y_MAX + 1));
	while (++Y < Y_MAX)
	{
		PIX[Y] = (t_pix*)malloc(sizeof(t_pix) * (X_MAX[Y] + 1));
		ft_insert(X_MAX != NULL, "Program stopped : Malloc of PIX failed.");
		X = -1;
		while (++X <= X_MAX[Y])
		{
			PIX[Y][X].x = 0;	
			PIX[Y][X].y = 0;	
			PIX[Y][X].z = 0;	
			PIX[Y][X].color = WHITE;
		}
	}
}
	

static void			ft_check_name(char *name, t_env *e)
{
	char *str = ".fdf";

	X = ft_strlen(name);
	Y = ft_strlen(str);
	while (--Y >= 0)
			ft_insert(name[--X] == str[Y], "Your file must end by <.fdf>\n");
}

int		main(int ac, char **av)
{
	t_env *e;

	e = (t_env*)malloc(sizeof(t_env));
	ft_insert(e != NULL, "Program stopped : Malloc of env failed.");
	ft_insert(ac >= 2, "Usage: ./fdf map.fdf [width] [height]");
	ft_check_name(av[1], e);
	ft_malloc_pix(av[1], e);
	ft_fill_pix(av[1], e);
	pte("\033[32m end\033[31m");
	e->zoom = 20;
	if (ac == 4)
		ft_launch_mlx(e, ft_atoi(av[2]), ft_atoi(av[3]));
	else if (ac == 3)
		ft_launch_mlx(e, ft_atoi(av[2]), 0);
	else
		ft_launch_mlx(e, 0, 0);
	ft_draw_fdf(e);
	mlx_hook(WIN, 17, 1L << 17, ft_error, "Goodbye Boy !"); 
	mlx_hook(WIN, 2, 1L << 2, ft_key, e);
	mlx_loop(MLX);
	return (0);
}
