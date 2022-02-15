
#ifndef LIBST_H
# define LIBST_H

typedef struct s_stack
{
	int				value;
	struct s_stack	*prev;
}	t_stack;

void	stack_add_bottom(t_stack **stack, t_stack *new);
void	stack_add_top(t_stack **stack, t_stack *new);
void	stack_clear(t_stack **stack);
void	stack_delone(t_stack *stack);
t_stack	*stack_duplicate(t_stack *stack);
t_stack	*stack_get_bottom(t_stack *stack);
t_stack	*stack_get_max(t_stack *stack);
t_stack	*stack_get_min(t_stack *stack);
int		stack_get_height(t_stack *stack);
t_stack	*stack_get_new(int value);
void	stack_print(t_stack *stack);

#endif
