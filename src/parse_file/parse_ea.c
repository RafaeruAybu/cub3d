#include "../cub3d.h"

void	parse_ea(t_cub3d *cub3d)
{
	char	*ptr;

	if (cub3d->utils.flg_ea == 1)
		map_not_valid();
	ptr = (char *)cub3d->utils.saved_list_ptr->data;
	ptr += 2;
	if (*ptr != ' ')
		map_not_valid();
	cub3d->map.ea = ft_strtrim(ptr, " ");
	check_path(cub3d->map.ea);
	cub3d->utils.flg_ea = 1;
}
