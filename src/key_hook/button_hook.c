/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:41:47 by igearhea          #+#    #+#             */
/*   Updated: 2021/03/16 22:41:48 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	button_hook(t_cub3d *cub3d)
{
	printf("Window is closed\n");
	free_map(cub3d);
	free_sprites(cub3d);
	ft_list_clear(cub3d->utils.begin_list);
	exit(1);
	return (0);
}
