/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:39:40 by igearhea          #+#    #+#             */
/*   Updated: 2021/03/16 22:39:41 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_sprites(t_cub3d *cub3d)
{
	free(cub3d->map.sprite_poses);
}

static void	fill_sprite_arr(t_cub3d *cub3d)
{
	t_list		*ptr;
	size_t		i;
	size_t		n;
	size_t		k;

	i = 0;
	n = 0;
	k = 0;
	ptr = cub3d->utils.saved_list_ptr;
	while (i < (size_t)cub3d->map.map_hight)
	{
		n = 0;
		while (((char *)ptr->data)[n])
		{
			if (((char *)ptr->data)[n] == '2')
			{
				cub3d->map.sprite_poses[k].x = n + 0.5;
				cub3d->map.sprite_poses[k].y = i + 0.5;
				k++;
			}
			n++;
		}
		ptr = ptr->next;
		i++;
	}
}

static void	get_sprite_array(t_cub3d *cub3d, size_t num)
{
	cub3d->map.sprite_poses = (t_sprite *)malloc(num * sizeof(t_sprite));
}

static size_t	count_sprites(t_cub3d *cub3d)
{
	size_t		num_of_sprites;
	t_list		*ptr;
	int			n;

	num_of_sprites = 0;
	ptr = cub3d->utils.saved_list_ptr;
	while (ptr != 0)
	{
		n = 0;
		while (((char *)ptr->data)[n])
		{
			if (((char *)ptr->data)[n] == '2')
				num_of_sprites++;
			n++;
		}
		ptr = ptr->next;
	}
	return (num_of_sprites);
}

void	parse_sprites(t_cub3d *cub3d)
{
	cub3d->map.sprite_num = count_sprites(cub3d);
	get_sprite_array(cub3d, cub3d->map.sprite_num);
	fill_sprite_arr(cub3d);
}
