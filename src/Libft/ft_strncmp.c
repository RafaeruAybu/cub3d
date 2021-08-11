/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:47:15 by igearhea          #+#    #+#             */
/*   Updated: 2020/11/02 19:54:03 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n != 0)
	{
		while (n-- != 0)
		{
			if (*s1 != *s2)
				return ((unsigned char)*s1 - (unsigned char)*s2);
			if (*s1 == 0)
				break ;
			s1++;
			s2++;
		}
	}
	return (0);
}
