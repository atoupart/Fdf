/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 18:58:47 by atoupart          #+#    #+#             */
/*   Updated: 2016/05/14 18:58:53 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"


void	ft_launch_mlx

int		z_here(char *s, int n)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[k])
	{
		if (ft_isdigit(s[k]) || s[k] == 45)
		{
			i++;
			if (i == n + 1)
			{
				return (ft_atoi(s + k));
			}
			while ((ft_isdigit(s[k]) || s[k] == 45) && s[k + 1])
				k++;
		}
		k++;
	}
	return (0);
}
