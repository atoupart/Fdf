/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_pix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 11:42:26 by atoupart          #+#    #+#             */
/*   Updated: 2016/05/18 11:42:28 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		ft_fill_pix(char *file, t_env *env)
{
	char *line;
	int  k;

	Y = -1;
	FD = open(file, O_RDONLY);
	ft_insert(FD >= 0, "Open error : Couldn't retrive the filename.");
	while (get_next_line(FD, &line) && ++Y < Y_MAX)
	{
		X = -1;
		k = 0;
		while (line[k])
		{
			if (ft_isdigit(line[k]) || line[k] == '-')
			{	
				X++;
				// PIX[Y][X].x = X;
				// PIX[Y][X].y = Y;
				PIX[Y][X].z = ft_atoi(line + k);
				while ((ft_isdigit(line[k]) || line[k] == '-') && line[k + 1])
					k++;
				if (line[k] == ',')
				{
					PIX[Y][X].color = ft_atoi_b(line + k + 1, 16);
					ft_insert(PIX[Y][X].color != 0, "Program stopped : malloc of pix.color failed");
				}
			}
			k++;
		}
		
	}
	ft_insert(close(FD) != -1, "Close error : Couldn't close the file.");
	ft_strdel(&line);
}
