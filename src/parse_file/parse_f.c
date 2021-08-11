#include "../cub3d.h"

static void	check_flag(t_cub3d *cub3d)
{
	if (cub3d->utils.flg_f == 1)
		map_not_valid();
}

static void	check_commas(char *ptr)
{
	if (*ptr != ',')
		map_not_valid();
}

static void	is_digit_count_digits(char *ptr)
{
	if (!ft_isdigit(*ptr))
		map_not_valid();
	if (count_digits(ptr) > 5)
		map_not_valid();
}

void	parse_f(t_cub3d *cub3d)
{
	char	*ptr;

	ptr = (char *)cub3d->utils.saved_list_ptr->data;
	check_flag(cub3d);
	if (*(++ptr) != ' ')
		map_not_valid();
	skip_spaces(&ptr);
	is_digit_count_digits(ptr);
	cub3d->map.floor_r = ft_atoi(ptr);
	skip_nums(&ptr);
	check_commas(ptr);
	ptr++;
	is_digit_count_digits(ptr);
	cub3d->map.floor_g = ft_atoi(ptr);
	skip_nums(&ptr);
	check_commas(ptr);
	ptr++;
	is_digit_count_digits(ptr);
	cub3d->map.floor_b = ft_atoi(ptr);
	skip_nums(&ptr);
	skip_spaces(&ptr);
	if (*ptr != '\0')
		map_not_valid();
	cub3d->utils.flg_f = 1;
}
