/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:26:38 by igearhea          #+#    #+#             */
/*   Updated: 2020/11/01 20:45:19 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*s_ptr;
	char			*s_tmp_ptr;
	unsigned char	ch;

	s_ptr = (char *)s;
	s_tmp_ptr = 0;
	ch = (char)c;
	while (1)
	{
		if (*s_ptr == c)
			s_tmp_ptr = s_ptr;
		if (*s_ptr == 0)
			return (s_tmp_ptr);
		s_ptr++;
	}
	return (s_tmp_ptr);
}
