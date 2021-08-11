/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 23:57:50 by igearhea          #+#    #+#             */
/*   Updated: 2020/11/07 16:46:07 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*ptr;
	char	*tmp;

	size = ft_strlen(s1);
	ptr = malloc(size + 1);
	tmp = ptr;
	if (ptr == 0)
		return (ptr);
	while (*s1)
		*ptr++ = *s1++;
	*ptr = '\0';
	return (tmp);
}
