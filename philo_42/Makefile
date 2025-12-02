NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread

SRC = 	actions.c\
		init.c\
		main.c\
		monitor.c\
		parser.c\
		simulation.c\
		time.c\
		utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c philosophers.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -fv $(OBJ)

fclean: clean
	@rm -fv $(NAME)

re: fclean all

.PHONY: all clean fclean re