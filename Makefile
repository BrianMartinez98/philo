# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brimarti <brimarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/02 15:37:01 by brimarti          #+#    #+#              #
#    Updated: 2025/12/02 15:37:02 by brimarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread

SRC = 	actions.c\
		init.c\
		main.c\
		monitor.c\
		parser.c\
		routine.c\
		timestamp.c\
		utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -fv $(OBJ)

fclean: clean
	@rm -fv $(NAME)

re: fclean all

.PHONY: all clean fclean re