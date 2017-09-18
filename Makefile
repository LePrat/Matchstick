##
## Makefile for my_exec in /root/Delivery/CProg_Elem/CPE_2016_BSQ
## 
## Made by root
## Login   <kentin.pratelli@epitech.eu>
## 
## Started on  Tue May  2 13:21:14 2017 root
## Last update Mon Sep 18 15:16:25 2017 root
##

CC      =       gcc

RM	=	rm -f

CFLAGS  +=	-W -Wextra -Wall -I ./include/

NAME    =       matchstick

SRCS    =	./src/print_board.c	\
		./src/display.c		\
		./src/get_next_line.c	\
		./src/data.c		\
		./src/marienbad.c	\
		./src/marienbad2.c	\
		./src/free.c		\
		./src/main.c

OBJS	=	$(SRCS:.c=.o)


all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
