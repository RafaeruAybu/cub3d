/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:12:21 by igearhea          #+#    #+#             */
/*   Updated: 2021/03/10 16:12:23 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_map(t_cub3d *cub3d)
{
	int		i;

	i = 0;
	while (i < cub3d->map.map_hight)
	{
		free(cub3d->map.map[i]);
		i++;
	}
	free(cub3d->map.map);
}

static void	fill_array(t_cub3d *cub3d)
{
	t_list	*ptr;
	int		i;
	int		n;

	i = 0;
	n = 0;
	ptr = cub3d->utils.saved_list_ptr;
	while (i < cub3d->map.map_hight)
	{
		while (((char *)ptr->data)[n])
		{
			cub3d->map.map[i][n] = ((char *)ptr->data)[n];
			n++;
		}
		while (n < cub3d->map.map_width)
		{
			cub3d->map.map[i][n] = ' ';
			n++;
		}
		ptr = ptr->next;
		n = 0;
		i++;
	}
}

static void	get_map_array(t_cub3d *cub3d)
{
	int	i;

	cub3d->map.map = (char **)malloc(cub3d->map.map_hight * sizeof(char *));
	i = 0;
	while (i < cub3d->map.map_hight)
	{
		cub3d->map.map[i] = (char *)ft_calloc(cub3d->map.map_width,
				sizeof(char));
		i++;
	}
}

static void	get_map_size(t_cub3d *cub3d)
{
	t_list	*ptr;
	int		len;

	cub3d->map.map_hight = 0;
	cub3d->map.map_width = 0;
	ptr = cub3d->utils.saved_list_ptr;
	while (*(char *)(ptr->data) != '\0')
	{
		check_map_line(ptr);
		cub3d->map.map_hight++;
		len = ft_strlen(ptr->data);
		if (cub3d->map.map_width < len)
			cub3d->map.map_width = len;
		ptr = ptr->next;
		if (ptr == NULL)
			break ;
	}
	if (ptr != NULL)
	{
		while ((ptr != NULL) && (*(char *)(ptr->data) == '\0'))
			ptr = ptr->next;
		if (ptr != NULL)
			map_not_valid();
	}
}

void	parse_map(t_cub3d *cub3d)
{
	get_map_size(cub3d);
	get_map_array(cub3d);
	fill_array(cub3d);
	validate_map(cub3d);
	parse_player_pos(cub3d);
	cub3d->utils.flg_map = 1;
}
