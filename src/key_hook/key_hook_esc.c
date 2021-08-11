/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_esc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 23:02:07 by igearhea          #+#    #+#             */
/*   Updated: 2021/03/16 23:02:08 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	key_hook_esc(t_cub3d *cub3d)
{
	printf("Window is closed\n");
	free_map(cub3d);
	free_sprites(cub3d);
	ft_list_clear(cub3d->utils.begin_list);
	exit(1);
}
