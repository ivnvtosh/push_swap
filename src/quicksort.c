/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:06:45 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/23 21:06:57 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

typedef struct s_var
{
	unsigned int	min;
	unsigned int	mid;
	unsigned int	max;
}	t_var;

t_var	get_min_mid_max(t_stack *stack, int count);
void	action(t_stack **a, t_stack **b, const char *s);
void	print(t_stack *a, t_stack *b);

static int	send_from_a_to_b(t_stack **a, t_stack **b, int count, t_var var)
{
	int	here;

	here = count;
	while (count > 0)
	{
		if (var.mid < (*a)->index)
		{
			action(a, b, "pb");
			here--;
		}
		else
			action(a, b, "ra");
		count--;
	}
	return (here);
}

void	ft_last(t_stack **a, t_stack **b)
{
	// if ((*a)->index > (*a)->next->index && (*b)->index < (*b)->next->index)
	// 	action(a, b, "ss");
	// else
	// {
		if ((*a)->index < (*a)->next->index)
			action(a, b, "sa");
		if ((*b)->index > (*b)->next->index)
			action(a, b, "sb");
	// }
	action(a, b, "pb");
	action(a, b, "pb");
	action(a, b, "rrb");
	action(a, b, "rrb"); 
	action(a, b, "rrb");
	action(a, b, "pa");
	action(a, b, "pa");
}

static void	recursion(t_stack **a, t_stack **b, int count)
{
	t_var	var;
	int		here;

	if (count <= 2)
		return ft_last(a, b);
	var = get_min_mid_max(*a, count);
	here = send_from_a_to_b(a, b, count, var);
	recursion(a, b, here);
}

// int	check_ra(t_stack *a, t_stack *b)
// {
// 	int	i;

// 	i = 0;
// 	while (a->index > b->index)
// 	{
// 		if (a->index > a->prev->index)
// 			break ;
// 		a = a->prev;
// 		i++;
// 	}
// 	return (i);
// }

void	search_place(t_stack **a, t_stack **b, unsigned int count)
{
	(void)a;
	(void)b;
	(void)count;

	count -= 2;
	while (count > 0)
	{
		if ((*a)->index < (*b)->index)
		{
			while ((*a)->index < (*b)->index)
			{
				action(a, b, "ra");
				if ((*a)->index < (*a)->prev->index)
					break ;
			}
		}
		else
		{
			while ((*a)->prev->index > (*b)->index)
			{
				if ((*a)->index < (*a)->prev->index)
					break ;
				action(a, b, "rra");
			}
		}
		action(a, b, "pa");
		action(a, b, "rrb");
		count--;
	}
	// action(a, b, "pa");
}

void	quicksort(t_stack **a, t_stack **b, int count)
{
	t_var	var;

	var = get_min_mid_max(*a, count);
	recursion(a, b, count);
	search_place(a, b, count);
}
