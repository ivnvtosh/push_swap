/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:12:49 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/16 18:12:50 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/libft.h"
# include "../libst/libst.h"
# include "../libgnl/get_next_line.h"

# include <stdio.h>

# define GOOD		0
# define ERROR		1
# define NOTHING	2
# define MALLOC		3
# define COMMAND	4

# define SA			"sa\n"
# define SB			"sb\n"
# define SS			"ss\n"
# define PA			"pa\n"
# define PB			"pb\n"
# define RA			"ra\n"
# define RB			"rb\n"
# define RR			"rr\n"
# define RRA		"rra\n"
# define RRB		"rrb\n"
# define RRR		"rrr\n"

void	action(t_stack **a, t_stack **b, const char *command);
void	terminate(int code);

#endif
