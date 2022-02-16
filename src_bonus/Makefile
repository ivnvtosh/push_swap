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

NAME		=	../checker
HEADER		=	   checker.h

LIBFT		=	../libft/libft.a
LIBST		=	../libst/libst.a
LIBGNL		=	../libgnl/libgnl.a

SRCS		=	action_bonus.c		\
				apply_comm_bonus.c	\
				check_bonus.c		\
				checker_bonus.c		\
				evaluate_bonus.c	\
				main_bonus.c		\
				parse_comm_bonus.c	\
				parse_num_bonus.c	\
				terminate_bonus.c

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

OBJS		=	$(SRCS:.c=.o)

.PHONY		:	all clean fclean re

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(LIBFT) $(LIBST) $(LIBGNL) $(OBJS) -o $(NAME)

%.o			:	%.c $(HEADER) $(LIBFT) $(LIBST) $(LIBGNL)
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)
				
re			:	fclean all
