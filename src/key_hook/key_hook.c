#include "../cub3d.h"

int	key_hook(int keycode, t_cub3d *cub3d)
{
	if (keycode == 53)
		key_hook_esc(cub3d);
	if (keycode == 13)
		key_hook_w(cub3d);
	if (keycode == 0)
		key_hook_a(cub3d);
	if (keycode == 1)
		key_hook_s(cub3d);
	if (keycode == 2)
		key_hook_d(cub3d);
	if (keycode == 123)
		key_hook_arw_left(cub3d);
	if (keycode == 124)
		key_hook_arw_right(cub3d);
	return (0);
}
