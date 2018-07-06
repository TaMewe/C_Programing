##
## EPITECH PROJECT, 2018
## my_rpg_2017
## File description:
## Makefile
##

NAME	=	my_rpg

SRCS	=	src/window.c	\
		src/map.c	\
		src/fill_sprite.c	\
		src/ini_sprite.c	\
		src/mov_anim.c	\
		src/hero.c	\
		src/mob.c	\
		src/tools.c	\
		src/tools2.c	\
		src/stat.c	\
		src/list.c	\
		src/list2.c	\
		src/event.c	\
		src/control.c	\
		src/main.c	\
		src/fight.c	\
		src/fight_HUD.c	\
		src/fight_function.c	\
		src/use.c	\
		src/swap_zone1-5.c	\
		lib/my/my_strlen.c      \
		lib/my/my_putstr.c      \
		lib/my/my_putchar.c     \
		lib/my/my_strcpy.c      \
		lib/my/my_strcmp.c	\
		lib/my/my_get_str_nbr.c	\
		lib/my/my_revstr.c	\
		src/menu/menu.c \
                src/menu/bg.c   \
                src/menu/leaf.c \
                src/menu/ini_leaf.c     \
                src/menu/cloud.c        \
                src/menu/ff.c		\
		src/menu_quit.c	\
		src/damage_string.c	\
		src/map_alloc.c	\
		src/map_specificities.c	\
		src/inventory/inventory.c	\
		src/inventory/inventory_effect.c	\
		src/music.c	\

OBJS	=	$(SRCS:.c=.o)

CFLAGS  +=      -Iinclude -Wall -Wextra -Werror #-g3

all:		$(NAME)

$(NAME): $(OBJS)
	gcc $(OBJS) -o $(NAME) -l c_graph_prog
#	@tput setaf 5; cat include/signature; tput sgr0

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)
	rm -rf src/*~
	rm -rf src/*#

re:	fclean all

.PHONY:	all clean fclean re
