
#include "push_swap.h"
#include <stddef.h>

t_stack	*parser(char **num);
void	sort(int count, t_stack **a, t_stack **b);

void	push_swap(int count, char **num)
{
	t_stack	*a;
	t_stack	*b;

	a = parser(num);
	b = NULL;
	sort(count, &a, &b);
}
