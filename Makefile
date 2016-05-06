# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atoupart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/04 17:16:34 by atoupart          #+#    #+#              #
#    Updated: 2016/05/04 17:16:37 by atoupart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= fdf

CC		= gcc
RM		= /bin/rm -rf

CFLAGS	= -Wall -Wextra -Werror 

FRAME	= -framework OpenGL -framework AppKit

HEADER	= fdf.h

FILES	= test.c

SRC		= $(addprefix src/, $(FILES))

OBJ		= $(SRC:src/%.c=.obj/%.o)

INC		= -I . -I libft

LIB		= -L libft -L libmlx -lft -lmlx

all:	$(NAME)

$(NAME): make_libft $(OBJ)
	$(CC) -g $(CFLAGS) $(FRAME)  $(OBJ) -o $(NAME) $(INC) $(LIB) 

.obj/%.o: src/%.c
	mkdir -p .obj
	$(CC) -c $< -o $@ $(CFLAGS) $(INC)

make_libft:
	make -C ./libmlx/
	make -C ./libft/

clean:
	make -C ./libft/ clean
	$(RM) .obj


fclean: clean
	make -C ./libft/ fclean
	make -C ./libmlx/ clean
	$(RM) $(NAME)

re: fclean all

norme:
	norminette $(FILES) $(HEADER)

function:
	nm -u $(NAME)

.PHONY: all make_libft clean fclean re norme

