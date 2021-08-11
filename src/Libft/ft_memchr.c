/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:06:31 by igearhea          #+#    #+#             */
/*   Updated: 2020/11/01 20:17:42 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		ch;

	ptr = (unsigned char *)s;
	ch = (unsigned char)c;
	if (n != 0)
	{
		while (n-- != 0)
		{
			if (*ptr++ == ch)
				return ((void *)(ptr - 1));
		}
	}
	return (0);
}
