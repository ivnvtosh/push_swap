/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 06:43:09 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/13 06:43:10 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

typedef struct s_ab
{
	int	a;
	int	b;
	int	r;
}	t_ab;

typedef struct s_calc
{
	t_ab	r;
	t_ab	rr;
}	t_calc;

typedef struct s_stack
{
	int				number;
	unsigned int	index;
	struct s_stack	*prev;
	struct s_stack	*next;
	t_calc			calc;
}	t_stack;

void	print(t_stack *a, t_stack *b);

#endif
