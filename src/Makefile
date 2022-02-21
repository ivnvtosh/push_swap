# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccamie <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 16:11:11 by ccamie            #+#    #+#              #
#    Updated: 2022/02/15 16:11:15 by ccamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	../push_swap
HEADER		=	   push_swap.h

LIBFT		=	../libft/libft.a
LIBST		=	../libst/libst.a

SRCS		=	action.c				\
				apply_comm.c			\
				calculate.c				\
				check.c					\
				chunk.c					\
				convert_to_indexes.c	\
				justsort.c				\
				main.c					\
				parser.c				\
				push_swap.c				\
				recalculate.c			\
				search_best.c			\
				sort.c					\
				sorts.c					\
				terminate.c				\
				utils.c

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

OBJS		=	$(SRCS:.c=.o)

.PHONY		:	all clean fclean re

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(LIBFT) $(LIBST) $(OBJS) -o $(NAME)

%.o			:	%.c $(HEADER) $(LIBFT) $(LIBST)
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)
				
re			:	fclean all
