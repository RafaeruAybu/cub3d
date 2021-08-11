/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 23:06:29 by igearhea          #+#    #+#             */
/*   Updated: 2021/03/16 23:06:30 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	perform_dda(t_cub3d *cub3d)
{
	if (cub3d->dda.side_dist_x < cub3d->dda.side_dist_y)
	{
		cub3d->dda.side_dist_x += cub3d->dda.delta_dist_x;
		cub3d->dda.map_x += cub3d->dda.step_x;
		cub3d->dda.side = 0;
	}
	else
	{
		cub3d->dda.side_dist_y += cub3d->dda.delta_dist_y;
		cub3d->dda.map_y += cub3d->dda.step_y;
		cub3d->dda.side = 1;
	}
	if (cub3d->map.map[cub3d->dda.map_y][cub3d->dda.map_x] == '1')
		cub3d->dda.hit = 1;
}

void	calc_side_dist(t_cub3d *cub3d)
{
	if (cub3d->dda.ray_dir_x < 0)
	{
		cub3d->dda.step_x = -1;
		cub3d->dda.side_dist_x = (cub3d->dda.pos_x - cub3d->dda.map_x)
			* cub3d->dda.delta_dist_x;
	}
	else
	{
		cub3d->dda.step_x = 1;
		cub3d->dda.side_dist_x = (cub3d->dda.map_x + 1.0 - cub3d->dda.pos_x)
			* cub3d->dda.delta_dist_x;
	}
	if (cub3d->dda.ray_dir_y < 0)
	{
		cub3d->dda.step_y = -1;
		cub3d->dda.side_dist_y = (cub3d->dda.pos_y - cub3d->dda.map_y)
			* cub3d->dda.delta_dist_y;
	}
	else
	{
		cub3d->dda.step_y = 1;
		cub3d->dda.side_dist_y = (cub3d->dda.map_y + 1.0 - cub3d->dda.pos_y)
			* cub3d->dda.delta_dist_y;
	}
}

void	calculate_positions(t_cub3d *cub3d)
{
	cub3d->dda.camera_x = 2 * cub3d->dda.x / (double)cub3d->dda.w - 1;
	cub3d->dda.ray_dir_x = cub3d->dda.dir_x + cub3d->player.plane_x
		* cub3d->dda.camera_x;
	cub3d->dda.ray_dir_y = cub3d->dda.dir_y + cub3d->player.plane_y
		* cub3d->dda.camera_x;
	cub3d->dda.map_x = (int)(cub3d->player.pos_x);
	cub3d->dda.map_y = (int)(cub3d->player.pos_y);
	if (cub3d->dda.ray_dir_y == 0)
		cub3d->dda.delta_dist_x = 0;
	else
	{
		if (cub3d->dda.ray_dir_x == 0)
			cub3d->dda.delta_dist_x = 1;
		else
			cub3d->dda.delta_dist_x = fabs(1 / cub3d->dda.ray_dir_x);
	}
	if (cub3d->dda.ray_dir_x == 0)
		cub3d->dda.delta_dist_y = 0;
	else
	{
		if (cub3d->dda.ray_dir_y == 0)
			cub3d->dda.delta_dist_y = 1;
		else
			cub3d->dda.delta_dist_y = fabs(1 / cub3d->dda.ray_dir_y);
	}
}

void	init(t_cub3d *cub3d)
{
	cub3d->dda.dir_x = cub3d->player.view_x;
	cub3d->dda.dir_y = cub3d->player.view_y;
	cub3d->dda.screen_width = cub3d->map.res_width;
	cub3d->dda.screen_height = cub3d->map.res_hight;
	cub3d->dda.tex_width = cub3d->textures.no.width;
	cub3d->dda.tex_height = cub3d->textures.no.height;
	cub3d->dda.x = 0;
	cub3d->dda.hit = 0;
	cub3d->dda.pos_x = cub3d->player.pos_x;
	cub3d->dda.pos_y = cub3d->player.pos_y;
	cub3d->dda.w = cub3d->map.res_width;
	cub3d->dda.h = cub3d->map.res_hight;
	cub3d->player.plane_x = 0.66 * (cub3d->player.view_x
			* 0 - cub3d->player.view_y * 1);
	cub3d->player.plane_y = 0.66 * (cub3d->player.view_x
			* 1 + cub3d->player.view_y * 0);
}

void	do_dda(t_cub3d *cub3d)
{
	init(cub3d);
	while (cub3d->dda.x < cub3d->dda.w)
	{
		do_first_step(cub3d);
		cub3d->dda.z_buffer[cub3d->dda.x] = cub3d->dda.perp_wall_dist;
		cub3d->dda.x++;
	}
	sort_sprites(cub3d);
	cub3d->dda.i = 0;
	while ((size_t)cub3d->dda.i < cub3d->map.sprite_num)
	{
		if (cub3d->map.sprite_poses[cub3d->dda.i].dist_to_player > 0.05)
		{
			translate_and_transform(cub3d);
			calc_hight_lowest_and_highest(cub3d);
			print_sprite_pos(cub3d);
		}
		(cub3d->dda.i)++;
	}
}
