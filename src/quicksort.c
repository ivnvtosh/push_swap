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

void	chunks(t_stack **a, t_stack **b, int count);
void	calculate(t_stack *a, t_stack *b, int count);
t_calc	search_best(t_stack *b, int count);
void    apply_commands(t_stack **a, t_stack **b, t_calc command);
void	action(t_stack **a, t_stack **b, const char *s);

void	search(t_stack **a, t_stack **b, unsigned int count)
{
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
}

void	quicksort(t_stack **a, t_stack **b, int count)
{
	// t_calc	calc;


	chunks(a, b, count);
	count -= 3;
	action(a, b, "rrb");
	search(a, b, count / 4);
	count -= count / 4;
	print(*a, *b);
	calculate(*a, *b, count);

	// print(*a, *b);
	// calc = search_best(*b, count / 2 - 2);
	// apply_commands(a, b, calc);
	// print(*a, *b);



}

// ./push_swap -266 -853 -657 746 -525 14 376 159 -590 583 -136 569 -1009 951 320 281 -640 -690 591 -275 -597 567 -940 458 -392 1028 -1062 160 817 -1056 -172 -1073 932 -261 -890 -914 -268 794 61 -1000 616 -563 91 -212 -665 321 -316 483 409 346 515 629 488 649 -613 -1 941 -128 682 -1023 791 -646 29 -333 -175 -658 -549 1029 -369 -528 297 -73 -991 -1092 -1068 -806 -373 659 -1075 -1030 961 -712 174 -464 114 147 -1084 -691 -650 -1007 -610 550 -390 410 698 118 -1096 549 -540 348