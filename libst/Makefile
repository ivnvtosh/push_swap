
NAME		=	libst.a
HEADER		=	libst.h

SRCS		=	stack_add_bottom.c	\
				stack_add_top.c		\
				stack_clear.c		\
				stack_delone.c		\
				stack_duplicate.c	\
				stack_get_bottom.c	\
				stack_get_max.c		\
				stack_get_mid.c		\
				stack_get_min.c		\
				stack_get_height.c	\
				stack_get_new.c		\
				stack_print.c		\
				stack_push.c		\
				stack_rotate.c		\
				stack_swap.c

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar
ARFLAGS		=	crs
RM			=	rm -f

OBJS		=	$(SRCS:.c=.o)

.PHONY		:	all clean fclean re

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(AR) $(ARFLAGS) $(NAME) $?

%.o			:	%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all
