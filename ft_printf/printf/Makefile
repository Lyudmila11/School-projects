# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldon <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 13:39:35 by ldon              #+#    #+#              #
#    Updated: 2024/01/31 16:08:50 by ldon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_putchar.c ft_printf.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)
$(OBJ) : $(SRC)
	$(CC) -c $(SRC) $(FLAGS)

clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re
