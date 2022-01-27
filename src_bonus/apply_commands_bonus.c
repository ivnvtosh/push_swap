/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_commands_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:17:38 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/26 19:17:40 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "../libft/libft.h"
#include <stdlib.h>

void	action(t_stack **a, t_stack **b, const char *s);

void	apply_commands(t_stack **a, t_stack **b, t_list *commands)
{
	t_list	*prev;

	while (commands)
	{
		action(a, b, commands->content);
		prev = commands;
		commands = commands->next;
		ft_lstdelone(prev, free);
	}
}
