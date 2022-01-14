/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_algorithm.c                                 :+:      :+:    :+:   */
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
}	t_number;

void	manual_algorithm(t_stack **stack_a, t_stack **stack_b, int argc)
{
	t_number	c;
		
	if (argc == 2)
		return stack_action(stack_a, stack_b, "sa");
	c.n1 = (*stack_a)->cell;
	c.n2 = (*stack_a)->next->cell;
	c.n3 = (*stack_a)->prev->cell;
	if (argc == 3)
	{
		if (c.n1 > c.n2 && c.n1 > c.n3 && c.n2 > c.n3)		//	первый самый большой	третий самый маленький
		{
			stack_action(stack_a, stack_b, "sa");
			stack_action(stack_a, stack_b, "rra");
		}
		else if (c.n1 > c.n2 && c.n1 > c.n3 && c.n2 < c.n3)	//	первый самый большой	второй самый маленький
		{
			stack_action(stack_a, stack_b, "ra");
		}
		else if (c.n1 < c.n2 && c.n1 < c.n3 && c.n2 > c.n3)	//	первый самый маленький	второй самый большой
		{
			stack_action(stack_a, stack_b, "rra");
			stack_action(stack_a, stack_b, "sa");
		}
		else if (c.n1 > c.n2 && c.n1 < c.n3 && c.n2 < c.n3)	//	второй самый маленький	третий самый большой
		{
			stack_action(stack_a, stack_b, "sa");
		}
		else if (c.n1 < c.n2 && c.n1 > c.n3 && c.n2 > c.n3)	//	второй самый большой	третий самый маленький
		{
			stack_action(stack_a, stack_b, "rra");
		}
	}
}
