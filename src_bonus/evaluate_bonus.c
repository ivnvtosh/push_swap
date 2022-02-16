/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:06:45 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/16 19:06:46 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	evaluate(t_stack *a, t_stack *b)
{
	t_stack	*start;

	if (b != NULL)
		terminate(ERROR);
	while (a->prev != NULL && a->value < a->prev->value)
		a = a->prev;
	if (a->prev != NULL)
		terminate(ERROR);
}