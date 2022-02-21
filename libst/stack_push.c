/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:14:29 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/15 16:14:31 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libst.h"
#include <stddef.h>

void	stack_push(t_stack **from, t_stack **to)
{
	t_stack	*top;

	if (*from == NULL)
		return ;
	top = *from;
	if ((*from)->prev == NULL)
		*from = NULL;
	else
		*from = (*from)->prev;
	stack_add_top(to, top);
}
