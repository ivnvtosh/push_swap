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

.PHONY		:	all clean fclean re bonus rebonus libft libst

all			:	libft libst
				make -C src

# bonus		:	libft libst
# 				make -C src_bonus

libft		:
				make -C libft bonus

libst		:
				make -C libst

clean		:
				make -C src clean
#				make -C src_bonus clean
				make -C libft clean
				make -C libst clean

fclean		:
				$(RM) $(NAME)
				make -C src fclean
#				make -C src_bonus fclean
				make -C libft fclean
				make -C libst clean
				
re			:	fclean all

rebonus		:	fclean bonus
