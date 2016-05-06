# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 10:08:38 by atoupart          #+#    #+#              #
#    Updated: 2016/03/14 19:21:07 by ebaudet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

CC		= gcc
RM		= /bin/rm -rf

CFLAGS	= -Wall -Wextra -Werror

FILES	= main.c\
		ft_error.c\
		ft_openfile_checker.c\
		ft_checkform.c\
		ft_checktab.c\
		ft_transfert_tab_tetri.c\
		ft_checktetri.c\
		ft_resolution_tetri.c\
		ft_search_y_min.c\
		ft_search_y_max.c\
		ft_search_x_min.c\
		ft_search_x_max.c\
		ft_reduce_tetri.c\
		recursive_try.c\
		ft_verif_put.c\
		put_piece.c\
		print_solution.c\
		retire_piece.c\
		init_square.c\
		ft_free_data.c\
		free_square.c
SRC		= $(addprefix src/, $(FILES))
OBJ		= $(SRC:src/%.c=.obj/%.o)

INC		= -I . -I libft
LIB		= -L libft -lft

all: $(NAME)

$(NAME): make_libft $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INC) $(LIB)

.obj/%.o: src/%.c
	mkdir -p .obj
	$(CC) -c $< -o $@ $(CFLAGS) $(INC)

make_libft:
	make -C libft

clean:
	$(RM) .obj

fclean: clean
	$(RM) $(NAME)

re: fclean all

lldb:
	cc $(CFLAGS) $(SRC) -o $(NAME) $(INC) $(LIB)

.PHONY: all clean fclean re lldb
