/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 23:08:35 by igearhea          #+#    #+#             */
/*   Updated: 2021/03/16 23:08:36 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_textures(t_data *tex, char *filename, void *mlx)
{
	tex->img = mlx_xpm_file_to_image(mlx, filename, &tex->width, &tex->height);
	if (tex->img == NULL)
		exit(1);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->line_length, &tex->endian);
}
