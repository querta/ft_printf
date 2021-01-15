NAME = libftprintf.a
LIBFT = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h

LIBFT_DIR = src/libft/
SRC_DIR = src/

SRC = ft_printf.c parser.c utilities.c processor.c

OBJ =	$(addprefix $(SRC_DIR), $(SRC:.c=.o)) 


all:	$(SRC_DIR) $(NAME)

$(NAME):	$(OBJ)
		make -C $(LIBFT_DIR)
		cp $(LIBFT_DIR)$(LIBFT) .
		mv $(LIBFT) $(NAME)
		ar -rc $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o) 

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
		rm -f $(LIBFT_DIR)$(LIBFT)
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
