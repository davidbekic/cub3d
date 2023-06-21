/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:32:43 by davidbekic        #+#    #+#             */
/*   Updated: 2023/06/21 13:14:48 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_remove_isspace_from_end_of_str(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (str[i] == 32 || str[i] == 10)
	{
		str[i] = 0;
		i--;
	}
}

int	ft_open_file_for_reading(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_exit("file didnt open", 1);
	return (fd);
}

int	ft_get_map_height(t_data *d, char *path)
{
	int		n;
	int		fd;
	char	*buf;
	int		start_count;

	start_count = 0;
	n = 0;
	fd = ft_open_file_for_reading(path);
	while (1)
	{
		n++;
		buf = get_next_line(fd);
		if (!buf)
			break ;
		if (n == d->map.start_line)
			start_count = 1;
		if (start_count)
		{
			if (d->map.width < (int)ft_strlen(buf))
				d->map.width = (int)ft_strlen(buf);
		}
		free(buf);
	}
	close(fd);
	return (n - d->map.start_line);
}

void	ft_check_extension(char *str)
{
	int	i;

	ft_remove_isspace_from_end_of_str(str);
	i = 0;
	str[ft_strlen(str)] = 0;
	while (str[i] != 0)
		i++;
	if (!(str[i - 1] == 'b' && str[i - 2] == 'u'
			&& str[i - 3] == 'c' && str[i - 4] == '.'))
		ft_exit("Wrong file extension", 1);
}
