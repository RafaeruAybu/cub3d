/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:27:46 by igearhea          #+#    #+#             */
/*   Updated: 2021/03/16 19:27:47 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_screen_size(t_cub3d *cub3d)
{
	mlx_get_screen_size(cub3d->vars.mlx, &cub3d->utils.exact_screen_res_x,
		&cub3d->utils.exact_screen_res_y);
	if (cub3d->map.res_width > cub3d->utils.exact_screen_res_x)
		cub3d->map.res_width = cub3d->utils.exact_screen_res_x;
	if (cub3d->map.res_hight > cub3d->utils.exact_screen_res_y)
		cub3d->map.res_hight = cub3d->utils.exact_screen_res_y;
}

void	init_img(t_cub3d *cub3d)
{
	cub3d->vars.mlx = mlx_init();
	cub3d->vars.win = mlx_new_window(cub3d->vars.mlx,
			cub3d->map.res_width, cub3d->map.res_hight, "Cub3D");
	cub3d->img.img = mlx_new_image(cub3d->vars.mlx, cub3d->map.res_width,
			cub3d->map.res_hight);
	cub3d->img.addr = mlx_get_data_addr(cub3d->img.img,
			&cub3d->img.bits_per_pixel, &cub3d->img.line_length,
			&cub3d->img.endian);
	get_textures(&cub3d->textures.no, cub3d->map.no, cub3d->vars.mlx);
	get_textures(&cub3d->textures.we, cub3d->map.we, cub3d->vars.mlx);
	get_textures(&cub3d->textures.so, cub3d->map.so, cub3d->vars.mlx);
	get_textures(&cub3d->textures.ea, cub3d->map.ea, cub3d->vars.mlx);
	get_textures(&cub3d->textures.sprite, cub3d->map.s, cub3d->vars.mlx);
}
