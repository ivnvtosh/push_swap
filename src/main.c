/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:11:02 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/15 16:11:05 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int count, char **num);

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (NOTHING);
	push_swap(--argc, ++argv);
	return (GOOD);
}
