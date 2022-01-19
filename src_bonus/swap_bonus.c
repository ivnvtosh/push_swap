
#include "checker_bonus.h"
#include "../libft/libft.h"

void	swap(t_stack *stack)
{
	if (stack == NULL || stack == stack->next)
		return ;
	ft_swap(&stack->number, &stack->next->number);
}
