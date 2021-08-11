#include "../cub3d.h"

void	parse_so(t_cub3d *cub3d)
{
	char	*ptr;

	if (cub3d->utils.flg_so == 1)
		map_not_valid();
	ptr = (char *)cub3d->utils.saved_list_ptr->data;
	ptr += 2;
	if (*ptr != ' ')
		map_not_valid();
	cub3d->map.so = ft_strtrim(ptr, " ");
	check_path(cub3d->map.so);
	cub3d->utils.flg_so = 1;
}
