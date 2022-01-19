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

void	push_swap(int count, char **numbers);

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	push_swap(--argc, ++argv);
	return (10);
}
