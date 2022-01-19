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

NAME		=		push_swap
HEADER		=	src/push_swap.h
HEADER_B	=

LIBFT		=	libft/libft.a

SRCS		=	src/action.c	\
				src/handsort.c	\
				src/main.c		\
				src/parser.c	\
				src/print.c		\
				src/push_swap.c	\
				src/push.c		\
				src/rotate.c	\
				src/swap.c		\
				src/terminate.c	\
				src/utils.c
				
SRCS_B		=

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

OBJS		=	$(SRCS:.c=.o)
OBJS_B		=	$(SRCS_B:.c=.o)

.PHONY		:	all clean fclean re bonus rebonus libft

all			:	libft $(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME)

%.o			:	%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

libft	:
				make -C libft all

bonus		:	
				@make OBJS="$(OBJS_B)" HEADER="$(HEADER_B)" all

clean		:
				$(RM) $(OBJS) $(OBJS_B)
				make -C libft clean

fclean		:	clean
				$(RM) $(NAME)
				make -C libft fclean
				
re			:	fclean all

rebonus		:	fclean bonus
