################
pour verifier que  av[1] est bien un .fdf
###############


int				**ft_init(char *map)
{
	int			fd;
	int			**matrix;

	if (0)
		ft_ext(map, ".fdf");

void		ft_ext(char *file, char *ext)
{
	int		file_len;
	int		ext_len;

	file_len = ft_strlen(file);
	ext_len = ft_strlen(ext);
	while (--ext_len >= 0)
	{
		if (file[--file_len] != ext[ext_len])
		{
			ft_putstr_fd(file, 2);
			ft_putstr_fd(" : File must have ", 2);
			ft_putstr_fd(ext, 2);
			ft_exit(" extension.\n");
		}
	}
}
un ft_strcmp puisse etre plus simple..

##############
utiliser une fonction derreur avec insertion de phrase
##############
void	ft_assert(int check, char *str)
{
	if (!check)
	{
		ft_exit(str);
		ft_putstr_fd(str, 2);
		exit(0);
	}
}