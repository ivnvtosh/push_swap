/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:17:53 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/26 19:17:56 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "../libft/libft.h"

void	terminate(t_stack *a, t_stack *b, int code);

void	evaluate_stack(t_stack *a, t_stack *b)
{
	t_stack	*start;

	if (b != NULL)
		terminate(a, b, 3);
	start = a;
	while (a->next != start && a->number < a->next->number)
		a = a->next;
	if (a->next != start)
		terminate(start, b, 3);
}
