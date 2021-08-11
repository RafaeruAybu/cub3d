#include "../cub3d.h"

void	print_img(t_cub3d *cub3d)
{
	mlx_do_sync(cub3d->vars.mlx);
	print_sky_ground(cub3d);
	do_dda(cub3d);
	if (cub3d->utils.screenshot_flag == 1)
	{
		take_screenshot(cub3d);
		free_map(cub3d);
		free_sprites(cub3d);
		ft_list_clear(cub3d->utils.begin_list);
		exit(0);
	}
	mlx_put_image_to_window(cub3d->vars.mlx,
		cub3d->vars.win, cub3d->img.img, 0, 0);
}

void	body(t_cub3d *cub3d)
{
	mlx_hook(cub3d->vars.win, 2, 1L << 0, key_hook, cub3d);
	mlx_hook(cub3d->vars.win, 17, 1L << 1, button_hook, cub3d);
	print_img(cub3d);
	mlx_loop(cub3d->vars.mlx);
}
