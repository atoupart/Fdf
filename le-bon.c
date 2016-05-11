
#include "../fdf.h"

int	ft_exit(int keycode, void *param)
{
	param = 0;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int	main(void)
{
	t_env *env;

	env = (t_env*)ft_memalloc(sizeof(t_env));


	MLX = mlx_init();
	WIN = mlx_new_window(MLX, 500, 500, "testit");
	mlx_key_hook(WIN, ft_exit, 0);
	IMAGE = mlx_new_image(MLX, 500, 500);
	

	PIX = mlx_get_data_addr(IMAGE, &BPP, &SL, &env->endian);
	COLOR =	mlx_get_color_value(MLX, 0xFFFFFF);


	Y = 0;
	while (Y <= 110)
	{
		X = 0;
		while (X <= 110)
		{
			*(unsigned int *)(PIX + (BPP / 8 * X + SL * Y)) = COLOR;
			X++;
		}
		Y++;
	}
	*(unsigned int *)(PIX + (BPP / 8 * X + SL * Y)) = 0xFF0000;

	mlx_put_image_to_window(MLX, WIN, IMAGE, 0, 0);

	mlx_loop(MLX);
	return(0);
}	
	
// le bon !