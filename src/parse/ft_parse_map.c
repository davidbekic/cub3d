/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:25:30 by davidbekic        #+#    #+#             */
/*   Updated: 2023/06/21 13:16:38 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_parse_player_pos(t_data *d)
{
	int	i;
	int	j;
	int	pos_char_found;

	i = 0;
	j = 0;
	pos_char_found = 0;
	while (d->map.arr[i] != NULL)
	{
		while (d->map.arr[i][j] != 0)
		{
			if (d->map.arr[i][j] == 'N' || d->map.arr[i][j] == 'S'
				|| d->map.arr[i][j] == 'E' || d->map.arr[i][j] == 'W')
			{
				if (pos_char_found)
					ft_exit("Multiple player positions found", 1);
				ft_init_pos(d, i, j, d->map.arr[i][j]);
				pos_char_found = 1;
				d->map.arr[i][j] = '0';
			}
			j++;
		}
		i++;
		j = 0;
	}
}

static void	ft_fill_spaces_with_points(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (d->map.arr[i] != NULL)
	{
		while (j < d->map.width)
		{
			if (d->map.arr[i][j] == ' ' || (d->map.arr[i][j] == 0
				&& j != d->map.width - 1) || d->map.arr[i][j] == 10)
				d->map.arr[i][j] = '.';
			j++;
		}
		i++;
		j = 0;
	}
}

static void	ft_verify_map(t_data *d)
{
	ft_check_if_map_has_player_pos_and_dir(d);
	ft_parse_player_pos(d);
	ft_check_allowed_chars(d);
	ft_fill_spaces_with_points(d);
	ft_check_if_first_and_last_line_is_one_or_point(d);
	ft_check_if_first_and_last_columns_is_one_or_point(d);
	ft_check_if_surrounded_by_walls(d);
}

void	ft_parse_map(t_data *d, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		ft_exit("Missing map or read error", 1);
	while (line)
	{
		d->map.arr[++i] = (char *) ft_calloc(sizeof(char)
				* (d->map.width + 1), 1);
		if (!d->map.arr[i])
			ft_exit("Malloc error", 1);
		ft_strcpy(d->map.arr[i], line);
		free(line);
		line = get_next_line(fd);
		if (i > 2000 || ft_strlen(line) > 2000)
			ft_exit("Too big map", 1);
	}
	d->map.arr[++i] = NULL;
	ft_verify_map(d);
}
