/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 21:05:54 by igearhea          #+#    #+#             */
/*   Updated: 2020/11/03 20:09:20 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_ptr;
	const unsigned char	*s2_ptr;

	s1_ptr = (const unsigned char *)s1;
	s2_ptr = (const unsigned char *)s2;
	if (n != 0)
	{
		while (n-- != 0)
		{
			if (*s1_ptr++ != *s2_ptr++)
				return (*--s1_ptr - *--s2_ptr);
		}
	}
	return (0);
}
