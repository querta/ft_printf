NAME = libftprintf.a
LIBFT = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h

LIBFT_DIR = src/libft/
SRC_DIR = src/

SRC = ft_printf.c

# SRC_BONUS = 

OBJ = $(SRC_DIR)$(SRC:.c=.o)

# OBJ_BONUS = $(SRC_BONUS:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o) 

$(NAME):	$(OBJ)
		make -C $(LIBFT_DIR)
		cp $(LIBFT_DIR)$(LIBFT) .
		mv $(LIBFT) $(NAME)
		ar -rc $(NAME) $(OBJ)

all:	$(SRC_DIR) $(NAME)

# bonus:	$(OBJ) $(OBJ_BONUS)
# 		ar -rc $(NAME) $(OBJ) $(OBJ_BONUS)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ) $(OBJ_BONUS)

# make fclean -C src/libft
fclean: clean
		rm -f $(LIBFT_DIR)$(LIBFT)
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
