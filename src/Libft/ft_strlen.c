/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:16:36 by igearhea          #+#    #+#             */
/*   Updated: 2020/11/04 23:35:15 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *string)
{
	const char		*ptr;
	size_t			counter;

	ptr = string;
	counter = 0;
	while (*ptr)
	{
		ptr++;
		counter++;
	}
	return (counter);
}
