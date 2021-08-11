/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 01:52:15 by igearhea          #+#    #+#             */
/*   Updated: 2020/11/07 16:57:34 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*tmp;

	ptr = (char *)malloc(len + 1);
	if (s == 0)
		return (0);
	if (!ptr)
		return (ptr);
	tmp = ptr;
	if (start < (ft_strlen(s)))
	{
		while (start-- != 0)
			s++;
		while ((len-- != 0) && *s)
			*ptr++ = *s++;
	}
	*ptr = '\0';
	return (tmp);
}
