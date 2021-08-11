/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 04:06:38 by igearhea          #+#    #+#             */
/*   Updated: 2020/11/04 20:19:16 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	general_size;
	char	*ptr;
	char	*save_ptr;

	if (!s1 || !s2)
		return (0);
	general_size = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc(general_size + 1);
	if (!ptr)
		return (ptr);
	save_ptr = ptr;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (save_ptr);
}
