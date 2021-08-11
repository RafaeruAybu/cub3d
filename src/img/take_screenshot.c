#include "../cub3d.h"

static void	set_header(t_cub3d *cub3d, unsigned char *buf)
{
	ft_bzero(buf, 54);
	buf[0] = 'B';
	buf[1] = 'M';
	buf[5] = (cub3d->map.res_width * cub3d->map.res_hight * 4 + 54);
	buf[4] = ((cub3d->map.res_width * cub3d->map.res_hight * 4 + 54) >> 8);
	buf[3] = ((cub3d->map.res_width * cub3d->map.res_hight * 4 + 54) >> 16);
	buf[2] = ((cub3d->map.res_width * cub3d->map.res_hight * 4 + 54) >> 24);
	buf[10] = 54;
	buf[14] = 40;
	buf[18] = cub3d->map.res_width;
	buf[19] = cub3d->map.res_width >> 8;
	buf[20] = cub3d->map.res_width >> 16;
	buf[21] = cub3d->map.res_width >> 24;
	buf[22] = -cub3d->map.res_hight;
	buf[23] = -cub3d->map.res_hight >> 8;
	buf[24] = -cub3d->map.res_hight >> 16;
	buf[25] = -cub3d->map.res_hight >> 24;
	buf[26] = 1;
	buf[28] = 32;
}

void	take_screenshot(t_cub3d *cub3d)
{
	unsigned char	header[54];
	int				fd;
	size_t			num_of_bytes;
	int				i;

	set_header(cub3d, header);
	fd = open("screenshot.bmp",
			O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd < 0)
	{
		printf("Error\nCant open file!\n");
		exit(0);
	}
	num_of_bytes = cub3d->img.bits_per_pixel / 8 * cub3d->map.res_width;
	write(fd, &header, 54);
	i = 0;
	while (i < cub3d->map.res_hight)
	{
		write(fd, &cub3d->img.addr[i * cub3d->img.line_length], num_of_bytes);
		i++;
	}
	close(fd);
	printf("Screenshot is done.\n");
}
