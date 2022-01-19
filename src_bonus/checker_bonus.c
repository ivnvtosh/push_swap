/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:57:53 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/19 19:57:55 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*parser(int *count, char **numbers);

void	checker(int count, char **numbers)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = parser(&count, numbers);
	stack_b = NULL;
	terminate(stack_a, stack_b, 0);
}
