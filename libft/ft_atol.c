/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 06:38:00 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/13 06:38:04 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isdigit(int c);

long	ft_atol(const char *s)
{
	long	n;
	long	sign;

	n = 0;
	sign = 1;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == 43 || *s == 45)
		if (*s++ == 45)
			sign = -1;
	while (ft_isdigit(*s))
	{
		if (n < -__INT_MAX__ - 1 || n > __INT_MAX__)
			return (__LONG_MAX__);
		n = n * 10 + *s++ - 48;
	}
	return (n * sign);
}
