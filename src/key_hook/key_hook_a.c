/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:42:55 by igearhea          #+#    #+#             */
/*   Updated: 2021/03/16 22:42:56 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	key_hook_a(t_cub3d *cub3d)
{
	double	move_speed;
	double	rotd_view_x;
	double	rotd_view_y;

	move_speed = 0.2;
	rotd_view_x = cub3d->player.view_x * 0 - cub3d->player.view_y * 1;
	rotd_view_y = cub3d->player.view_x * 1 - cub3d->player.view_y * 0;
	if (cub3d->map.map[(int)(cub3d->player.pos_y - rotd_view_y
			* move_speed)][(int)cub3d->player.pos_x] != '1')
		cub3d->player.pos_y -= rotd_view_y * move_speed;
	if (cub3d->map.map[(int)cub3d->player.pos_y]
		[(int)(cub3d->player.pos_x - rotd_view_x * move_speed)] != '1')
		cub3d->player.pos_x -= rotd_view_x * move_speed;
	print_img(cub3d);
}
