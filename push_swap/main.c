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

#include "libft/libft.h"

int	push_swap(int argc, char **argv);

int	main(int argc, char **argv)
{
	int	error;

	if (argc == 1)
		return (-1);
	error = push_swap(--argc, ++argv);
	if (error == -1)
		ft_putendl_fd("Error", 1);
	return (error);
}
