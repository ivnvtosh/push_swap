
#include "checker_bonus.h"
#include "../libft/libft.h"

void	rotate(t_stack **stack)
{
	if (*stack == NULL || (*stack) == (*stack)->next)
		return ;
	*stack = (*stack)->next;
}

void	reverse_rotate(t_stack **stack)
{
	if (*stack == NULL || (*stack) == (*stack)->next)
		return ;
	*stack = (*stack)->prev;
}
