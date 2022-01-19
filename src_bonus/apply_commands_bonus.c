
#include "checker_bonus.h"
#include "../libft/libft.h"
#include <stdlib.h>

void	stack_action(t_stack **stack_a, t_stack **stack_b, const char *s);

void	apply_commands(t_stack **stack_a, t_stack **stack_b, t_list *commands)
{
	t_list	*prev;

	while (commands)
	{
		stack_action(stack_a, stack_b, commands->content);
		prev = commands;
		commands = commands->next;
		ft_lstdelone(prev, free);
	}
}
