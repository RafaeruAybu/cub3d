/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 20:27:53 by igearhea          #+#    #+#             */
/*   Updated: 2021/03/06 20:28:03 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*ptr;

	ptr = (t_list *)malloc(sizeof(t_list));
	ptr->data = data;
	ptr->next = 0;
	return (ptr);
}

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*ptr;
	t_list	*tmp;

	ptr = begin_list;
	while (ptr != 0)
	{
		tmp = ptr;
		ptr = ptr->next;
	}
	return (tmp);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*newlist;
	t_list	*tmp;

	tmp = ft_list_last(*begin_list);
	if (*begin_list)
	{
		newlist = ft_create_elem(data);
		tmp->next = newlist;
	}
	else
	{
		*begin_list = ft_create_elem(data);
	}
}

void	ft_list_clear(t_list *begin_list)
{
	t_list	*tmp;
	t_list	*elem;

	elem = begin_list;
	while (elem != 0)
	{
		free(elem->data);
		tmp = elem->next;
		free(elem);
		elem = tmp;
	}
}
