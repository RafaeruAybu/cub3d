/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 02:33:36 by igearhea          #+#    #+#             */
/*   Updated: 2021/03/26 02:33:37 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_textures_hight_width(t_cub3d *cub3d)
{
	if (cub3d->dda.side == 0 && cub3d->dda.ray_dir_x < 0)
	{
		cub3d->dda.tex_width = cub3d->textures.we.width;
		cub3d->dda.tex_height = cub3d->textures.we.height;
	}
	if (cub3d->dda.side == 0 && cub3d->dda.ray_dir_x > 0)
	{
		cub3d->dda.tex_width = cub3d->textures.ea.width;
		cub3d->dda.tex_height = cub3d->textures.ea.height;
	}
	if (cub3d->dda.side == 1 && cub3d->dda.ray_dir_y < 0)
	{
		cub3d->dda.tex_width = cub3d->textures.no.width;
		cub3d->dda.tex_height = cub3d->textures.no.height;
	}
	if (cub3d->dda.side == 1 && cub3d->dda.ray_dir_y > 0)
	{
		cub3d->dda.tex_width = cub3d->textures.so.height;
		cub3d->dda.tex_height = cub3d->textures.so.height;
	}
}
