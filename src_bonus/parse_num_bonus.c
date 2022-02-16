/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:22:45 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/16 18:22:46 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*get_stack(char **num)
{
	t_stack	*top;
	t_stack	*new_top;

	top = NULL;
	while (*num)
	{
		new_top = stack_get_new(ft_atoi(*num++));
		if (new_top == NULL)
			exit(MALLOC);
		stack_add_top(&top, new_top);
	}
	return (top);
}

void	check_for_digit(char **num);
void	check_for_range_int(char **num);
void	check_for_duplicates(t_stack *stack);
void	check_for_sorted(t_stack *stack);
void	convert_to_indexes(t_stack *stack);

t_stack	*parse_num(char **num)
{
	t_stack	*stack;

	check_for_digit(num);
	check_for_range_int(num);
	stack = get_stack(num);
	check_for_duplicates(stack);
	check_for_sorted(stack);
	convert_to_indexes(stack);
	return (stack);
}
