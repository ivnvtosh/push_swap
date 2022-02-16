/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:12:41 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/16 18:12:42 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdlib.h>

t_stack	*parse_num(char **num);
t_list	*parse_comm(t_stack *a, t_stack *b);
void	apply_comm(t_stack **a, t_stack **b, t_list *comm);
void	evaluate(t_stack *a, t_stack *b);

void	checker(char **num)
{
	t_stack	*a;
	t_stack	*b;
	t_list	*comm;

	a = parse_num(num);
	b = NULL;
	comm = parse_comm(a, b);
	apply_comm(&a, &b, comm);
	evaluate(a, b);
	stack_clear(&a);
	stack_clear(&b);
	ft_lstclear(&comm, free);
}
