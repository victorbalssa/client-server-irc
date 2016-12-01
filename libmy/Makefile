##
## Makefile for Libmy
## 
## Made by BALSSA Victor
## Login   <balssa_v@etna-alternance.net>
## 
## Started on  Fri Oct 23 19:08:32 2015 BALSSA Victor
## Last update Thu Dec  1 21:12:39 2016 BALSSA Victor
##

NAME =		libmy.a
SRC = 		my_putchar.c \
		my_isneg.c \
		my_put_nbr.c \
		my_swap.c \
		my_putstr.c \
		my_putstr_fd.c \
		my_putnbr_fd.c \
		my_strlen.c \
		my_strcpy.c \
		my_strncpy.c \
		my_strcmp.c \
		my_strncmp.c \
		my_strcat.c \
		my_strncat.c \
		my_strstr.c \
		my_getnbr.c \
		my_strdup.c \
		my_bzero.c \
		tablen.c \
		my_str_to_wordtab.c \
		freetab.c

OBJ = 		$(SRC:%.c=%.o)

CFLAGS = 	-Wall -Werror -W -Wextra

all: 		$(NAME)

$(NAME):
		@echo "-> Compilation libmy.a ..."
		@gcc -c $(CFLAGS) $(SRC)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

clean:
		@echo "-> clean libmy ..."
		@rm -f $(OBJ)

fclean:
		@echo "-> fclean libmy ..."
		@rm -f $(NAME)
