/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:03:47 by igearhea          #+#    #+#             */
/*   Updated: 2020/11/01 18:31:52 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst_ptr;
	unsigned char		*src_ptr;
	unsigned char		ch;
	void				*ret_ptr;
	size_t				count;

	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	ch = (unsigned char)c;
	ret_ptr = dst;
	count = 0;
	if (n != 0)
	{
		while (count < n)
		{
			*dst_ptr++ = *src_ptr++;
			if ((*dst_ptr) == ch)
				return (dst_ptr);
			ret_ptr++;
			count++;
		}
	}
	return (0);
}
