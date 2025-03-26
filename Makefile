NAME = so_long
CC = cc
CFLAGS = -Werror -Wextra -Wall -fsanitize=address -g

SRC = so_long.c \
	  utils/Error_hand.c \
	  utils/check_map.c \
	  utils/fill.c \
	  utils/ft_strcmp.c \
	  utils/ft_strlen.c \
	  utils/ft_strrchr.c \
	  get_next_line/get_next_line_utils.c \
	  get_next_line/get_next_line.c 

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)  -o $(NAME)

clean:
	@rm -f $(OBJ) $(GNL_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re