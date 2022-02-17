/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_comm_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:34:00 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/16 18:34:03 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdlib.h>
#include <fcntl.h>

static t_list	*get_comm(void)
{
	t_list	*comm;
	t_list	*start;
	int		fd;
	char	*s;

	start = NULL;
	fd = 0;
	s = get_next_line(fd);
	while (s)
	{
		comm = ft_lstnew(s);
		if (comm == NULL)
			exit(MALLOC);
		ft_lstadd_back(&start, comm);
		s = get_next_line(fd);
	}
	return (start);
}

static void	checking(char *comm)
{
	if (ft_strcmp(comm, SA) == 0)
		return ;
	if (ft_strcmp(comm, SB) == 0)
		return ;
	if (ft_strcmp(comm, SS) == 0)
		return ;
	if (ft_strcmp(comm, PA) == 0)
		return ;
	if (ft_strcmp(comm, PB) == 0)
		return ;
	if (ft_strcmp(comm, RA) == 0)
		return ;
	if (ft_strcmp(comm, RB) == 0)
		return ;
	if (ft_strcmp(comm, RR) == 0)
		return ;
	if (ft_strcmp(comm, RRA) == 0)
		return ;
	if (ft_strcmp(comm, RRB) == 0)
		return ;
	if (ft_strcmp(comm, RRR) == 0)
		return ;
	terminate(COMMAND);
}

static	void	check(t_list *comm)
{
	while (comm)
	{
		checking(comm->content);
		comm = comm->next;
	}
}

t_list	*parse_comm(void)
{
	t_list	*comm;

	comm = get_comm();
	check(comm);
	return (comm);
}
