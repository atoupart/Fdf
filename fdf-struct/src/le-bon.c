
#include <fdf.h>
#include <ft_fc_tests.h>
#include <ft_fc_print.h>
#include <get_next_line.h>
#include <stdlib.h>

static int		get_elem_nb(char *str)
{
	int			nb;

	nb = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
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

static int		*fill_line(int *matrix, char *values)
{
	int			*tmp;
	int			val;

	tmp = matrix;
	while (*values && *tmp != -999)
	{
		if (ft_isdigit(*values))
		{
			val = 0;
			while (ft_isdigit(*values))
				val = (val * 10) + (*values++ - '0');
			*tmp++ = val;
		}
		else
			++values;
	}
	return (matrix);
}

int				**create_matrix(int fd)
{
	int			lines;
	char		*actline;
	int			**matrix;

	lines = 0;
	while ((actline = get_next_line(fd)))
		++lines;
	matrix = (int **)malloc((lines + 1) * sizeof(int *));
	ft_assert(matrix != NULL, "Malloc error on matrix, exiting...\n");
	matrix[lines] = NULL;
	return (matrix);
}

int				**fill_matrix(int fd, int **matrix)
{
	int			elems;
	int			i;
	char		*line;

	i = 0;
	while ((line = get_next_line(fd)))
	{
		elems = get_elem_nb(line);
		matrix[i] = (int *)malloc((elems + 1) * sizeof(int));
		ft_assert(matrix[i] != NULL, "Malloc error on matrix, exiting...\n");
		matrix[i][elems] = -999;
		matrix[i] = fill_line(matrix[i], line);
		++i;
	}
	return (matrix);
}

void			print_matrix(int **matrix)
{
	int			x;
	int			y;

	ft_putstr("===================\n");
	x = -1;
	while (matrix[++x])
	{
		y = -1;
		while (matrix[x][++y] != -999)
		{
			ft_putstr("| ");
			ft_putnbr(matrix[x][y]);
			ft_putstr(" ");
		}
		ft_putstr("|\n");
	}
	ft_putstr("===================\n");
}


int			ft_open(char *file, int mode)
{
	int		fd;

	ft_assert(file != NULL, "File error : Couldn't retrive the filename.\n");
	if ((fd = open(file, mode)) == -1)
	{
		ft_putstr_fd("File error : Couldn't open \033[33m", 2);
		ft_putstr_fd(file, 2);
		ft_exit("\033[0m.\n");
	}
	return (fd);
}

void		ft_close(int fd)
{
	ft_assert(close(fd) != -1, "File error : Couldn't close the file.\n");
}

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

int				**ft_init(char *map)
{
	int			fd;
	int			**matrix;

	if (0)
		ft_ext(map, ".fdf");
	fd = ft_open(map, O_RDWR);
	matrix = create_matrix(fd);
	ft_close(fd);
	fd = ft_open(map, O_RDONLY);
	matrix = fill_matrix(fd, matrix);
	return (matrix);
}
