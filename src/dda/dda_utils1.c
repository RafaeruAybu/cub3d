/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:11:59 by igearhea          #+#    #+#             */
/*   Updated: 2021/03/17 23:12:00 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_perp_dist(t_cub3d *cub3d)
{
	if (cub3d->dda.side == 0)
	{
		cub3d->dda.perp_wall_dist = (cub3d->dda.map_x - cub3d->dda.pos_x
				+ (1 - cub3d->dda.step_x) / 2) / cub3d->dda.ray_dir_x;
	}
	else
	{
		cub3d->dda.perp_wall_dist = (cub3d->dda.map_y - cub3d->dda.pos_y
				+ (1 - cub3d->dda.step_y) / 2) / cub3d->dda.ray_dir_y;
	}
}

void	calculate_height_and_pixels(t_cub3d *cub3d)
{
	cub3d->dda.line_height = (int)(cub3d->dda.h / cub3d->dda.perp_wall_dist);
	cub3d->dda.draw_start = (-(cub3d->dda.line_height)) / 2 + cub3d->dda.h / 2;
	if (cub3d->dda.draw_start < 0)
		cub3d->dda.draw_start = 0;
	cub3d->dda.draw_end = cub3d->dda.line_height / 2 + cub3d->dda.h / 2;
	if (cub3d->dda.draw_end >= cub3d->dda.h)
		cub3d->dda.draw_end = cub3d->dda.h - 1;
}

void	calculate_value_of_wall_x(t_cub3d *cub3d)
{
	if (cub3d->dda.side == 0)
	{
		cub3d->dda.wall_x = cub3d->dda.pos_y + cub3d->dda.perp_wall_dist
			* cub3d->dda.ray_dir_y;
	}
	else
	{
		cub3d->dda.wall_x = cub3d->dda.pos_x + cub3d->dda.perp_wall_dist
			* cub3d->dda.ray_dir_x;
	}
	cub3d->dda.wall_x -= floor((cub3d->dda.wall_x));
}

void	calculate_x_coordinate(t_cub3d *cub3d)
{
	set_textures_hight_width(cub3d);
	cub3d->dda.tex_x = (int)(cub3d->dda.wall_x
			* (double)(cub3d->dda.tex_width));
	if (cub3d->dda.side == 0 && cub3d->dda.ray_dir_x < 0)
		cub3d->dda.tex_x = cub3d->dda.tex_width - cub3d->dda.tex_x - 1;
	if (cub3d->dda.side == 1 && cub3d->dda.ray_dir_y > 0)
		cub3d->dda.tex_x = cub3d->dda.tex_width - cub3d->dda.tex_x - 1;
	cub3d->dda.step = 1.0 * cub3d->dda.tex_height / cub3d->dda.line_height;
	cub3d->dda.tex_pos = (cub3d->dda.draw_start - cub3d->dda.h / 2
			+ cub3d->dda.line_height / 2) * cub3d->dda.step;
}

void	set_text_color_to_buf(t_cub3d *cub3d)
{
	cub3d->dda.y = cub3d->dda.draw_start;
	while (cub3d->dda.y < cub3d->dda.draw_end)
	{
		cub3d->dda.tex_y = ((int)(cub3d->dda.tex_pos));
		cub3d->dda.tex_pos = cub3d->dda.tex_pos + cub3d->dda.step;
		if (cub3d->dda.side == 0 && cub3d->dda.ray_dir_x < 0)
			cub3d->dda.color = my_mlx_pixel_get(&cub3d->textures.we,
					cub3d->dda.tex_x, cub3d->dda.tex_y);
		if (cub3d->dda.side == 0 && cub3d->dda.ray_dir_x > 0)
			cub3d->dda.color = my_mlx_pixel_get(&cub3d->textures.ea,
					cub3d->dda.tex_x, cub3d->dda.tex_y);
		if (cub3d->dda.side == 1 && cub3d->dda.ray_dir_y < 0)
			cub3d->dda.color = my_mlx_pixel_get(&cub3d->textures.no,
					cub3d->dda.tex_x, cub3d->dda.tex_y);
		if (cub3d->dda.side == 1 && cub3d->dda.ray_dir_y > 0)
			cub3d->dda.color = my_mlx_pixel_get(&cub3d->textures.so,
					cub3d->dda.tex_x, cub3d->dda.tex_y);
		my_mlx_pixel_put(cub3d, cub3d->dda.x, cub3d->dda.y, cub3d->dda.color);
		(cub3d->dda.y)++;
	}
}
