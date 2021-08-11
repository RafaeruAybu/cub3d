/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:10:30 by igearhea          #+#    #+#             */
/*   Updated: 2021/03/16 19:10:32 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_s(t_cub3d *cub3d)
{
	char	*ptr;

	if (cub3d->utils.flg_s == 1)
		map_not_valid();
	ptr = (char *)cub3d->utils.saved_list_ptr->data;
	ptr++;
	if (*ptr != ' ')
		map_not_valid();
	cub3d->map.s = ft_strtrim(ptr, " ");
	check_path(cub3d->map.s);
	cub3d->utils.flg_s = 1;
}
