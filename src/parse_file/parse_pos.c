#include "../cub3d.h"

static void	check_player_flag(t_cub3d *cub3d)
{
	if (cub3d->utils.flg_player != 0)
		map_not_valid();
}

static void	check_n_w(t_cub3d *cub3d, int x, int y)
{
	if (cub3d->map.map[y][x] == 'N')
	{
		check_player_flag(cub3d);
		cub3d->player.pos_x = x + 0.5;
		cub3d->player.pos_y = y + 0.5;
		cub3d->player.view_x = 0;
		cub3d->player.view_y = -1;
		cub3d->utils.flg_player = 1;
	}
	if (cub3d->map.map[y][x] == 'W')
	{
		check_player_flag(cub3d);
		cub3d->player.pos_x = x + 0.5;
		cub3d->player.pos_y = y + 0.5;
		cub3d->player.view_x = -1;
		cub3d->player.view_y = 0;
		cub3d->utils.flg_player = 1;
	}
}

static void	check_e_s(t_cub3d *cub3d, int x, int y)
{
	if (cub3d->map.map[y][x] == 'E')
	{
		check_player_flag(cub3d);
		cub3d->player.pos_x = x + 0.5;
		cub3d->player.pos_y = y + 0.5;
		cub3d->player.view_x = 1;
		cub3d->player.view_y = 0;
		cub3d->utils.flg_player = 1;
	}
	if (cub3d->map.map[y][x] == 'S')
	{
		check_player_flag(cub3d);
		cub3d->player.pos_x = x + 0.5;
		cub3d->player.pos_y = y + 0.5;
		cub3d->player.view_x = 0;
		cub3d->player.view_y = 1;
		cub3d->utils.flg_player = 1;
	}
}

void	parse_player_pos(t_cub3d *cub3d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < cub3d->map.map_hight)
	{
		while (x < cub3d->map.map_width)
		{
			check_n_w(cub3d, x, y);
			check_e_s(cub3d, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
