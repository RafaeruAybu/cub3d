/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 20:34:00 by igearhea          #+#    #+#             */
/*   Updated: 2021/03/06 20:34:06 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SCALE 10
# define UDIV 1
# define VDIV 1
# define VMOVE 0.0

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "minilibx_mms_20200219/mlx.h"
# include "Libft/libft.h"
# include "gnl/get_next_line.h"
# include "list/ft_list.h"

typedef struct s_dda
{
	double	dir_x;
	double	dir_y;
	int		screen_width;
	int		screen_height;
	int		tex_width;
	int		tex_height;
	int		x;
	int		hit;
	double	pos_x;
	double	pos_y;
	int		w;
	int		h;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	int		side;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		y;
	int		tex_y;
	int		color;
	double	sprite_x;
	double	sprite_y;
	int		i;
	double	inv_det;
	double	transform_x;
	double	transform_y;
	int		sprite_screen_x;
	int		v_move_screen;
	int		sprite_height;
	int		draw_start_y;
	int		draw_end_y;
	int		sprite_width;
	int		draw_start_x;
	int		draw_end_x;
	int		stripe;
	int		d;
	double	*z_buffer;
}	t_dda;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
}	t_vars;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}	t_data;

typedef struct s_textures
{
	t_data		sprite;
	t_data		no;
	t_data		so;
	t_data		we;
	t_data		ea;
}	t_textures;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		view_x;
	double		view_y;
	double		plane_x;
	double		plane_y;
}	t_player;

typedef struct s_utils
{
	int			fd;
	int			screenshot_flag;
	t_list		*begin_list;
	t_list		*saved_list_ptr;
	int			flg_res;
	int			flg_no;
	int			flg_so;
	int			flg_we;
	int			flg_ea;
	int			flg_s;
	int			flg_f;
	int			flg_c;
	int			flg_map;
	int			flg_player;
	int			exact_screen_res_x;
	int			exact_screen_res_y;
}	t_utils;

typedef struct s_prite
{
	double		x;
	double		y;
	double		dist_to_player;
}	t_sprite;

typedef struct s_map
{
	int			res_hight;
	int			res_width;
	int			map_width;
	int			map_hight;
	int			floor_r;
	int			floor_g;
	int			floor_b;
	int			ceill_r;
	int			ceill_g;
	int			ceill_b;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	char		**map;
	t_sprite	*sprite_poses;
	size_t		sprite_num;
}	t_map;

typedef struct s_cub3d
{
	t_vars		vars;
	t_data		img;
	t_utils		utils;
	t_map		map;
	t_player	player;
	t_textures	textures;
	t_dda		dda;
}	t_cub3d;

void			parse(t_cub3d *cub3d);
void			init_pars(t_cub3d *cub3d);
void			skip_new_lines(t_cub3d *cub3d);
void			check_path(char *c_ptr);
void			check_map_line(t_list *saved_list_ptr);
void			validate_ranges(t_cub3d *cub3d);
void			validate_map(t_cub3d *cub3d);
void			skip_spaces(char **ptr);
void			skip_nums(char **ptr);
void			parse_resolution(t_cub3d *cub3d);
void			parse_no(t_cub3d *cub3d);
void			parse_so(t_cub3d *cub3d);
void			parse_we(t_cub3d *cub3d);
void			parse_ea(t_cub3d *cub3d);
void			parse_s(t_cub3d *cub3d);
void			parse_f(t_cub3d *cub3d);
void			parse_c(t_cub3d *cub3d);
void			parse_map(t_cub3d *cub3d);
void			parse_player_pos(t_cub3d *cub3d);
void			check_player(t_cub3d *cub3d, int x, int y);
void			validate_map(t_cub3d *cub3d);
void			close_file(int fd);
void			free_map(t_cub3d *cub3d);
int				count_digits(char *ptr);
void			map_not_valid(void);
void			init_img(t_cub3d *cub3d);
void			body(t_cub3d *cub3d);
int				key_hook(int keycode, t_cub3d *cub3d);
int				button_hook(t_cub3d *cub3d);
void			key_hook_a(t_cub3d *cub3d);
void			key_hook_arw_left(t_cub3d *cub3d);
void			key_hook_arw_right(t_cub3d *cub3d);
void			key_hook_d(t_cub3d *cub3d);
void			key_hook_esc(t_cub3d *cub3d);
void			key_hook_s(t_cub3d *cub3d);
void			key_hook_w(t_cub3d *cub3d);
void			print_sky_ground(t_cub3d *cub3d);
void			print_img(t_cub3d *cub3d);
void			sort_sprites(t_cub3d *cub3d);
void			parse_sprites(t_cub3d *cub3d);
void			free_sprites(t_cub3d *cub3d);
void			get_textures(t_data *tex, char *filename, void *mlx);
int				my_mlx_pixel_get(t_data *textures, int x, int y);
void			my_mlx_pixel_put(t_cub3d *cub3d, int x, int y, int color);
int				rgb_to_hex(int t, int r, int g, int b);
void			do_dda(t_cub3d *cub3d);
void			calculate_perp_dist(t_cub3d *cub3d);
void			calculate_height_and_pixels(t_cub3d *cub3d);
void			calculate_value_of_wall_x(t_cub3d *cub3d);
void			calculate_x_coordinate(t_cub3d *cub3d);
void			set_text_color_to_buf(t_cub3d *cub3d);
void			do_first_step(t_cub3d *cub3d);
void			perform_dda(t_cub3d *cub3d);
void			calc_side_dist(t_cub3d *cub3d);
void			calculate_positions(t_cub3d *cub3d);
void			init(t_cub3d *cub3d);
void			translate_and_transform(t_cub3d *cub3d);
void			calc_hight_lowest_and_highest(t_cub3d *cub3d);
void			print_sprite_pos(t_cub3d *cub3d);
void			take_screenshot(t_cub3d *cub3d);
void			set_screen_size(t_cub3d *cub3d);
void			check_zeros(t_cub3d *cub3d, int x, int y);
void			set_textures_hight_width(t_cub3d *cub3d);
#endif
