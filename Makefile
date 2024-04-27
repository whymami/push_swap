NAME = push_swap
BONUS_NAME = checker
LIBFT_PATH = lib/libft
PRINTF_PATH = lib/ft_printf
LIBFT = $(LIBFT_PATH)/libft.a
PRINTF = $(PRINTF_PATH)/libftprintf.a

SRC = \
	bubble_sort/main.c bubble_sort/utils.c \
	bubble_sort/ft_sort.c \
	bubble_sort/operations/action_push.c \
	bubble_sort/operations/action_rotate.c \
	bubble_sort/operations/action_rrotate.c \
	bubble_sort/operations/action_swap.c \
	bubble_sort/big_sort.c bubble_sort/utils1.c bubble_sort/utils2.c bubble_sort/ft_control.c

BONUS_SRC = \
	bonus/main_bonus.c\
	bonus/handler_bonus.c\
	bonus/utils_bonus.c\
	bonus/utils1_bonus.c\
	bonus/operations_bonus/action_push_bonus.c\
	bonus/operations_bonus/action_rotate_bonus.c\
	bonus/operations_bonus/action_rrotate_bonus.c\
	bonus/operations_bonus/action_swap_bonus.c\
	lib/getnextline/get_next_line.c \
	lib/getnextline/get_next_line_utils.c \

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

bonus: $(BONUS_OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) $(PRINTF) -o $(BONUS_NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(PRINTF):
	$(MAKE) -C $(PRINTF_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(PRINTF_PATH) clean
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(PRINTF_PATH) fclean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all bonus

.PHONY: all clean fclean re
