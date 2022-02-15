/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:11:41 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/15 16:11:47 by ccamie           ###   ########.fr       */
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
}
