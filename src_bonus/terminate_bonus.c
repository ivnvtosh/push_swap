/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:23:40 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/16 18:23:43 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdlib.h>

void	terminate(int code)
{
	if (code == ERROR)
		ft_putstr_fd("Error\n", 2);
	exit(code);
}
