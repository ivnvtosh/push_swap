/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:14:25 by ccamie            #+#    #+#             */
/*   Updated: 2021/12/25 18:14:28 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

t_stack	*parser(int *count, char **numbers);
void	sort(t_stack **a, t_stack **b, int count);
void	terminate(t_stack *a, t_stack *b, int code);

void	push_swap(int count, char **numbers)
{
	t_stack	*a;
	t_stack	*b;

	a = parser(&count, numbers);
	b = NULL;
	sort(&a, &b, count);
	terminate(a, b, 0);
}
