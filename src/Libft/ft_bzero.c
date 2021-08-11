/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:55:21 by igearhea          #+#    #+#             */
/*   Updated: 2020/10/31 17:41:20 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char		*ptr;
	size_t				count;

	count = 0;
	ptr = s;
	if (n != 0)
	{
		while (count < n)
		{
			*ptr = '\0';
			ptr++;
			count++;
		}
	}
}
