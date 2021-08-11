/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 23:26:23 by igearhea          #+#    #+#             */
/*   Updated: 2020/11/09 23:26:26 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	foo(int n, int fd)
{
	char	i;

	i = (n % 10) + '0';
	if (n != 0)
	{
		foo(n / 10, fd);
		write(fd, &i, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
		foo(n, fd);
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
	}
	else if (1)
	{
		foo(n, fd);
	}
}
