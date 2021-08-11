/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 20:33:47 by igearhea          #+#    #+#             */
/*   Updated: 2021/03/06 20:33:49 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	open_file(char *argv[])
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nNo such file or directory\n");
		exit(0);
	}
	return (fd);
}

void	close_file(int fd)
{
	if (close(fd) < 0)
	{
		printf("Error\nCan't close file\n");
		exit(0);
	}
}

static void	check_arguments(int argc, char *argv[], t_cub3d *cub3d)
{
	char	*c_ptr;

	cub3d->utils.screenshot_flag = 0;
	if (argc < 2 || argc > 3)
	{
		printf("Error\nNum of arguments must be 1 or 2\n");
		exit(0);
	}
	c_ptr = argv[1];
	if (ft_strlen(c_ptr) < 3)
		map_not_valid();
	while (*c_ptr != '\0')
		c_ptr++;
	if (!ft_strncmp((c_ptr - 3), ".cub", 3))
		map_not_valid();
	if (argc == 3)
	{
		if ((ft_strncmp(argv[2], "--save", 6) != 0)
			|| (ft_strlen(argv[2]) != 6))
		{
			printf("Error\nSecond argument is not right, try \"--save\"\n");
			exit(0);
		}
		cub3d->utils.screenshot_flag = 1;
	}
}

int	main(int argc, char *argv[])
{
	t_cub3d	cub3d;

	check_arguments(argc, argv, &cub3d);
	cub3d.utils.fd = open_file(argv);
	parse(&cub3d);
	cub3d.dda.z_buffer = (double *)malloc(cub3d.map.res_width * sizeof(double));
	if (cub3d.utils.screenshot_flag == 0)
		set_screen_size(&cub3d);
	init_img(&cub3d);
	body(&cub3d);
	return (0);
}
