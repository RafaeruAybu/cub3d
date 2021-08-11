/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:12:55 by igearhea          #+#    #+#             */
/*   Updated: 2021/03/10 16:12:56 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	skip_nums(char **ptr)
{
	while (ft_isdigit(**ptr))
		(*ptr)++;
}

void	init_pars(t_cub3d *cub3d)
{
	cub3d->map.res_hight = 0;
	cub3d->map.res_width = 0;
	cub3d->utils.flg_res = 0;
	cub3d->utils.flg_no = 0;
	cub3d->utils.flg_so = 0;
	cub3d->utils.flg_we = 0;
	cub3d->utils.flg_ea = 0;
	cub3d->utils.flg_s = 0;
	cub3d->utils.flg_f = 0;
	cub3d->utils.flg_c = 0;
	cub3d->utils.flg_map = 0;
	cub3d->utils.flg_player = 0;
	cub3d->map.sprite_num = 0;
}

void	map_not_valid(void)
{
	printf("Error\nFile not valid\n");
	exit(0);
}

void	skip_spaces(char **ptr)
{
	while (**ptr == ' ')
		(*ptr)++;
}

void	skip_new_lines(t_cub3d *cub3d)
{
	while (*((char *)cub3d->utils.saved_list_ptr->data) == '\0')
		cub3d->utils.saved_list_ptr = cub3d->utils.saved_list_ptr->next;
}
