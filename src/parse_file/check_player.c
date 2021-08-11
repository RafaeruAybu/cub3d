/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:39:10 by igearhea          #+#    #+#             */
/*   Updated: 2021/03/16 22:39:21 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check_up_down(t_cub3d *cub3d, int x, int y)
{
	int	m_w;
	int	m_h;

	m_w = cub3d->map.map_width;
	m_h = cub3d->map.map_hight;
	if (y > 0)
	{
		if (!(ft_strchr("102", cub3d->map.map[y - 1][x])))
			map_not_valid();
	}
	if (y < (m_h - 1))
	{
		if (!(ft_strchr("102", cub3d->map.map[y + 1][x])))
			map_not_valid();
	}
}

static void	check_left_right(t_cub3d *cub3d, int x, int y)
{
	int	m_w;
	int	m_h;

	m_w = cub3d->map.map_width;
	m_h = cub3d->map.map_hight;
	if (x > 0)
	{
		if (!(ft_strchr("102", cub3d->map.map[y][x - 1])))
			map_not_valid();
	}
	if (x < (m_w - 1))
	{
		if (!(ft_strchr("102", cub3d->map.map[y][x + 1])))
			map_not_valid();
	}
}

void	check_player(t_cub3d *cub3d, int x, int y)
{
	if (x == 0 || x == (cub3d->map.map_width - 1))
		map_not_valid();
	if (y == 0 || y == (cub3d->map.map_hight - 1))
		map_not_valid();
	check_left_right(cub3d, x, y);
	check_up_down(cub3d, x, y);
}
