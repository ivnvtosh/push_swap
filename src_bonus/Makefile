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

NAME		=	../checker
HEADER		=	   checker_bonus.h

LIBFT		=	../libft/libft.a

GNL			=	../get_next_line/get_next_line_utils.c	\
				../get_next_line/get_next_line.c
HEADER_GNL	=	../get_next_line/get_next_line.h

SRCS		=	action_bonus.c			\
				apply_commands_bonus.c	\
				checker_bonus.c			\
				evaluate_stack_bonus.c	\
				main_bonus.c			\
				parse_commands_bonus.c	\
				parser_bonus.c			\
				push_bonus.c			\
				rotate_bonus.c			\
				swap_bonus.c			\
				terminate_bonus.c		\
				utils_bonus.c

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

OBJS		=	$(SRCS:.c=.o) $(GNL:.c=.o)

.PHONY		:	all clean fclean re

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(LIBFT) $(OBJS) -o $(NAME)

%.o			:	%.c $(HEADER) $(HEADER_GNL) $(LIBFT)
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all
