/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 11:28:13 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/14 11:28:21 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

void	stack_action(t_stack **stack_a, t_stack **stack_b, const char *s);

typedef struct s_number
{
	int	n1;
	int	n2;
	int	n3;
	int	n4;
}	t_number;

void	norma_3(t_number c)
{
	if (c.n4 > c.n2 && c.n2 > c.n1 && c.n1 > c.n3)
		ft_putstr_fd("ra\nsa\nrra\nsa\n", 1);
	else if (c.n3 > c.n1 && c.n1 > c.n2 && c.n2 > c.n4)
		ft_putstr_fd("sa\nrra\n", 1);
	else if (c.n4 > c.n1 && c.n1 > c.n3 && c.n3 > c.n2)
		ft_putstr_fd("rra\nsa\nra\nra\n", 1);
	else if (c.n4 > c.n1 && c.n1 > c.n2 && c.n2 > c.n3)
		ft_putstr_fd("rra\nsa\nra\nra\nsa\n", 1);
	else if (c.n2 > c.n1 && c.n1 > c.n3 && c.n3 > c.n4)
		ft_putstr_fd("ra\nra\nsa\n", 1);
	else if (c.n2 > c.n1 && c.n1 > c.n4 && c.n4 > c.n3)
		ft_putstr_fd("ra\nra\n", 1);
	else if (c.n3 > c.n4 && c.n4 > c.n1 && c.n1 > c.n2)
		ft_putstr_fd("pb\nra\nsa\npa\nrra\n", 1);
	else if (c.n2 > c.n4 && c.n4 > c.n1 && c.n1 > c.n3)
		ft_putstr_fd("sa\nra\nsa\n", 1);
	else if (c.n2 > c.n3 && c.n3 > c.n1 && c.n1 > c.n4)
		ft_putstr_fd("ra\nsa\nrra\nrra\n", 1);
	else if (c.n3 > c.n1 && c.n1 > c.n4 && c.n4 > c.n2)
		ft_putstr_fd("ra\nsa\nra\n", 1);
	else if (c.n1 > c.n3 && c.n3 > c.n2 && c.n2 > c.n4)
		ft_putstr_fd("rra\npb\nra\npa\n", 1);
	else if (c.n3 > c.n2 && c.n2 > c.n1 && c.n1 > c.n4)
		ft_putstr_fd("rra\n", 1);
}

void	norma_2(t_number c)
{
	if (c.n1 > c.n2 && c.n2 > c.n3 && c.n3 > c.n4)
		ft_putstr_fd("sa\nra\nra\nsa\n", 1);
	else if (c.n1 > c.n2 && c.n2 > c.n4 && c.n4 > c.n3)
		ft_putstr_fd("sa\nra\nra\n", 1);
	else if (c.n1 > c.n4 && c.n4 > c.n3 && c.n3 > c.n2)
		ft_putstr_fd("ra\n", 1);
	else if (c.n1 > c.n3 && c.n3 > c.n4 && c.n4 > c.n2)
		ft_putstr_fd("rra\nsa\nra\nsa\n", 1);
	else if (c.n1 > c.n4 && c.n4 > c.n2 && c.n2 > c.n3)
		ft_putstr_fd("ra\nsa\n", 1);
	else if (c.n3 > c.n4 && c.n4 > c.n2 && c.n2 > c.n1)
		ft_putstr_fd("ra\nra\nsa\nra\nra\n", 1);
	else if (c.n2 > c.n3 && c.n3 > c.n4 && c.n4 > c.n1)
		ft_putstr_fd("ra\nsa\nra\nra\nsa\n", 1);
	else if (c.n2 > c.n4 && c.n4 > c.n3 && c.n3 > c.n1)
		ft_putstr_fd("sa\nra\n", 1);
	else if (c.n3 > c.n2 && c.n2 > c.n4 && c.n4 > c.n1)
		ft_putstr_fd("rra\nsa\n", 1);
	else if (c.n4 > c.n2 && c.n2 > c.n3 && c.n3 > c.n1)
		ft_putstr_fd("ra\nsa\nrra\n", 1);
	else if (c.n4 > c.n3 && c.n3 > c.n1 && c.n1 > c.n2)
		ft_putstr_fd("sa\n", 1);
	else
		norma_3(c);
}

