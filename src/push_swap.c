/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:11:41 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/08 04:09:03 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

t_stack	*parser(char **num);
void	sort(int count, t_stack **a, t_stack **b);

void	push_swap(int count, char **num)
{
	t_stack	*a;
	t_stack	*b;

	a = parser(num);
	b = NULL;
	sort(count, &a, &b);
	stack_clear(&a);
}
