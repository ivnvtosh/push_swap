/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:14:25 by ccamie            #+#    #+#             */
/*   Updated: 2021/12/25 18:14:28 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

t_list	*processing_incoming_values(char **argv)
{
	t_list	*list;

	if (is_astr_anbr(argv) == 0)
		return (NULL);
	list = get_list(argv);
	if (list == NULL)
		return (NULL);
	if (duplicates(argv) == 0)
		return (NULL);	
}

int	push_swap(int argc, char **argv)
{
	t_list	*list;

	list = processing_incoming_values(argv);
	if (list == NULL)
		return (-1);
	return (0);
}
