#include "../cub3d.h"

static void	print_sky(t_cub3d *cub3d, int *i, int *j)
{
	while (*i < cub3d->map.res_width)
	{
		while (*j < cub3d->map.res_hight / 2)
		{
			my_mlx_pixel_put(cub3d, *i, *j,
				rgb_to_hex(0, cub3d->map.ceill_r,
					cub3d->map.ceill_g, cub3d->map.ceill_b));
			(*j)++;
		}
		*j = 0;
		(*i)++;
	}
}

static void	print_ground(t_cub3d *cub3d, int *i, int *j)
{
	while (*i < cub3d->map.res_width)
	{
		while (*j < cub3d->map.res_hight)
		{
			my_mlx_pixel_put(cub3d, *i, *j,
				rgb_to_hex(0, cub3d->map.floor_r,
					cub3d->map.floor_g, cub3d->map.floor_b));
			(*j)++;
		}
		*j = cub3d->map.res_hight / 2;
		(*i)++;
	}
}

void	print_sky_ground(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	print_sky(cub3d, &i, &j);
	i = 0;
	j = cub3d->map.res_hight / 2;
	print_ground(cub3d, &i, &j);
}
