
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libst/libst.h"

# define GOOD		0
# define NOTHING	1
# define ERROR		2
# define MALLOC		3

# define SA			"sa"
# define SB			"sb"
# define SS			"ss"
# define PA			"pa"
# define PB			"pb"
# define RA			"ra"
# define RB			"rb"
# define RR			"rr"
# define RRA		"rra"
# define RRB		"rrb"
# define RRR		"rrr"

void	action(t_stack **a, t_stack **b, const char *command);
void	terminate(int code);

# include <stdio.h>

#endif
