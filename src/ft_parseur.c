/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 21:42:23 by atoupart          #+#    #+#             */
/*   Updated: 2016/05/29 21:42:26 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"


void		ft_fill_pix(char *file, t_env *e)
{
	char *line;
	int  k;

	Y = -1;
	FD = open(file, O_RDONLY);
	ft_insert(FD >= 0, "Open error : Couldn't retrive the filename.");
	while (get_next_line(FD, &line) && ++Y < Y_MAX)
	{
		X = -1;
		k = -1;
		while (line[++k])
		{
			if (ft_isdigit(line[k]) || line[k] == '-')
				PIX[Y][++X].z = ft_atoi(line + k);
				while ((ft_isdigit(line[k]) || line[k] == '-') && line[k + 1])
					k++;
			if (line[k] == ',')
			{
				PIX[Y][X].color = ft_atoi_b(line + k + 1, 16);
				ft_insert(PIX[Y][X].color != 0, "Program stopped : malloc of pix.color failed");
				k++;
				while ((ft_isdigit(line[k]) || line[k] == 'x' || 
					(line[k] >= 'A' && line[k] <= 'F')) && line[k + 1])
					k++;
			}
		}
	}
	ft_insert(close(FD) != -1, "Close error : Couldn't close the file.");
	ft_strdel(&line);
}


int		ft_take_nb_elem(char *str)
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

void			ft_get_max_x_y(char *file, t_env *e)
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

void		ft_malloc_pix(char *file, t_env *e)
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

 void			ft_check_name(char *name, t_env *e)
{
	char *str = ".fdf";

	X = ft_strlen(name);
	Y = ft_strlen(str);
	while (--Y >= 0)
			ft_insert(name[--X] == str[Y], "Your file must end by <.fdf>\n");
}
