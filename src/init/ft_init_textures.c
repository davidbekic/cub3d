/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:23:54 by davidbekic        #+#    #+#             */
/*   Updated: 2023/06/23 09:00:45 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	*ft_choose_texture(t_data *d, int i)
{
	if (i == 0)
		return (d->tex[2].path);
	if (i == 1)
		return (d->tex[0].path);
	if (i == 2)
		return (d->tex[1].path);
	else
		return (d->tex[3].path);
}

void	ft_init_textures(t_data *d)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		d->tex[i].img.img = mlx_xpm_file_to_image(
				d->img.mlx, ft_choose_texture(d, i), &d->tex[i].width,
				&d->tex[i].height);
		if (!d->tex[i].img.img)
			ft_exit("Texture not found", 1);
		d->tex[i].img.addr = mlx_get_data_addr(d->tex[i].img.img,
				&d->tex[i].img.bits_per_pixel,
				&d->tex[i].img.line_length, &d->tex[i].img.endian);
		ft_fill_texture(d, i);
		d->tex[i].ready = 1;
	}
}

void	ft_fill_texture(t_data *d, int i)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	d->tex[i].arr = malloc(d->tex[i].height * sizeof(int *));
	if (!d->tex[i].arr)
		ft_exit("Malloc failed", 1);
	while (++y < d->tex[i].height)
	{
		d->tex[i].arr[y] = malloc(d->tex[i].width * sizeof(int));
		if (!d->tex[i].arr[y])
			ft_exit("Malloc failed", 1);
		while (++x < d->tex[i].width)
			d->tex[i].arr[y][x] = ft_my_pixel_get(&d->tex[i].img, y, x);
		if (x == d->tex[i].width)
			x = 0;
	}
}
