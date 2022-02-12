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
		// printf("a = %d > b = %d\n", a->index, b->index);
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

    calc.r.r = 0;
	while (calc.r.a && calc.r.b)
	{
		calc.r.a--;
		calc.r.b--;
    	calc.r.r++;
	}
    calc.rr.r = 0;
	while (calc.rr.a && calc.rr.b)
	{
		calc.rr.a--;
		calc.rr.b--;
    	calc.rr.r++;
	}
	return (calc);
} 

void	calculate(t_stack *a, t_stack *b, int count)
{
	int	i;
    int j;

	i = 1;
    j = count / 2 - 2;
	print(a, b);
	b = b->prev; 
	while (j > 0)
	{
		b->calc = calculate_one(a, b, count, i++);
		printf("what?\n");
		printf("ra - %d\n", b->calc.r.a);
		printf("rb - %d\n", b->calc.r.b);
		printf("rr - %d\n\n", b->calc.r.r);
		printf("rra - %d\n", b->calc.rr.a);
		printf("rrb - %d\n", b->calc.rr.b);
		printf("rrr - %d\n\n", b->calc.rr.r);
		if (b->calc.r.a + b->calc.r.b +  b->calc.r.r < b->calc.rr.a + b->calc.rr.b + b->calc.rr.r)
		{
			printf("top\n");
			b->calc.rr.a = 0;
			b->calc.rr.b = 0;
			b->calc.rr.r = 0;
			printf("ra - %d\n", b->calc.r.a);
			printf("rb - %d\n", b->calc.r.b);
			printf("rr - %d\n\n", b->calc.r.r);
		}
		else
		{
			printf("top\n");
			b->calc.r.a = 0;
			b->calc.r.b = 0;
			b->calc.r.r = 0;
			printf("rra - %d\n", b->calc.rr.a);
			printf("rrb - %d\n", b->calc.rr.b);
			printf("rrr - %d\n\n", b->calc.rr.r);
		}
		b = b->prev;
		j--;
	}
}
