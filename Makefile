# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctilda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/29 19:49:47 by ctilda            #+#    #+#              #
#    Updated: 2020/12/29 19:49:51 by ctilda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror -c

SRC = ./libft/*.c ./src/*.c ./specifiers/*.c
OBJ = *.o
LIB_PATH = ./libft
INCLUDES = ./includes

all: $(NAME)

$(NAME):
	make re -C $(LIB_PATH)
	$(CC) $(CFLAGS) $(SRC) -I $(INCLUDES)
	ar rc $(NAME) $(OBJ) $(LIB_PATH)/*.o
	ranlib $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C $(LIB_PATH)

fclean: clean

	rm -rf $(NAME)
	make clean -C $(LIB_PATH)

re: fclean all

.PHONY: all clean fclean re