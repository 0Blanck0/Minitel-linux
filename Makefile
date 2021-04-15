##
## ETNA PROJECT, 24/02/2021
## Makefile
## File description:
##      Makefile for myMinitel
##

NAME = myMinitel
SRCS =  ./src/main.c\
        ./src/bash.c\
        ./src/menu.c\
        ./src/display.c

LIB_NAME = ./lib/libmy.a
CC = gcc
FLAGS = -Wall -Wextra -std=c11 -c -g
RM = rm -rf

SRCS_LIB = ./lib/my/my_putchar.c\
                ./lib/my/my_putstr.c\
                ./lib/my/my_strlen.c\
                ./lib/my/my_getnbr.c\
                ./lib/my/my_putnbr.c\
                ./lib/my/my_isneg.c\
                ./lib/my/my_swap.c\
                ./lib/my/my_strcpy.c\
                ./lib/my/my_strncpy.c\
                ./lib/my/my_strcmp.c\
                ./lib/my/my_strncmp.c\
                ./lib/my/my_strcat.c\
                ./lib/my/my_strncat.c\
                ./lib/my/my_strstr.c\
                ./lib/my/my_strdup.c\
                ./lib/my/my_str_to_word_array.c\
                ./lib/my/my_strchr.c\
                ./lib/my/my_subremove.c\


OBJS_LIB = $(SRCS_LIB:.c=.o)

all: $(NAME)

$(LIB_NAME):
	$(CC) $(FLAGS) $(SRCS_LIB) -I./include/
	mv *.o ./lib/my
	ar rc $(LIB_NAME) $(OBJS_LIB)
	ranlib $(LIB_NAME)

$(NAME): $(LIB_NAME) $(SRCS_LIB)
	gcc $(SRCS) -Wall -Wextra -Werror -std=c11 -g -L./lib -lmy -o $(NAME)

clean:
	rm -rf $(OBJS_LIB)

fclean: clean
	rm -rf $(LIB_NAME)
	rm -rf $(NAME)

re: fclean all

.PHONY: clean, fclean, re