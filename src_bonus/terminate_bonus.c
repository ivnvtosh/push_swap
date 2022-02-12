/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 05:18:25 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/13 05:18:26 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include <stdlib.h>

void	clean(t_stack *stack);

void	leave(int code)
{
	if (code == 5)
		ft_putstr_fd("OK\n", 1);
	else if (code == 3)
		ft_putstr_fd("KO\n", 1);
	else if (code)
		ft_putstr_fd("Error\n", 2);
	exit(code);
}

static int	check(t_stack *a, t_stack *b)
{
	char	*s;

	s = get_next_line(0);
	if (s == NULL)
	{
		return (5);
	}
	else
	{
		free(s);
		return (3);
	}
}

void	terminate(t_stack *a, t_stack *b, int code)
{
	if (code == 10)
		code = check(a, b);
	clean(a);
	clean(b);
	leave(code);
}
