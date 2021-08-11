/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_w.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 23:04:12 by igearhea          #+#    #+#             */
/*   Updated: 2021/03/16 23:04:13 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	key_hook_w(t_cub3d *cub3d)
{
	double	move_speed;

	move_speed = 0.2;
	if (cub3d->map.map[(int)(cub3d->player.pos_y
			+ cub3d->player.view_y * move_speed)][(int)cub3d->player.pos_x]
				!= '1')
		cub3d->player.pos_y += cub3d->player.view_y * move_speed;
	if (cub3d->map.map[(int)cub3d->player.pos_y]
		[(int)(cub3d->player.pos_x + cub3d->player.view_x * move_speed)] != '1')
		cub3d->player.pos_x += cub3d->player.view_x * move_speed;
	print_img(cub3d);
}
