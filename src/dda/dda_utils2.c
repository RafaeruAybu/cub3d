#include "../cub3d.h"

void	do_first_step(t_cub3d *cub3d)
{
	calculate_positions(cub3d);
	calc_side_dist(cub3d);
	while (cub3d->dda.hit == 0)
		perform_dda(cub3d);
	cub3d->dda.hit = 0;
	calculate_perp_dist(cub3d);
	calculate_height_and_pixels(cub3d);
	calculate_value_of_wall_x(cub3d);
	calculate_x_coordinate(cub3d);
	set_text_color_to_buf(cub3d);
}

void	translate_and_transform(t_cub3d *cub3d)
{
	cub3d->dda.sprite_x = cub3d->map.sprite_poses[cub3d->dda.i].x
		- cub3d->dda.pos_x;
	cub3d->dda.sprite_y = cub3d->map.sprite_poses[cub3d->dda.i].y
		- cub3d->dda.pos_y;
	cub3d->dda.inv_det = 1.0 / (cub3d->player.plane_x * cub3d->dda.dir_y
			- cub3d->dda.dir_x * cub3d->player.plane_y);
	cub3d->dda.transform_x = cub3d->dda.inv_det * (cub3d->dda.dir_y
			* cub3d->dda.sprite_x - cub3d->dda.dir_x * cub3d->dda.sprite_y);
	cub3d->dda.transform_y = cub3d->dda.inv_det * (-(cub3d->player.plane_y)
			* cub3d->dda.sprite_x + cub3d->player.plane_x
			* cub3d->dda.sprite_y);
	cub3d->dda.sprite_screen_x = (int)((cub3d->dda.w / 2)
			* (1 + cub3d->dda.transform_x / cub3d->dda.transform_y));
	cub3d->dda.v_move_screen = (int)(VMOVE / cub3d->dda.transform_y);
}

void	calc_hight_lowest_and_highest(t_cub3d *cub3d)
{
	cub3d->dda.sprite_height = abs((int)(cub3d->dda.h
				/ (cub3d->dda.transform_y))) / VDIV;
	cub3d->dda.draw_start_y = -(cub3d->dda.sprite_height)
		/ 2 + cub3d->dda.h / 2 + cub3d->dda.v_move_screen;
	if (cub3d->dda.draw_start_y < 0)
		cub3d->dda.draw_start_y = 0;
	cub3d->dda.draw_end_y = cub3d->dda.sprite_height
		/ 2 + cub3d->dda.h / 2 + cub3d->dda.v_move_screen;
	if (cub3d->dda.draw_end_y >= cub3d->dda.h)
		cub3d->dda.draw_end_y = cub3d->dda.h - 1;
	cub3d->dda.sprite_width = abs((int)(cub3d->dda.w
				/ (cub3d->dda.transform_y))) / UDIV;
	cub3d->dda.draw_start_x = -(cub3d->dda.sprite_width)
		/ 2 + cub3d->dda.sprite_screen_x;
	if (cub3d->dda.draw_start_x < 0)
		cub3d->dda.draw_start_x = 0;
	cub3d->dda.draw_end_x = cub3d->dda.sprite_width
		/ 2 + cub3d->dda.sprite_screen_x;
	if (cub3d->dda.draw_end_x >= cub3d->dda.w)
		cub3d->dda.draw_end_x = cub3d->dda.w - 1;
}

static void	sprite_draw_loop(t_cub3d *cub3d)
{
	cub3d->dda.y = cub3d->dda.draw_start_y;
	while (cub3d->dda.y < cub3d->dda.draw_end_y)
	{
		cub3d->dda.d = (cub3d->dda.y - cub3d->dda.v_move_screen)
			* 256 - cub3d->dda.h * 128 + cub3d->dda.sprite_height * 128;
		cub3d->dda.tex_y = ((cub3d->dda.d
					* cub3d->textures.sprite.height)
				/ cub3d->dda.sprite_height) / 256;
		cub3d->dda.color = my_mlx_pixel_get(&cub3d->textures.sprite,
				cub3d->dda.tex_x, cub3d->dda.tex_y);
		if ((cub3d->dda.color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(cub3d, cub3d->dda.stripe,
				cub3d->dda.y, cub3d->dda.color);
		(cub3d->dda.y)++;
	}
}

void	print_sprite_pos(t_cub3d *cub3d)
{
	cub3d->dda.stripe = cub3d->dda.draw_start_x;
	while (cub3d->dda.stripe < cub3d->dda.draw_end_x)
	{
		cub3d->dda.tex_x = (int)(256 * (cub3d->dda.stripe
					- (-(cub3d->dda.sprite_width)
						/ 2 + cub3d->dda.sprite_screen_x))
				* cub3d->textures.sprite.width / cub3d->dda.sprite_width) / 256;
		if (cub3d->dda.transform_y > 0 && cub3d->dda.stripe > 0
			&& cub3d->dda.stripe < cub3d->dda.w && cub3d->dda.transform_y
			< cub3d->dda.z_buffer[cub3d->dda.stripe])
			sprite_draw_loop(cub3d);
		(cub3d->dda.stripe)++;
	}
}
