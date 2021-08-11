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
