
#include "push_swap.h"
#include <stdlib.h>

t_stack	*get_stack(char **num)
{
	t_stack	*top;
	t_stack	*bottom;

	top = NULL;
	while (*num)
	{
		bottom = stack_get_new(ft_atoi(*num++));
		if (bottom == NULL)
			exit(MALLOC);
		stack_add_bottom(&top, bottom);
	}
	return (top);
}

void	check_for_digit(char **num);
void	check_for_range_int(char **num);
void	check_for_duplicates(t_stack *stack);
void	check_for_sorted(t_stack *stack);
void	convert_to_indexes(t_stack *stack);

t_stack	*parser(char **num)
{
	t_stack	*stack;

	check_for_digit(num);
	check_for_range_int(num);
	stack = get_stack(num);
	check_for_duplicates(stack);
	check_for_sorted(stack);
	convert_to_indexes(stack);
	return (stack);
}
