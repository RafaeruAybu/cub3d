#include "../cub3d.h"

void	parse_s(t_cub3d *cub3d)
{
	char	*ptr;

	if (cub3d->utils.flg_s == 1)
		map_not_valid();
	ptr = (char *)cub3d->utils.saved_list_ptr->data;
	ptr++;
	if (*ptr != ' ')
		map_not_valid();
	cub3d->map.s = ft_strtrim(ptr, " ");
	check_path(cub3d->map.s);
	cub3d->utils.flg_s = 1;
}
