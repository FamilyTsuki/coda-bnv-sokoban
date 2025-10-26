# Makefile

NAME = sokoban

SRCS = main.c \
affichage.c\
defaite.c\
dep.c\
init.c\
victoire.c\
verifi_defait.c\
free.c


all: $(NAME)

$(NAME): $(SRCS)
	gcc $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all