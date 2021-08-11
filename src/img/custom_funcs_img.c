#include "../cub3d.h"

int	my_mlx_pixel_get(t_data *textures, int x, int y)
{
	char	*dst;
	int		color;

	dst = textures->addr
		+ (y * textures->line_length + x * (textures->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void	my_mlx_pixel_put(t_cub3d *cub3d, int x, int y, int color)
{
	char	*dst;

	dst = cub3d->img.addr
		+ (y * cub3d->img.line_length + x * (cub3d->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
