SRC_CLIENT=client.c
SRC_SERVER=server.c
CC=cc
FLAGS=-Wall -Werror -Wextra
LIBFT=libft/libft.a
NAME_C=client
NAME_S=server

all: $(NAME_C) $(NAME_S)

$(NAME_C): $(SRC_CLIENT)
	make -C libft
	$(CC) $(FLAGS) $(SRC_CLIENT) $(LIBFT) -o $(NAME_C)

$(NAME_S): $(SRC_SERVER)
	make -C libft
	$(CC) $(FLAGS) $(SRC_SERVER) $(LIBFT) -o $(NAME_S)

clean:
	make clean -C libft

fclean: clean
	make fclean -C libft 
	rm -rf $(NAME_C) $(NAME_S)

re: fclean all
