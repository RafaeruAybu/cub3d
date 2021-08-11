/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:45:12 by igearhea          #+#    #+#             */
/*   Updated: 2020/11/04 03:00:13 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	foo(char **str, int *sign)
{
	while ((**str == ' ') || ((**str >= 9) && (**str <= 13)))
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*sign = -1;
		(*str)++;
	}
}

int	ft_atoi(const char *s)
{
	long long	number;
	int			sign;
	char		*str;

	str = (char *)s;
	sign = 1;
	number = 0;
	foo(&str, &sign);
	while ((*str >= '0') && (*str <= '9'))
	{
		if (number > 2147483647 / 10 || (number == 2147483647 / 10
				&& *str - '0' > 7))
			if (sign == 1)
				return (-1);
		if (number > 2147483648 / 10 || (number == 2147483648 / 10
				&& *str - '0' > 8))
		{
			if (sign != 1)
				return (0);
		}
		number = 10 * number + (*str - '0');
		str++;
	}
	return (sign * (int)number);
}
