/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:10:35 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/15 16:10:38 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	check_for_digit(char **num)
{
	int	i;
	int	j;

	j = 0;
	while (num[j])
	{
		i = 0;
		if (num[j][i] == '-')
			i++;
		if (num[j][i] == '\0')
			terminate(ERROR);
		while (ft_isdigit(num[j][i]))
			i++;
		if (num[j][i] != '\0')
			terminate(ERROR);
		j++;
	}
}

void	check_for_range_int(char **num)
{
	long	n;
	int		i;

	i = 0;
	while (num[i])
	{
		n = atol(num[i]);
		if (n < -__INT_MAX__ - 1 || n > __INT_MAX__)
			terminate(ERROR);
		i++;
	}
}

void	check_for_duplicates(t_stack *stack)
{
	t_stack	*check;

	while (stack != NULL)
	{
		check = stack;
		stack = stack->prev;
		while (stack != NULL)
		{
			if (check->value == stack->value)
				terminate(ERROR);
			stack = stack->prev;
		}
		stack = check->prev;
	}
}

void	check_for_sorted(t_stack *stack)
{
	while (stack->prev != NULL && stack->value < stack->prev->value)
		stack = stack->prev;
	if (stack->prev == NULL)
		exit(NOTHING);
}
