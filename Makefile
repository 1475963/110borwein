##
## Makefile for make in /home/benzah_m//svn/git@github.com:1475963/110borwein.git
## 
## Made by marc benzahra
## Login   <benzah_m@epitech.net>
## 
## Started on  Mon Apr  8 15:31:25 2013 marc benzahra
## Last update Mon Apr  8 18:10:38 2013 marc benzahra
##

SRC	=	sources/main.c		\
		sources/borwein.c	\

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

CC	=	cc

NAME	=	110borwein

RESET=		\033[0m
BIG=		\033[1;01m
UNDERLINE=	\033[1;04m
BLINGBLING=	\033[1;05m
VIDEO=		\033[1;07m
C_BLACK=	\033[1;30m
C_RED=		\033[1;31m
C_GREEN=	\033[1;32m
C_ORANGE=	\033[1;33m
C_BLUE=		\033[1;34m
C_PINK=		\033[1;35m
C_GAYBLUE=	\033[1;36m
C_WHITE=	\033[1;37m
B_BLACK=	\033[1;40m
B_RED=		\033[1;41m
B_GREEN=	\033[1;42m
B_ORANGE=	\033[1;43m
B_BLUE=		\033[1;44m
B_PINK=		\033[1;45m
B_GAYBLUE=	\033[1;46m
B_WHITE=	\033[1;47m

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lm

clean:
	$(RM) $(OBJ) $(OBJ_SDL)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

unicorn:
	@clear
	@echo -e "$(C_PINK)"
	@cat pokedex/unicorn
	@echo -e "$(RESET)"

howto:	
	@echo -e "$(C_GAYBLUE)"
	@echo -e "$(BIG)"
	@cat usage/notice
	@echo -e "$(RESET)"

evo:
	@clear
	@echo -e "$(C_RED)"
	@echo -e "$(BLINGBLING)"
	@cat pokedex/004charmander
	@sleep 1
	@clear
	@cat pokedex/005charmeleon
	@sleep 1
	@clear
	@echo -e "$(RESET)"
	@echo -e "$(C_RED)"
	@cat pokedex/006charizard
	@sleep 1
	@echo -e "$(RESET)"