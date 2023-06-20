/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:27:47 by davidbekic        #+#    #+#             */
/*   Updated: 2023/06/20 10:10:18 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <ctype.h>

int	ft_is_configurated(t_data *d)
{
	if (!d->tex[NORTH_TEX_INDEX].ready)
		return (0);
	else if (!d->tex[SOUTH_TEX_INDEX].ready)
		return (0);
	else if (!d->tex[EAST_TEX_INDEX].ready)
		return (0);
	else if (!d->tex[WEST_TEX_INDEX].ready)
		return (0);
	else if (d->ceiling.r < 0)
		return (0);
	else if (d->floor.r < 0)
		return (0);
	else
		return (1);
}

void	ft_parse_tex_path(t_data *d, char *line, int index)
{
	int	i;

	i = 0;
	if (d->tex[index].ready)
		ft_exit(d, "element duplicate", 1);
	while (line[i] == 32)
		i++;
	ft_remove_isspace_from_end_of_str(line + i);
	d->tex[index].path = ft_strdup(line + i);
	d->tex[index].path[ft_strlen(line) - i] = 0;
	if (!d->tex[index].path)
		ft_exit(d, "Malloc failed\n", 1);
	d->tex[index].ready = 1;
}

void	ft_parse_line(t_data *d, char *line, char *path, int fd)
{
	while (*line == ' ' && !ft_is_configurated(d))
		line++;
	if (!ft_strncmp(line, "NO ", 3))
		ft_parse_tex_path(d, line + 3, NORTH_TEX_INDEX);
	else if (!ft_strncmp(line, "SO ", 3))
		ft_parse_tex_path(d, line + 3, SOUTH_TEX_INDEX);
	else if (!ft_strncmp(line, "WE ", 3))
		ft_parse_tex_path(d, line + 3, WEST_TEX_INDEX);
	else if (!ft_strncmp(line, "EA ", 3))
		ft_parse_tex_path(d, line + 3, EAST_TEX_INDEX);
	else if (!ft_strncmp(line, "F ", 2))
		ft_parse_color(d, line + 2, &d->floor);
	else if (!ft_strncmp(line, "C ", 2))
		ft_parse_color(d, line + 2, &d->ceiling);
	else if ((line[0] == '1' || (line[0] == ' ')) && ((ft_is_configurated(d))))
	{
		d->map.width = 0;
		d->map.height = ft_get_map_height(d, path);
		d->map.arr = malloc(sizeof(char *) * (d->map.height + 1));
		if (!d->map.arr)
			ft_exit(d, "malloc error", 1);
		d->map.arr[0] = (char *) ft_calloc(d->map.width + 1, sizeof(char));
		if (!d->map.arr[0])
			ft_exit(d, "malloc error", 1);
		strcpy(d->map.arr[0], line);
		ft_parse_map(d, fd);
	}
	else if ((line[0] == '1' || (line[0] == ' ') || line[0] == '0') && ft_strlen(line))
		ft_exit(d, "Bad cub format", 1);
}

int	ft_parse_cub(t_data *d, char *path)
{
	char	*line;
	int		fd;

	d->floor.r = -1;
	d->ceiling.r = -1;
	d->map.start_line = 0;
	d->tex[0].ready = 0;
	d->tex[1].ready = 0;
	d->tex[2].ready = 0;
	d->tex[3].ready = 0;
	d->map.height = 0;
	ft_check_extension(path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_exit(d, "File reading error", 1);
	line = get_next_line(fd);
	while (line)
	{
		d->map.start_line++;
		ft_parse_line(d, line, path, fd);
		free(line);
		line = get_next_line(fd);
	}
	if (d->map.height == 0)
		ft_exit(d, "Bad cub file format or empty", 1);
	close(fd);
/*	int i = 0;
	while (i < d->map.height)
	{
		printf("d->map.arr[%d]: %s\n", i, d->map.arr[i]);
		i++;
	} 
	*/
	return (0);
}
