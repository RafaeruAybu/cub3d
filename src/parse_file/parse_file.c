/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:10:20 by igearhea          #+#    #+#             */
/*   Updated: 2021/03/10 16:10:22 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check_flgas(t_cub3d *cub3d)
{
	if (!(cub3d->utils.flg_res && cub3d->utils.flg_no && cub3d->utils.flg_so
			&& cub3d->utils.flg_we && cub3d->utils.flg_ea && cub3d->utils.flg_s
			&& cub3d->utils.flg_f && cub3d->utils.flg_f && cub3d->utils.flg_c
			&& cub3d->utils.flg_map && cub3d->utils.flg_player))
		map_not_valid();
}

static void	get_list(t_cub3d *cub3d)
{
	char		*str;

	str = NULL;
	cub3d->utils.begin_list = NULL;
	while (get_next_line(cub3d->utils.fd, &str) > 0)
		ft_list_push_back(&cub3d->utils.begin_list, str);
	ft_list_push_back(&cub3d->utils.begin_list, str);
	cub3d->utils.saved_list_ptr = cub3d->utils.begin_list;
	close_file(cub3d->utils.fd);
}

static void	ifs(t_cub3d *cub3d, t_utils *f)
{
	if (!ft_strncmp((char *)f->saved_list_ptr->data, "R ", 2))
		parse_resolution(cub3d);
	else if (!ft_strncmp((char *)f->saved_list_ptr->data, "NO ", 3))
		parse_no(cub3d);
	else if (!ft_strncmp((char *)f->saved_list_ptr->data, "SO ", 3))
		parse_so(cub3d);
	else if (!ft_strncmp((char *)f->saved_list_ptr->data, "WE ", 3))
		parse_we(cub3d);
	else if (!ft_strncmp((char *)f->saved_list_ptr->data, "EA ", 3))
		parse_ea(cub3d);
	else if (!ft_strncmp((char *)f->saved_list_ptr->data, "S ", 2))
		parse_s(cub3d);
	else if (!ft_strncmp((char *)f->saved_list_ptr->data, "F ", 2))
		parse_f(cub3d);
	else if (!ft_strncmp((char *)f->saved_list_ptr->data, "C ", 2))
		parse_c(cub3d);
	else if (ft_strncmp((char *)f->saved_list_ptr->data, "\0", 1))
		map_not_valid();
}

static void	static_init(t_utils **f, t_cub3d *cub3d)
{
	*f = &cub3d->utils;
	get_list(cub3d);
	init_pars(cub3d);
}

void	parse(t_cub3d *cub3d)
{
	t_utils		*f;

	static_init(&f, cub3d);
	while (cub3d->utils.saved_list_ptr != NULL)
	{
		if (ft_strrchr("RNSWEFC", *((char *)f->saved_list_ptr->data)))
			ifs(cub3d, f);
		else if (*((char *)f->saved_list_ptr->data) == '\0')
		{
			f->saved_list_ptr = f->saved_list_ptr->next;
			continue ;
		}
		else if (*((char *)f->saved_list_ptr->data) == ' '
			|| *((char *)f->saved_list_ptr->data) == '1')
		{
			parse_map(cub3d);
			parse_sprites(cub3d);
			break ;
		}
		else
			map_not_valid();
		f->saved_list_ptr = f->saved_list_ptr->next;
	}
	check_flgas(cub3d);
	validate_ranges(cub3d);
}
