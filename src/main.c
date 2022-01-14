/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:59:08 by ccamie            #+#    #+#             */
/*   Updated: 2021/12/26 12:59:10 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	push_swap(int argc, char **argv);
void	error(const char *s, int code);

int	main(int argc, char **argv)
{
	if (argc == 1)
		error("enter the numbers.", -1);
	if (argc == 2)
		error("enter more numbers.", -1);
	push_swap(--argc, ++argv);
	return (0);
}
