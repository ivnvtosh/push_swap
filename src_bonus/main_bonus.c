/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:58:08 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/19 19:58:09 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	checker(int count, char **numbers);

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	checker(--argc, ++argv);
	return (10);
}
