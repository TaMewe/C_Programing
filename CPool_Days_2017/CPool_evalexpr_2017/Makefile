##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## 
##

NAME	=	eval_expr

SRCS	=	/lib/my/my_putchar.c	\
		/lib/my/my_put_nbr.c	\
		/lib/my/my_swap.c	\
		/lib/my/my_strlen.c	\
		/lib/my/my_revstr.c

OBJS	= $(SRCS:.c=.o)

all: compile clean

compile:
	gcc eval_expr.c -o eval_expr -L. -lmy 

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm *.gcno
	rm *.gcda

re: clean fclean all 

.PHONY: all clean fclean
