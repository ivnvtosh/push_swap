# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccamie <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 15:45:41 by ccamie            #+#    #+#              #
#    Updated: 2021/10/18 15:45:43 by ccamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	../push_swap
HEADER		=	   push_swap.h

LIBFT		=	../libft/libft.a

SRCS		=	action.c	\
				get_mmm.c	\
				main.c		\
				parser.c	\
				print.c		\
				push_swap.c	\
				push.c		\
				quicksort.c	\
				replace.c	\
				rotate.c	\
				sort.c		\
				swap.c		\
				terminate.c	\
				utils.c

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

OBJS		=	$(SRCS:.c=.o)

.PHONY		:	all clean fclean re

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(LIBFT) $(OBJS) -o $(NAME)

%.o			:	%.c $(HEADER) $(LIBFT)
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)
				
re			:	fclean all
