/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 11:28:13 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/14 11:28:21 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

void	action(t_stack **stack_a, t_stack **stack_b, const char *s);

typedef struct s_nbr
{
	int	n1;
	int	n2;
	int	n3;
	int	n4;
}	t_nbr;

void	norma_3(t_nbr n)
{
	if (n.n4 > n.n2 && n.n2 > n.n1 && n.n1 > n.n3)
		ft_putstr_fd("ra\nsa\nrra\nsa\n", 1);
	else if (n.n3 > n.n1 && n.n1 > n.n2 && n.n2 > n.n4)
		ft_putstr_fd("sa\nrra\n", 1);
	else if (n.n4 > n.n1 && n.n1 > n.n3 && n.n3 > n.n2)
		ft_putstr_fd("rra\nsa\nra\nra\n", 1);
	else if (n.n4 > n.n1 && n.n1 > n.n2 && n.n2 > n.n3)
		ft_putstr_fd("rra\nsa\nra\nra\nsa\n", 1);
	else if (n.n2 > n.n1 && n.n1 > n.n3 && n.n3 > n.n4)
		ft_putstr_fd("ra\nra\nsa\n", 1);
	else if (n.n2 > n.n1 && n.n1 > n.n4 && n.n4 > n.n3)
		ft_putstr_fd("ra\nra\n", 1);
	else if (n.n3 > n.n4 && n.n4 > n.n1 && n.n1 > n.n2)
		ft_putstr_fd("pb\nra\nsa\npa\nrra\n", 1);
	else if (n.n2 > n.n4 && n.n4 > n.n1 && n.n1 > n.n3)
		ft_putstr_fd("sa\nra\nsa\n", 1);
	else if (n.n2 > n.n3 && n.n3 > n.n1 && n.n1 > n.n4)
		ft_putstr_fd("ra\nsa\nrra\nrra\n", 1);
	else if (n.n3 > n.n1 && n.n1 > n.n4 && n.n4 > n.n2)
		ft_putstr_fd("ra\nsa\nra\n", 1);
	else if (n.n1 > n.n3 && n.n3 > n.n2 && n.n2 > n.n4)
		ft_putstr_fd("rra\npb\nra\npa\n", 1);
	else if (n.n3 > n.n2 && n.n2 > n.n1 && n.n1 > n.n4)
		ft_putstr_fd("rra\n", 1);
}

void	norma_2(t_nbr n)
{
	if (n.n1 > n.n2 && n.n2 > n.n3 && n.n3 > n.n4)
		ft_putstr_fd("sa\nra\nra\nsa\n", 1);
	else if (n.n1 > n.n2 && n.n2 > n.n4 && n.n4 > n.n3)
		ft_putstr_fd("sa\nra\nra\n", 1);
	else if (n.n1 > n.n4 && n.n4 > n.n3 && n.n3 > n.n2)
		ft_putstr_fd("ra\n", 1);
	else if (n.n1 > n.n3 && n.n3 > n.n4 && n.n4 > n.n2)
		ft_putstr_fd("rra\nsa\nra\nsa\n", 1);
	else if (n.n1 > n.n4 && n.n4 > n.n2 && n.n2 > n.n3)
		ft_putstr_fd("ra\nsa\n", 1);
	else if (n.n3 > n.n4 && n.n4 > n.n2 && n.n2 > n.n1)
		ft_putstr_fd("ra\nra\nsa\nra\nra\n", 1);
	else if (n.n2 > n.n3 && n.n3 > n.n4 && n.n4 > n.n1)
		ft_putstr_fd("ra\nsa\nra\nra\nsa\n", 1);
	else if (n.n2 > n.n4 && n.n4 > n.n3 && n.n3 > n.n1)
		ft_putstr_fd("sa\nra\n", 1);
	else if (n.n3 > n.n2 && n.n2 > n.n4 && n.n4 > n.n1)
		ft_putstr_fd("rra\nsa\n", 1);
	else if (n.n4 > n.n2 && n.n2 > n.n3 && n.n3 > n.n1)
		ft_putstr_fd("ra\nsa\nrra\n", 1);
	else if (n.n4 > n.n3 && n.n3 > n.n1 && n.n1 > n.n2)
		ft_putstr_fd("sa\n", 1);
	else
		norma_3(n);
}

void	norma_1(t_nbr n)
{
	if (n.n1 > n.n2 && n.n2 > n.n3)
		ft_putstr_fd("sa\nrra\n", 1);
	else if (n.n1 > n.n3 && n.n3 > n.n2)
		ft_putstr_fd("ra\n", 1);
	else if (n.n2 > n.n3 && n.n3 > n.n1)
		ft_putstr_fd("rra\nsa\n", 1);
	else if (n.n3 > n.n1 && n.n1 > n.n2)
		ft_putstr_fd("sa\n", 1);
	else if (n.n2 > n.n1 && n.n1 > n.n3)
		ft_putstr_fd("rra\n", 1);
}

void	handsort(t_stack **stack_a, t_stack **stack_b, int count)
{
	t_nbr	n;

	(void)stack_b;
	if (count == 2)
		return (ft_putstr_fd("sa\n", 1));
	n.n1 = (*stack_a)->number;
	n.n2 = (*stack_a)->next->number;
	n.n3 = (*stack_a)->next->next->number;
	if (count == 3)
		return (norma_1(n));
	n.n4 = (*stack_a)->prev->number;
	if (count == 4)
		return (norma_2(n));
}
