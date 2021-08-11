#include "../cub3d.h"

static void	set_sprite_distance(t_cub3d *cub3d)
{
	size_t	i;

	i = 0;
	while (i < cub3d->map.sprite_num)
	{
		cub3d->map.sprite_poses[i].dist_to_player
			= (cub3d->map.sprite_poses[i].x - cub3d->player.pos_x)
			* (cub3d->map.sprite_poses[i].x - cub3d->player.pos_x)
			+ (cub3d->map.sprite_poses[i].y - cub3d->player.pos_y)
			* (cub3d->map.sprite_poses[i].y - cub3d->player.pos_y);
		i++;
	}
}

static void	check_pos(t_cub3d *cub3d, int i, int *flag_done,
	t_sprite *tmp_sprite)
{
	if (cub3d->map.sprite_poses[i].dist_to_player
		< cub3d->map.sprite_poses[i + 1].dist_to_player)
	{
		*tmp_sprite = cub3d->map.sprite_poses[i + 1];
		cub3d->map.sprite_poses[i + 1] = cub3d->map.sprite_poses[i];
		cub3d->map.sprite_poses[i] = *tmp_sprite;
		*flag_done = 0;
	}
}

void	sort_sprites(t_cub3d *cub3d)
{
	t_sprite	tmp_sprite;
	size_t		i;
	int			flag_done;

	set_sprite_distance(cub3d);
	flag_done = 0;
	i = 0;
	if (cub3d->map.sprite_num > 0)
	{
		while (!flag_done)
		{
			flag_done = 1;
			while (i < (cub3d->map.sprite_num - 1))
			{
				check_pos(cub3d, i, &flag_done, &tmp_sprite);
				i++;
			}
			i = 0;
		}
	}
}
