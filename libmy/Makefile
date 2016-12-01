##
## Makefile for Libmy
## 
## Made by BALSSA Victor
## Login   <balssa_v@etna-alternance.net>
## 
## Started on  Fri Oct 23 19:08:32 2015 BALSSA Victor
## Last update Fri Nov 25 19:52:05 2016 BALSSA Victor
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
		tablen.c

OBJ = 		$(SRC:%.c=%.o)

CFLAGS = 	-Wall -Werror -W -Wextra

all: 		$(NAME)

$(NAME):
		@echo "-> Creation de la Libmy ..."
		gcc -c $(CFLAGS) $(SRC)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
		rm -f $(OBJ)

fclean:
		rm -f $(NAME)
