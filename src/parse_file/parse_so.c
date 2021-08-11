/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_so.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:10:44 by igearhea          #+#    #+#             */
/*   Updated: 2021/03/16 19:10:45 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_so(t_cub3d *cub3d)
{
	char	*ptr;

	if (cub3d->utils.flg_so == 1)
		map_not_valid();
	ptr = (char *)cub3d->utils.saved_list_ptr->data;
	ptr += 2;
	if (*ptr != ' ')
		map_not_valid();
	cub3d->map.so = ft_strtrim(ptr, " ");
	check_path(cub3d->map.so);
	cub3d->utils.flg_so = 1;
}
