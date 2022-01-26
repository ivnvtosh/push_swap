/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:12:27  by ccamie            #+#    #+#             */
/*   Updated: 2022/01/26 16:12:35 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

void	quicksort(t_stack **stack_a, t_stack **stack_b, int count);
void	print(t_stack *stack_a, t_stack *stack_b);

void	sort(t_stack **stack_a, t_stack **stack_b, int count)
{
	quicksort(stack_a, stack_b, count);
}
