/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:05:23 by igearhea          #+#    #+#             */
/*   Updated: 2020/11/04 23:11:02 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const unsigned char	*s_ptr;
	unsigned char		ch;

	s_ptr = (unsigned char *)s;
	ch = (unsigned char)c;
	while (1)
	{
		if (*s_ptr == c)
			return ((char *)s_ptr);
		if (*s_ptr == 0)
			return (0);
		s_ptr++;
	}
	return (0);
}
