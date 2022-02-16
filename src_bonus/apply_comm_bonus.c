/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_comm_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:04:18 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/16 19:04:20 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	apply_comm(t_stack **a, t_stack **b, t_list *comm)
{
	while (comm)
	{
		action(a, b, comm->content);
		comm = comm->next;
	}
}
