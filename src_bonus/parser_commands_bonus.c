
#include "checker_bonus.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include <stdlib.h>

void	terminate(t_stack *stack_a, t_stack *stack_b, int code);

t_list	*parser_commands(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*comand;
	t_list	*start;
	char	*s;

	start = NULL;
	s = get_next_line(0);
	if (s == NULL)
		terminate(stack_a, stack_b, 2);
	while (s)
	{
		comand = ft_lstnew(s);
		if (comand == NULL)
		{
			free(s);
			ft_lstclear(&start, free);
			terminate(stack_a, stack_b, 2);
		}
		ft_lstadd_back(&start, comand);
		s = get_next_line(0);
	}
	return (start);
}
