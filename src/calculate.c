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
    int min;
	int	i;

	i = 0;
    if (a->index < b->index)
    {
        while (a->index < b->index)
        {
            a = a->prev;
            i++;
        }
    }
    else
    {
        while (a->index < b->index)
        {
            a = a->prev;
            i++;
        }
        min = a->index;
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
    int i;
    int max;

    i = 0 ;
    if (a->index < b->index)
    {
        while (a->index < b->index)
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
	calc.r.b = i;
	calc.rr.a = calculate_rra(a, b);
	calc.rr.b = count - i;



    // ftwtfwtfwtfwtwt
    calc.r.r = 0;  //wtf;
    calc.rr.r = 0; //wtf;
	return (calc);
}

void	calculate(t_stack *a, t_stack *b, int count)
{
	int	i;
    int j;

	i = 0;
    j = count;
	b = b->prev;
	while (j > 0)
	{
		b->calc = calculate_one(a, b, count, i++);
		b = b->prev;
		j--;
	}
}
