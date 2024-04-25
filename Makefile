NAME = push_swap
LIBFT_PATH = lib/libft
PRINTF_PATH = lib/ft_printf
LIBFT = $(LIBFT_PATH)/libft.a
PRINTF = $(PRINTF_PATH)/libftprintf.a

SRC = \
	main.c utils.c \
	ft_sort.c \
	operations/action_push.c \
	operations/action_rotate.c \
	operations/action_rrotate.c \
	operations/action_swap.c \
	big_sort.c utils1.c utils2.c ft_control.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(PRINTF):
	$(MAKE) -C $(PRINTF_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(PRINTF_PATH) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(PRINTF_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
