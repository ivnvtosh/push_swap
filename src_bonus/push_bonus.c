/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:18:24 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/26 19:18:27 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "../libft/libft.h"

static void	disconnect(t_stack **from)
{
	if (*from == (*from)->next)
		*from = NULL;
	else
	{
		(*from)->next->prev = (*from)->prev;
		(*from)->prev->next = (*from)->next;
		(*from) = (*from)->next;
	}
}

static void	connect(t_stack *elem, t_stack **in)
{
	if (*in == NULL)
	{
		elem->next = elem;
		elem->prev = elem;
	}
	else
	{
		elem->next = *in;
		elem->prev = (*in)->prev;
		(*in)->prev->next = elem;
		(*in)->prev = elem;
	}
	*in = elem;
}

void	push(t_stack **from, t_stack **in)
{
	t_stack	*elem;

	elem = *from;
	if (elem == NULL)
		return ;
	disconnect(from);
	connect(elem, in);
}
