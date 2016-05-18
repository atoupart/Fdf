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

static void 		ft_fill_line(char *line, t_env *env)
{
	int 	k;
	int 	i;

	k = 0;
	i = 0;
	bzero(TAB[Y])
	while (line[k])
	{
		if (ft_isdigit(line[k]) || line[k] == 45)
		{
			TAB[Y][i] = ft_atoi(line + k);
			i++;
		}
		k++;
	}
}

void		put_tab(t_env *env)
{
	Y = 0;
	while (Y < Y_MAX)
	{
		X = 0;
		while (X < X_MAX)
		{
			ptn(TAB[Y][X]);pts(" ");
			X++;
		}
		ptcn;
		Y++;
	}
}


static int		ft_take_nb_elem(char *str)
{
	int			nb;

	nb = 0;
	while (*str)
	{
		if (ft_isdigit(*str) || *str == 45)
		{
			++nb;
			while (*str && ft_isdigit(*str))
				++str;
		}
		else
			++str;
	}
	return (nb);
}


static void		ft_fill_tab(char *str, t_env *env)
{
	char *line;
	
	X = 0;
	ft_insert((FD = open(str, O_RDONLY)) >= 0, "Open error : Couldn't retrive the filename.");
	while ((Y = get_next_line(FD, &line)) && ++X)
		ft_insert(Y != -1, "Program stopped : reading file failed.");
	Y_MAX = X;
	ft_insert(close(FD) != -1, "Close error : Couldn't close the file.");
	TAB = (int**)malloc(sizeof(int*) * (Y_MAX+ 1));
	ft_insert(TAB != NULL, "Program stopped : Malloc of TAB failed.");
	ft_insert((FD = open(str, O_RDONLY)) >= 0, "Open error : Couldn't retrive the filename.");
	Y = 0;
	pte("before while");
	while (get_next_line(FD, &line))
	{
		X_MAX = ft_take_nb_elem(line);
		TAB[Y] = (int*)malloc(sizeof(int) * (X_MAX + 1));
		ft_insert(TAB[Y] != NULL, "Program stopped : Malloc of *TAB failed.");
		pte("before fill line");
		ft_fill_line(line, env);
		Y++;
	}
	ft_insert(close(FD) != -1, "Close error : Couldn't close the file.");
}

static void			ft_check_name(char *name, t_env *env)
{
	char *str = ".fdf";

	X = ft_strlen(name);
	Y = ft_strlen(str);
	while (--Y >= 0)
			ft_insert(name[--X] == str[Y], "Your file must end by <.fdf>\n");
}

int		main(int ac, char **av)
{
	t_env *env;

	env = (t_env*)malloc(sizeof(t_env));
	ft_insert(env != NULL, "Program stopped : Malloc of env failed.");
	ft_insert(ac >= 2, "Usage: ./fdf map.fdf [width] [height]");
	ft_check_name(av[1], env);
	ft_fill_tab(av[1], env);

	put_tab(env);
	pte("\033[32m end");
	// if (ac == 4)
	// 	ft_launch_mlx(env, ft_atoi(av[2]), ft_atoi(av[3]));
	// else if (ac == 3)
	// 	ft_launch_mlx(env, ft_atoi(av[2]), 0);
	// else
	// 	ft_launch_mlx(env, 0, 0);
	return (0);
}
