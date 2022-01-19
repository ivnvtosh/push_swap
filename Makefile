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

.PHONY		:	all clean fclean re bonus rebonus libft

all			:	libft
				make -C src all

bonus		:	libft
				make -C src_bonus all

libft		:
				make -C libft bonus

clean		:
				$(RM) $(OBJS)
				make -C libft clean
				make -C src clean
				make -C src_bonus clean

fclean		:	clean
				$(RM) $(NAME)
				make -C libft fclean
				make -C src fclean
				make -C src_bonus fclean
				
re			:	fclean all

rebonus		:	fclean bonus
