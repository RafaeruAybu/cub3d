#include "../cub3d.h"

void	check_zeros(t_cub3d *cub3d, int x, int y)
{
	if (x == 0 || x == (cub3d->map.map_width - 1))
		map_not_valid();
	if (y == 0 || y == (cub3d->map.map_hight - 1))
		map_not_valid();
}

void	validate_ranges(t_cub3d *cub3d)
{
	if (cub3d->map.floor_r < 0 || cub3d->map.floor_r > 255)
		map_not_valid();
	if (cub3d->map.floor_g < 0 || cub3d->map.floor_g > 255)
		map_not_valid();
	if (cub3d->map.floor_b < 0 || cub3d->map.floor_b > 255)
		map_not_valid();
	if (cub3d->map.ceill_r < 0 || cub3d->map.ceill_r > 255)
		map_not_valid();
	if (cub3d->map.ceill_g < 0 || cub3d->map.ceill_g > 255)
		map_not_valid();
	if (cub3d->map.ceill_b < 0 || cub3d->map.ceill_b > 255)
		map_not_valid();
	if (cub3d->map.res_width < 1 || cub3d->map.res_hight < 1)
		map_not_valid();
	if (cub3d->map.res_width > 15000)
		cub3d->map.res_width = 15000;
	if (cub3d->map.res_hight > 15000)
		cub3d->map.res_hight = 15000;
}

void	check_map_line(t_list *saved_list_ptr)
{
	char	*ptr;

	ptr = (char *)saved_list_ptr->data;
	while (*ptr != '\0')
	{
		if (!ft_strchr("WSEN210 ", *ptr))
			map_not_valid();
		ptr++;
	}
}

void	check_path(char *c_ptr)
{
	int	fd;

	fd = open(c_ptr, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nNo such file or directory\n");
		exit(0);
	}
	else
	{
		if (close(fd) < 0)
		{
			printf("Error\nCan't close file\n");
			exit(0);
		}
	}
}

int	count_digits(char *ptr)
{
	int	n;

	n = 0;
	while (ft_isdigit(*ptr))
	{
		n++;
		ptr++;
	}
	return (n);
}
