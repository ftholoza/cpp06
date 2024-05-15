# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francesco <francesco@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 07:04:09 by francesco         #+#    #+#              #
#    Updated: 2024/04/25 17:58:11 by francesco        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror -Wshadow -Wno-shadow
SRC = Serializer.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = Serializer

all : $(NAME)

re :fclean $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
clean :
	rm -f $(OBJ)
fclean: clean
	rm -rf $(NAME)