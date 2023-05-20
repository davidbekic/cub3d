/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:15:37 by davidbekic        #+#    #+#             */
/*   Updated: 2023/05/20 17:49:09 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void ft_draw_vertical_line(int x, int draw_start, int draw_end, int color, t_img *img)
{
    int y;

    y = draw_start;
    while (y < draw_end)
    {
        ft_my_mlx_pixel_put(img, x, y, color);
        y++;
    }
}

void ft_draw_ceiling_and_floor(t_data *d)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < H)
    {
        while (x < W)
        {
            if (y > (H / 2))
              ft_my_mlx_pixel_put(&d->back_img_buffer, x, y,
                                  ft_create_trgb(1, 60, 60, 60));
            else
                ft_my_mlx_pixel_put(&d->back_img_buffer, x, y,
                                    ft_create_trgb(1, 200, 200, 245));
            x++;
        }
        y++;
        x = 0;
    }
}

void	ft_draw_buffer(t_data *d, int buffer[1080][1920])
{
	int	x;
	int	y;

	y = 0; 
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
            printf("buffer[%d][%d]: %d\n",  y, x, buffer[y][x]);
			ft_my_mlx_pixel_put(&d->img, x, y, buffer[y][x]);
			x++;
		}
		y++;
	}
}