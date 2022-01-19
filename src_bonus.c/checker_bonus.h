#ifndef CHECHER_BONUS_N
# define CHECHER_BONUS_N

# include <stdio.h>

typedef struct s_stack
{
	int				number;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

#endif
