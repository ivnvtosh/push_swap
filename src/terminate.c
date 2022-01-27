/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 05:18:25 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/13 05:18:26 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	clean(t_stack *stack);

void	leave(int code)
{
	if (code)
		ft_putstr_fd("Error\n", 2);
	exit(code);
}

void	terminate(t_stack *a, t_stack *b, int code)
{
	clean(a);
	clean(b);
	leave(code);
}
