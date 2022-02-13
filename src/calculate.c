/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:14:39 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/11 17:14:47 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int	calculate_ra(t_stack *a, t_stack *b)
{
    unsigned int	min;
	int				i;

	i = 0;
	// while ((*a)->index < (*b)->index)
	// {
	// 	a = a->prev;
	// 	i++
	// 	if ((*a)->index < (*a)->prev->index)
	// 		break ;
	// }
	
    if (a->index < b->index)
    {
		// printf("a = %d < b = %d\n", a->index, b->index);
        while (a->index < b->index && a->prev->index > a->index)
        {
			// printf("a = %d < b = %d\n", a->index, b->index);
            a = a->prev;
            i++;
        }
    }
    else
    {
		// printf("a = %d > b = %d\n", a->index, b->index);
        while (a->index > b->index && a->prev->index < b->index)
        {
            a = a->prev;
            i++;
        }
        min = a->index;
			// printf("hi\n");
        while (min < b->index)
        {
            a = a->prev;
            i++;
        }
    }
	return (i);
}

int	calculate_rra(t_stack *a, t_stack *b)
{
    unsigned int	max;
    int				i;

    i = 0 ;
    if (a->index < b->index)
    {
		// printf("a = %d < b = %d\n", a->index, b->index);
        while (a->index < b->index && a->index < a->next->index)
        {
            a = a->next;
            i++;
        }
    }
    else
    {
        while (a->index < b->index)
        {
            a = a->next;
            i++;
        }
        max = a->index;
        while (max < b->index)
        {
            a = a->next;
            i++;
        }
    }
	return (i);
}

t_calc	calculate_one(t_stack *a, t_stack *b, int count, int i)
{
	t_calc	calc;

	calc.r.a = calculate_ra(a, b);
	// printf("done ra\n");
	calc.r.b = count - i;
	calc.rr.a = calculate_rra(a, b);
	// printf("done rra\n");
	calc.rr.b = i;
	return (calc);
} 

void	calculate(t_stack *a, t_stack *b, int count)
{
	int	i;
    int j;

	i = 1;
    j = count;
	b = b->prev; 
	// while (j > 0)
	// {
		b->calc = calculate_one(a, b, count, i++);
		// printf("what?\n");
		printf("%d   ",       b->index);
		printf ("ra - %d, ",  b->calc.r.a);
		printf ("rb - %d   ", b->calc.r.b);
		printf("rra - %d, ",  b->calc.rr.a);
		printf("rrb - %d   ", b->calc.rr.b);
		printf ("rr - %d, ",  b->calc.r.r);
		printf("rrr - %d\n",  b->calc.rr.r);
		b = b->prev;
		j--;
	// }
}

