NAME=fdf
CC = cc
SRC = \
	./src/main.c \

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -I/usr/include -I./includes -Imlx_linux -Ift -O3 -g -fsanitize=address -c $< -o $@

$(NAME): $(OBJ) libft
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -Ift -lXext -lX11 -lm -lz -L./lib -lft -g -fsanitize=address -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf ./lib/libft.a
	make -C ./lib/LibFT fclean

re: fclean all

all: $(NAME)

libft:
	make -C ./lib/LibFT
	cp ./lib/LibFT/libft.a ./lib/libft.a

dev :
	make fclean
	git add .; git commit -m "auto/dev"; git push
	make all

PHONY: all clean fclean re dev