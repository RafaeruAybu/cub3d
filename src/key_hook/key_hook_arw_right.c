#include "../cub3d.h"

void	key_hook_arw_right(t_cub3d *cub3d)
{
	double	rot_speed;
	double	old_dirx;
	double	old_planex;

	rot_speed = 0.1;
	old_dirx = cub3d->player.view_x;
	old_planex = cub3d->player.plane_x;
	cub3d->player.view_x = cub3d->player.view_x
		* cos(rot_speed) - cub3d->player.view_y * sin(rot_speed);
	cub3d->player.view_y = old_dirx
		* sin(rot_speed) + cub3d->player.view_y * cos(rot_speed);
	cub3d->player.plane_x = cub3d->player.plane_x
		* cos(rot_speed) - cub3d->player.plane_y * sin(rot_speed);
	cub3d->player.plane_y = old_planex
		* sin(rot_speed) + cub3d->player.plane_y * cos(rot_speed);
	print_img(cub3d);
}
