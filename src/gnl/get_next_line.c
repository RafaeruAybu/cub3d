/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:35:10 by igearhea          #+#    #+#             */
/*   Updated: 2021/01/21 10:35:11 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	remain_np(char *n_p, char *temp, char **line, char **remain)
{
	*n_p = '\0';
	*line = ft_strdup(*remain);
	temp = *remain;
	*remain = ft_strdup(++n_p);
	free(temp);
}

int	check_remain(char **remain, char **line)
{
	char	*n_p;
	char	*temp;

	temp = 0;
	n_p = ft_strchr(*remain, '\n');
	if (*remain && n_p)
	{
		remain_np(n_p, temp, line, remain);
		return (1);
	}
	else if (1)
	{
		n_p = ft_strchr(*remain, '\0');
		if (*remain && n_p)
		{
			*line = ft_strdup(*remain);
			free(*remain);
			*remain = NULL;
			return (0);
		}
	}
	*line = ft_strdup("");
	return (0);
}

int	check_buf_and_remain(char *bf, char **remain)
{
	if (!bf)
		return (-1);
	if (*remain == NULL)
		*remain = ft_memalloc((1) * sizeof(char));
	return (0);
}

int	get_next_line(int fd, char **line)
{
	unsigned long long	rbyte;
	char				*bf;
	static char			*remain;
	char				*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || (read(fd, "", 0) < 0))
		return (-1);
	bf = (char *)malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (check_buf_and_remain(bf, &remain) < 0)
		return (-1);
	while ((!ft_strchr(remain, '\n'))
		&& ((rbyte = read(fd, bf, BUFFER_SIZE)) > 0))
	{
		bf[rbyte] = '\0';
		if (!remain)
			remain = ft_strdup(bf);
		else
		{
			tmp = remain;
			remain = ft_strjoin(remain, bf);
			ft_memdel((void **)&tmp);
		}
	}
	free(bf);
	return (check_remain(&remain, line));
}
