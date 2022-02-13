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
	int	i;

	i = 0;
	// printf("calc ra\n");
	while (1)
	{
		a = a->prev;
		i++;
		// if (a->index > a->prev->index && a->index > b->index)
		// 	break ;
		// if (a->index > a->prev->index && a->index < b->index)
		// 	break ;
		if (a->index > b->index && a->prev->index < b->index)
			break ;
	}
	// printf("done ra\n");
	return (i);
}

int	calculate_rra(t_stack *a, t_stack *b)
{
    int	i;

    i = 0;
	// printf("calc rra\n");
	while (1)
	{
		a = a->next;
		i++;
		// if (a->index > a->prev->index && a->index > b->index)
		// 	break ;
		// if (a->index > a->prev->index && a->index < b->index)
		// 	break ;
		if (a->index > b->index && a->prev->index < b->index)
			break ;
	}
	// printf("done rra\n");
	return (i);
}

int	least(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

int	biggest(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

t_calc	print_v(t_calc calc, int index)
{
	(void)index;
		// printf("%2d   ",       index);
		// printf ("ra - %2d, ",  calc.r.a);
		// printf("rra - %2d   ", calc.rr.a);
		// printf ("rb - %2d, ",  calc.r.b);
		// printf("rrb - %2d   ", calc.rr.b);
		// printf ("rr - %2d, ",  calc.r.r);
		// printf("rrr - %2d\n",  calc.rr.r);

		int	v1;
		int	v2;
		int	v3;
		int	v4;

		v1 = calc.r.a + calc.rr.b;
		v2 = calc.rr.a + calc.r.b;
		v3 = biggest(calc.r.a, calc.r.b);
		v4 = biggest(calc.rr.a, calc.rr.b);
		// printf("\n");
		// printf("ra  + rrb       = %3d\n", v1);
		// printf("rra + rb        = %3d\n", v2);
		// printf("rr  + ra  + rb  = %3d\n", v3);
		// printf("rrr + rra + rrb = %3d\n", v4);

		// printf("\n");

		if (v1 < v2 && v1 < v3 && v1 < v4)
		{
			printf("%2d least v1 ra  + rrb       = %2d\n", index, v1);
			// calc.r.a   = ;
			// calc.r.b   = ;
			calc.rr.a  = 0;
			calc.r.b  = 0;
			calc.r.r   = 0;
			calc.rr.r  = 0;

		}
		else if (v2 < v1 && v2 < v3 && v2 < v4)
		{
			printf("%2d least v2 rra + rb        = %2d\n", index, v2);
			calc.r.a   = 0;
			// calc.r.b   = ;
			// calc.rr.a  = ;
			calc.r.b   = 0;
			calc.r.r   = 0;
			calc.rr.r  = 0;

		}
		else if (v3 < v1 && v3 < v2 && v3 < v4)
		{
			printf("%2d least v3 rr  + ra  + rb  = %2d\n", index, v3);
			calc.r.a  -=  calc.r.r;
			calc.r.b  -=  calc.r.r;
			calc.rr.a -= 0;
			calc.rr.b -= 0;
			// calc.r.r   = ;
			calc.rr.r  = 0;

		}
		else if (v4 < v1 && v4 < v2 && v4 < v3)
		{
			printf("%2d least v4 rrr + rra + rrb = %2d\n", index, v4);
			calc.r.a   = 0;
			calc.r.b   = 0;
			calc.rr.a -= calc.rr.r;
			calc.rr.b -= calc.rr.r;
			calc.r.r   = 0;
			// calc.rr.r  = ;
		}
		else
			printf("lol v1 v2 v3 v4\n");

		// printf("\n");

		// printf("%2d   ",       index);
		// printf ("ra - %2d, ",  calc.r.a);
		// printf("rra - %2d   ", calc.rr.a);
		// printf ("rb - %2d, ",  calc.r.b);
		// printf("rrb - %2d   ", calc.rr.b);
		// printf ("rr - %2d, ",  calc.r.r);
		// printf("rrr - %2d\n",  calc.rr.r);

		// printf("\n\n\n");
		return (calc);
}

t_calc	calculate_one(t_stack *a, t_stack *b, int count, int i)
{
	t_calc	calc;

	calc.r.a = calculate_rra(a, b);
	calc.r.b = count - i;
	calc.rr.a = calculate_ra(a, b);
	calc.rr.b = i;
	calc.r.r = least(calc.r.a, calc.r.b);
	calc.rr.r = least(calc.rr.a, calc.rr.b);
	calc = print_v(calc, b->index);
	return (calc);
} 

void	calculate(t_stack *a, t_stack *b, int count)
{
	int	i;
    int j;

	i = 1;
    j = count;
	b = b->prev; 
	while (j > 1)
	{
		b->calc = calculate_one(a, b, count, i++);
		b = b->prev;
		j--;
	}
}
