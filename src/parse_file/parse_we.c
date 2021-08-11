/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_we.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:11:31 by igearhea          #+#    #+#             */
/*   Updated: 2021/03/16 19:11:32 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_we(t_cub3d *cub3d)
{
	char	*ptr;

	if (cub3d->utils.flg_we == 1)
		map_not_valid();
	ptr = (char *)cub3d->utils.saved_list_ptr->data;
	ptr += 2;
	if (*ptr != ' ')
		map_not_valid();
	cub3d->map.we = ft_strtrim(ptr, " ");
	check_path(cub3d->map.we);
	cub3d->utils.flg_we = 1;
}
