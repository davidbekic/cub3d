/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:46:29 by dbekic            #+#    #+#             */
/*   Updated: 2023/06/21 12:40:07 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	ft_extract_color(char *line, int *color, int *index)
{
	int	digit_found;

	digit_found = 0;
	while (line[*index] == 32)
		*index += 1;
	*color = 0;
	while (line[*index] != ',')
	{
		if (ft_is_digit(line[*index]))
		{
			digit_found = 1;
			*color = (*color * 10) + (line[*index] - '0');
		}
		else if (line[*index] != 32 && line[*index] != 10)
			return (1);
		*index += 1;
	}
	if (*color > 255 || *color < 0 || !digit_found)
		return (1);
	*index += 1;
	return (0);
}

static int	ft_extract_last_color(char *line, int *color, int *index)
{
	int	digit_found;

	digit_found = 0;
	if (!ft_strlen(line + *index))
		return (1);
	while (line[*index] == 32)
		*index += 1;
	*color = 0;
	while (line[*index] != 0)
	{
		if (ft_is_digit(line[*index]))
		{
			digit_found = 1;
			*color = (*color * 10) + (line[*index] - '0');
		}
		else if (line[*index] != 32 && line[*index] != 10)
			return (1);
		*index += 1;
	}
	if (*color > 255 || *color < 0 || !digit_found)
		return (1);
	return (0);
}

void	ft_parse_color(char *line, t_color *color)
{
	int	i;

	i = 0;
	if (color->r >= 0)
		ft_exit("duplicate element", 1);
	if (ft_extract_color(line, &color->r, &i))
		ft_exit("bad color value", 1);
	if (ft_extract_color(line, &color->g, &i))
		ft_exit("bad color value", 1);
	if (ft_extract_last_color(line, &color->b, &i))
		ft_exit("bad color value", 1);
}
