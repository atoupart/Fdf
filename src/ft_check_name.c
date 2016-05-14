/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 19:25:05 by atoupart          #+#    #+#             */
/*   Updated: 2016/05/14 19:25:08 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// a verifier si cela est focntionnel

void			ft_check_name(char *name, t_env *env)
{
	char *str = ".fdf";

	X = ft_strlen(name);
	Y = ft_strlen(str);
	while (--Y >= 0)
			ft_insert(name[--X] == str[Y], "Your file must end by <.fdf>\n");
}
