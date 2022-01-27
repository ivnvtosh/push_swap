/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:12:27 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/26 16:12:35 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

void	quicksort(t_stack **a, t_stack **b, int count);

void	sort(t_stack **a, t_stack **b, int count)
{
	if (count == 2)
		return (ft_putstr_fd("sa\n", 1));
	quicksort(a, b, count);
}
