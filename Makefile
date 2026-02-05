# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hecakir <hecakir@student.42kocaeli.com.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/03 10:21:07 by hecakir           #+#    #+#              #
#    Updated: 2026/02/05 15:48:55 by hecakir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	ftprintf.a

SRC	=	ft_str.c\
		ft_char.c\


OBJ	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	cc -Wall -Werror -Wextra -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re