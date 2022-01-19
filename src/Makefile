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
HEADER_L	=	../libft/libft.h

SRCS		=	action.c	\
				handsort.c	\
				main.c		\
				parser.c	\
				print.c		\
				push_swap.c	\
				push.c		\
				rotate.c	\
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
				$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME)

%.o			:	%.c $(HEADER) $(HEADER_L) $(LIBFT)
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)
				
re			:	fclean all
