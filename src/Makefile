
NAME		=	../push_swap
HEADER		=	   push_swap.h

LIBFT		=	../libft/libft.a
LIBST		=	../libst/libst.a

SRCS		=	action.c				\
				check.c					\
				convert_to_indexes.c	\
				main.c					\
				parser.c				\
				push_swap.c				\
				sort.c					\
				terminate.c

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
