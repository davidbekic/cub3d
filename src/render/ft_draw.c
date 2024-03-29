/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:15:37 by davidbekic        #+#    #+#             */
/*   Updated: 2023/06/21 12:51:28 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_draw_ceiling_and_floor(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < H)
	{
		while (x < W)
		{
			if (y > (H / 2))
				ft_my_mlx_pixel_put(&d->img, x, y,
					ft_create_trgb(1, d->floor.r,
						d->floor.g, d->floor.b));
			else
				ft_my_mlx_pixel_put(&d->img, x, y,
					ft_create_trgb(1, d->ceiling.r,
						d->ceiling.g, d->ceiling.b));
			x++;
		}
		y++;
		x = 0;
	}
}
