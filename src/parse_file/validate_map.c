/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:13:02 by igearhea          #+#    #+#             */
/*   Updated: 2021/03/16 19:13:03 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check_sprites(t_cub3d *cub3d, int x, int y)
{
	if (x == 0 || x == (cub3d->map.map_width - 1))
		map_not_valid();
	if (y == 0 || y == (cub3d->map.map_hight - 1))
		map_not_valid();
}

static void	check_left_right(t_cub3d *cub3d, int x, int y)
{
	int	m_w;
	int	m_h;

	m_w = cub3d->map.map_width;
	m_h = cub3d->map.map_hight;
	if (x < (m_w - 1))
	{
		if (!(cub3d->map.map[y][x + 1] == ' '
			|| cub3d->map.map[y][x + 1] == '1'))
			map_not_valid();
	}
	if (x > 0)
	{
		if (!(cub3d->map.map[y][x - 1] == ' '
			|| cub3d->map.map[y][x - 1] == '1'))
			map_not_valid();
	}
}

static void	check_up_down(t_cub3d *cub3d, int x, int y)
{
	int	m_w;
	int	m_h;

	m_w = cub3d->map.map_width;
	m_h = cub3d->map.map_hight;
	if (y < (m_h - 1))
	{
		if (!(cub3d->map.map[y + 1][x] == ' '
			|| cub3d->map.map[y + 1][x] == '1'))
			map_not_valid();
	}
	if (y > 0)
	{
		if (!(cub3d->map.map[y - 1][x] == ' '
			|| cub3d->map.map[y - 1][x] == '1'))
			map_not_valid();
	}
}

static void	check_walls(t_cub3d *cub3d, int x, int y)
{
	check_left_right(cub3d, x, y);
	check_up_down(cub3d, x, y);
}

void	validate_map(t_cub3d *cub3d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < cub3d->map.map_hight)
	{
		while (x < cub3d->map.map_width)
		{
			if (cub3d->map.map[y][x] == ' ')
				check_walls(cub3d, x, y);
			if (cub3d->map.map[y][x] == '2')
				check_sprites(cub3d, x, y);
			if (cub3d->map.map[y][x] == '0')
				check_zeros(cub3d, x, y);
			if (ft_strchr("NSWE", cub3d->map.map[y][x]))
				check_player(cub3d, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