void	norma_1(t_number c)
{
	if (c.n1 > c.n2 && c.n2 > c.n3)
		ft_putstr_fd("sa\nrra\n", 1);
	else if (c.n1 > c.n3 && c.n3 > c.n2)
		ft_putstr_fd("ra\n", 1);
	else if (c.n2 > c.n3 && c.n3 > c.n1)
		ft_putstr_fd("rra\nsa\n", 1);
	else if (c.n3 > c.n1 && c.n1 > c.n2)
		ft_putstr_fd("sa\n", 1);
	else if (c.n2 > c.n1 && c.n1 > c.n3)
		ft_putstr_fd("rra\n", 1);
}

void	manual_sorting(t_stack **stack_a, t_stack **stack_b, int argc)
{
	t_number	c;

	(void)stack_b;
	if (argc == 2)
		return (ft_putstr_fd("sa\n", 1));
	c.n1 = (*stack_a)->cell;
	c.n2 = (*stack_a)->next->cell;
	c.n3 = (*stack_a)->next->next->cell;
	if (argc == 3)
		return (norma_1(c));
	c.n4 = (*stack_a)->prev->cell;
	if (argc == 4)
		return (norma_2(c));
}

		// if (c.n1 > c.n2 && c.n2 > c.n3)
		// {
		// 	stack_action(stack_a, stack_b, "sa");
		// 	stack_action(stack_a, stack_b, "rra");
		// }
		// else if (c.n1 > c.n3 && c.n3 > c.n2)
		// {
		// 	stack_action(stack_a, stack_b, "ra");
		// }
		// else if (c.n2 > c.n3 && c.n3 > c.n1)
		// {
		// 	stack_action(stack_a, stack_b, "rra");
		// 	stack_action(stack_a, stack_b, "sa");
		// }
		// else if (c.n3 > c.n1 && c.n1 > c.n2)
		// {
		// 	stack_action(stack_a, stack_b, "sa");
		// }
		// else if (c.n2 > c.n1 && c.n1 > c.n3)
		// {
		// 	stack_action(stack_a, stack_b, "rra");
		// }
		//
		//
		//
		//
		//
		// if (c.n1 > c.n2 && c.n2 > c.n3 && c.n3 > c.n4)
		// {
		// 	stack_action(stack_a, stack_b, "sa");
		// 	stack_action(stack_a, stack_b, "ra");
		// 	stack_action(stack_a, stack_b, "ra");
		// 	stack_action(stack_a, stack_b, "sa");
		// }
		// if (c.n1 > c.n2 && c.n2 > c.n4 && c.n4 > c.n3)
		// {
		// 	stack_action(stack_a, stack_b, "sa");
		// 	stack_action(stack_a, stack_b, "ra");
		// 	stack_action(stack_a, stack_b, "ra");
		// }
		// if (c.n1 > c.n4 && c.n4 > c.n3 && c.n3 > c.n2)
		// {
		// 	stack_action(stack_a, stack_b, "ra");
		// }
		// if (c.n1 > c.n3 && c.n3 > c.n4 && c.n4 > c.n2)
		// {
		// 	stack_action(stack_a, stack_b, "rra");
		// 	stack_action(stack_a, stack_b, "sa");
		// 	stack_action(stack_a, stack_b, "ra");
		// 	stack_action(stack_a, stack_b, "sa");
		// }
		// if (c.n1 > c.n4 && c.n4 > c.n2 && c.n2 > c.n3)
		// {
		// 	stack_action(stack_a, stack_b, "ra");
		// 	stack_action(stack_a, stack_b, "sa");
		// }
		// if (c.n3 > c.n4 && c.n4 > c.n2 && c.n2 > c.n1)
		// {
		// 	stack_action(stack_a, stack_b, "ra");
		// 	stack_action(stack_a, stack_b, "ra");
		// 	stack_action(stack_a, stack_b, "sa");
		// 	stack_action(stack_a, stack_b, "ra");
		// 	stack_action(stack_a, stack_b, "ra");
		// }
		// if (c.n2 > c.n3 && c.n3 > c.n4 && c.n4 > c.n1)
		// {
		// 	stack_action(stack_a, stack_b, "ra");
		// 	stack_action(stack_a, stack_b, "sa");
		// 	stack_action(stack_a, stack_b, "ra");
		// 	stack_action(stack_a, stack_b, "ra");
		// 	stack_action(stack_a, stack_b, "sa");
		// }
		// if (c.n2 > c.n4 && c.n4 > c.n3 && c.n3 > c.n1)
		// {
		// 	stack_action(stack_a, stack_b, "sa");
		// 	stack_action(stack_a, stack_b, "ra");
		// }
		// if (c.n3 > c.n2 && c.n2 > c.n4 && c.n4 > c.n1)
		// {
		// 	stack_action(stack_a, stack_b, "rra");
		// 	stack_action(stack_a, stack_b, "sa");
		// }
		// if (c.n4 > c.n2 && c.n2 > c.n3 && c.n3 > c.n1)
		// {
		// 	stack_action(stack_a, stack_b, "ra");
		// 	stack_action(stack_a, stack_b, "sa");
		// 	stack_action(stack_a, stack_b, "rra");
		// }
		// if (c.n4 > c.n3 && c.n3 > c.n1 && c.n1 > c.n2)
		// {
		// 	stack_action(stack_a, stack_b, "sa");
		// }
		// if (c.n4 > c.n2 && c.n2 > c.n1 && c.n1 > c.n3)
		// {
		// 	stack_action(stack_a, stack_b, "ra");
		// 	stack_action(stack_a, stack_b, "sa");
		// 	stack_action(stack_a, stack_b, "rra");
		// 	stack_action(stack_a, stack_b, "sa");
		// }
		// if (c.n3 > c.n1 && c.n1 > c.n2 && c.n2 > c.n4)
		// {
		// 	stack_action(stack_a, stack_b, "sa");
		// 	stack_action(stack_a, stack_b, "rra");
		// }
		// if (c.n4 > c.n1 && c.n1 > c.n3 && c.n3 > c.n2)
		// {
		// 	stack_action(stack_a, stack_b, "rra");
		// 	stack_action(stack_a, stack_b, "sa");
		// 	stack_action(stack_a, stack_b, "ra");
		// 	stack_action(stack_a, stack_b, "ra");
		// }
		// if (c.n4 > c.n1 && c.n1 > c.n2 && c.n2 > c.n3)
		// {
		// 	stack_action(stack_a, stack_b, "rra");
		// 	stack_action(stack_a, stack_b, "sa");
		// 	stack_action(stack_a, stack_b, "ra");
		// 	stack_action(stack_a, stack_b, "ra");
		// 	stack_action(stack_a, stack_b, "sa");
		// }
		// if (c.n2 > c.n1 && c.n1 > c.n3 && c.n3 > c.n4)
		// {
		// 	stack_action(stack_a, stack_b, "ra");
		// 	stack_action(stack_a, stack_b, "ra");
		// 	stack_action(stack_a, stack_b, "sa");
		// }
		// if (c.n2 > c.n1 && c.n1 > c.n4 && c.n4 > c.n3)
		// {
		// 	stack_action(stack_a, stack_b, "ra");
		// 	stack_action(stack_a, stack_b, "ra");
		// }
		// if (c.n3 > c.n4 && c.n4 > c.n1 && c.n1 > c.n2)
		// {
		// 	stack_action(stack_a, stack_b, "pb");
		// 	stack_action(stack_a, stack_b, "ra");
		// 	stack_action(stack_a, stack_b, "sa");
		// 	stack_action(stack_a, stack_b, "pa");
		// 	stack_action(stack_a, stack_b, "rra");
		// }
		// if (c.n2 > c.n4 && c.n4 > c.n1 && c.n1 > c.n3)
		// {
		// 	stack_action(stack_a, stack_b, "sa");
		// 	stack_action(stack_a, stack_b, "ra");
		// 	stack_action(stack_a, stack_b, "sa");
		// }
		// if (c.n2 > c.n3 && c.n3 > c.n1 && c.n1 > c.n4)
		// {
		// 	stack_action(stack_a, stack_b, "ra");
		// 	stack_action(stack_a, stack_b, "sa");
		// 	stack_action(stack_a, stack_b, "rra");
		// 	stack_action(stack_a, stack_b, "rra");
		// }
		// if (c.n3 > c.n1 && c.n1 > c.n4 && c.n4 > c.n2)
		// {
		// 	stack_action(stack_a, stack_b, "ra");
		// 	stack_action(stack_a, stack_b, "sa");
		// 	stack_action(stack_a, stack_b, "ra");
		// }
		// if (c.n1 > c.n3 && c.n3 > c.n2 && c.n2 > c.n4)
		// {
		// 	stack_action(stack_a, stack_b, "rra");
		// 	stack_action(stack_a, stack_b, "pb");
		// 	stack_action(stack_a, stack_b, "ra");
		// 	stack_action(stack_a, stack_b, "pa");
		// }
		// if (c.n3 > c.n2 && c.n2 > c.n1 && c.n1 > c.n4)
		// {
		// 	stack_action(stack_a, stack_b, "rra");
		// }