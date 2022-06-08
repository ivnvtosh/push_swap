/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:19:39 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/16 17:19:40 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	checker(char **numbers);

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (NOTHING);
	checker(++argv);
	return (GOOD);
}
