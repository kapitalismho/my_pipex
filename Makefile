# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salee <salee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/26 07:08:27 by salee             #+#    #+#              #
#    Updated: 2022/02/27 03:29:49 by salee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SOURCE = ./pipex_utils.c	\
./pipex_utils2.c			\
./pipex.c					\
./spilt.c					\
./strjoin.c					\

OBJECT = $(SOURCE:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJECT)
	gcc -Wall -Wextra -Werror $^ -o $@

%.o : %.c
	gcc -Wall -Wextra -Werror -c -o $@ $<

clean :
	rm -f $(OBJECT)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
