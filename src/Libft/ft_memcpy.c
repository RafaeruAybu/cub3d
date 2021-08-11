/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:46:19 by igearhea          #+#    #+#             */
/*   Updated: 2020/10/31 18:48:20 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_ptr;
	unsigned char		*src_ptr;
	size_t				count;

	count = 0;
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	if ((n != 0) && (dst != src))
	{
		while (count < n)
		{
			*dst_ptr = *src_ptr;
			dst_ptr++;
			src_ptr++;
			count++;
		}
	}
	return (dst);
}
