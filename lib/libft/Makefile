NAME = libft.a
SRC = \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstlast.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_atoi.c \
	ft_isdigit.c \
	ft_strlen.c \
	ft_swap.c \
	ft_strjoin.c \
	ft_split.c \
	ft_calloc.c \
	ft_strlcpy.c \

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(LIBC) $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


