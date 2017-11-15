##
## Makefile for make in /rendu/rendu_Systeme_Unix/PSU_2015_my_ls
##
## Made by munoz david
## Login   <munoz_d@epitech.net>
##
## Started on  Thu Nov 26 22:59:46 2015 munoz david
## Last update Thu Mar 31 14:24:52 2016 David Munoz
##

NAME	= mysh

OBJ	= $(addprefix src/, $(SRC:.c=.o))

SRC	= main.c		\
	  my_command.c		\
	  my_path.c		\
	  my_free.c		\
	  my_fonctions.c	\
	  my_av.c		\
	  my_exe.c

TMP	= $(SRC:.c=.c~)

CC	= gcc

RM 	= rm -f

CFLAGS	= -W -Wall -Werror -ansi -pedantic -I./include/ -I/home/${USER}/.froot/include

CFLAGS	+= -L./lib/my/ -lmy

DIR	= lib/my

$(NAME): $(OBJ)
	cd $(DIR) && $(MAKE)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
	@echo "\033[1;32m[Minishell1] : Program compilated\n\033[0m"

all: $(NAME)

clean:
	$(RM) $(OBJ) $(TMP)
	cd $(DIR) && $(MAKE) clean
	@echo "\033[1;31m[Minishell1] : Binary files deleted\n\033[0m"

fclean:
	$(RM) $(OBJ) $(TMP) $(NAME)
	cd $(DIR) && $(MAKE) clean
	@echo "\033[1;31m[Minishell1] : Binary and executable files are deleted\n\033[0m"

re: lib fclean all

.PHONY: all clean fclean re lib
