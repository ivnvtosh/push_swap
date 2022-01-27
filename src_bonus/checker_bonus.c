/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:57:53 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/19 19:57:55 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "../libft/libft.h"

t_stack	*parser(int *count, char **numbers);
t_list	*parser_commands(t_stack *a, t_stack *b);
void	apply_commands(t_stack **a, t_stack **b, t_list *commands);
void	evaluate_stack(t_stack *a, t_stack *b);
void	terminate(t_stack *a, t_stack *b, int code);

void	checker(int count, char **numbers)
{
	t_stack	*a;
	t_stack	*b;
	t_list	*commands;

	a = parser(&count, numbers);
	b = NULL;
	commands = parser_commands(a, b);
	apply_commands(&a, &b, commands);
	evaluate_stack(a, b);
	terminate(a, b, 5);
}
