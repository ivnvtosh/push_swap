/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_commands_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:18:06 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/26 19:18:08 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include <stdlib.h>

void	terminate(t_stack *a, t_stack *b, int code);

static t_list	*get_commands(t_stack *a, t_stack *b)
{
	t_list	*commands;
	t_list	*start;
	char	*s;

	start = NULL;
	s = get_next_line(0);
	if (s == NULL)
		terminate(a, b, 2);
	while (s)
	{
		commands = ft_lstnew(s);
		if (commands == NULL)
		{
			free(s);
			ft_lstclear(&start, free);
			terminate(a, b, 2);
		}
		ft_lstadd_back(&start, commands);
		s = get_next_line(0);
	}
	return (start);
}

static	int	checking(t_list *commands)
{
	if (ft_strcmp(commands->content, "sa\n") == 0)
		return (0);
	if (ft_strcmp(commands->content, "sb\n") == 0)
		return (0);
	if (ft_strcmp(commands->content, "ss\n") == 0)
		return (0);
	if (ft_strcmp(commands->content, "pa\n") == 0)
		return (0);
	if (ft_strcmp(commands->content, "pb\n") == 0)
		return (0);
	if (ft_strcmp(commands->content, "ra\n") == 0)
		return (0);
	if (ft_strcmp(commands->content, "rb\n") == 0)
		return (0);
	if (ft_strcmp(commands->content, "rr\n") == 0)
		return (0);
	if (ft_strcmp(commands->content, "rra\n") == 0)
		return (0);
	if (ft_strcmp(commands->content, "rrb\n") == 0)
		return (0);
	if (ft_strcmp(commands->content, "rrr\n") == 0)
		return (0);
	return (1);
}

static	void	check(t_stack *a, t_stack *b, t_list *commands)
{
	t_list	*start;
	int		error;

	start = commands;
	while (commands)
	{
		error = checking(commands);
		if (error == 1)
		{
			ft_lstclear(&start, free);
			terminate(a, b, 3);
		}
		commands = commands->next;
	}
}

t_list	*parser_commands(t_stack *a, t_stack *b)
{
	t_list	*commands;

	commands = get_commands(a, b);
	check(a, b, commands);
	return (commands);
}
