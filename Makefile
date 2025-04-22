NAME = fdf
CC = cc
SRC = \
	./src/main.c \
	./src/draw/calculate_draw.c \
	./src/draw/draw.c \
	./src/draw/mlx_draw.c \
	./src/draw/project_draw_opti.c \
	./src/draw/projection_draw.c \
	./src/get_next_line/get_next_line_utils.c \
	./src/get_next_line/get_next_line.c \
	./src/hooks/hooks.c \
	./src/initialization/init.c \
	./src/initialization/parse.c \
	./src/utils/utils.c \

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -I./includes -Imlx_linux -Ift -O3 -c $< -o $@

$(NAME): $(OBJ) libft
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -Ift -lXext -lX11 -lm -lz -L./libs/LibFT -lft -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C ./libs/LibFT/ fclean

re: fclean all

all: $(NAME)

libft:
	make -C ./libs/LibFT/

dev :
	make fclean
	git add .; git commit -m "auto/dev"; git push
	make all

PHONY: all clean fclean re dev