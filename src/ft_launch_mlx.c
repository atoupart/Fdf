/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 12:14:16 by atoupart          #+#    #+#             */
/*   Updated: 2016/05/14 12:14:19 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	launch_mlx(t_env *env, int width, int height)
{
	WIDTH = (width > 0 ? width : 1000);
	HEIGHT = (height > 0 ? height : WIDTH);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIDTH, HEIGHT, "FDF");
	mlx_key_hook(WIN, ft_key, env);
	


}
