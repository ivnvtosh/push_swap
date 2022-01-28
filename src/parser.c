/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 06:31:57 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/13 06:31:58 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <limits.h>

void	leave(int code);
void	terminate(t_stack *a, t_stack *b, int code);
int		stack_len(t_stack *stack);

typedef struct s_var
{
	int	min;
	int	mid;
	int	max;
}	t_var;

int	get_min(t_stack *stack, int count);
t_var	get_min_mid_max(t_stack *stack, int count);

static void	check(char **numbers)
{
	long long	n;
	int			i;

	while (*numbers)
	{
		i = 0;
		if ((*numbers)[i] == '-')
			i++;
		while (ft_isdigit((*numbers)[i]))
			i++;
		if ((*numbers)[i])
			leave(1);
		n = ft_atoll(*numbers);
		if (n < INT_MIN || n > INT_MAX)
			leave(1);
		numbers++;
	}
}

static t_stack	*allocate(char **numbers)
{
	t_stack	*stack;
	t_stack	*start;
	t_stack	*prev;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		leave(2);
	stack->number = ft_atoi(*numbers++);
	start = stack;
	while (*numbers)
	{
		stack->next = (t_stack *)malloc(sizeof(t_stack));
		if (stack->next == NULL)
			terminate(start, NULL, 2);
		prev = stack;
		stack = stack->next;
		stack->prev = prev;
		stack->number = ft_atoi(*numbers++);
	}
	stack->next = start;
	start->prev = stack;
	return (start);
}

static void	duplicates_sorted(t_stack *stack)
{
	t_stack	*start;
	t_stack	*prev;

	start = stack;
	while (stack->next != start)
	{
		prev = stack;
		stack = stack->next;
		while (stack != start)
		{
			if (prev->number == stack->number)
				terminate(start, NULL, 1);
			stack = stack->next;
		}
		stack = prev->next;
	}
	stack = start;
	while (stack->next != start && stack->number < stack->next->number)
		stack = stack->next;
	if (stack->next == start)
		terminate(start, NULL, 0);
}

static int	get_next(t_stack *stack, int count, int find)
{
	int	min;

	min = INT_MAX;
	while (count > 0)
	{
		if (min > stack->number && find < stack->number)
			min = stack->number;
		stack = stack->next;
		count--;
	}
	return (min);
}

static void	replacing_with_indexes(t_stack *stack)
{
	t_stack	*start;
	int		count;
	int		*index;
	int		find;
	int		i;
	int		j;

	count = stack_len(stack);
	index = (int *)malloc(sizeof(int *) * (count));
	if (index == NULL)
		terminate(stack, NULL, 2);
	find = get_min(stack, count);
	i = 0;
	j = 0;
	start = stack;
	while (j != count)
	{
		if (stack->number == find)
		{
			find = get_next(stack, count, find);
			index[i] = j + 1;
			j++;
		}
		stack = stack->next;
		i++;
		if (i == count)
			i = 0;
	}
	stack = start;
	i = 0;
	while (i != count)
	{
		stack->number = index[i++];
		stack = stack->next;
	}
	free(index);
}

void	print(t_stack *a, t_stack *b);

t_stack	*parser(char **numbers)
{
	t_stack	*stack;

	check(numbers);
	stack = allocate(numbers);
	duplicates_sorted(stack);
	print(stack, NULL);
	replacing_with_indexes(stack);
	print(stack, NULL);
	return (stack);
}

/*

static t_stack	*get_stack(char **numbers)
{
	t_stack	*stack;

	check(numbers);
	stack = allocate(numbers);
	duplicates_sorted(stack);
	return (stack);
}

t_stack	*parser(int *count, char **numbers)
{
	t_stack	*stack;
	char	**temp;
	int		i;

	if (*count == 1)
	{
		temp = ft_split(*numbers, 32);
		if (temp == NULL)
			leave(2);
		if (temp[1] == NULL)
		{
			free(*temp);
			free(temp);
			leave(1);
		}
		stack = get_stack(temp);
		i = 0;
		while (temp[i])
			free(temp[i++]);
		free(temp);
		*count = i;
	}
	else
		stack = get_stack(numbers);
	return (stack);
}

*/