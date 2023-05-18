/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:15:37 by davidbekic        #+#    #+#             */
/*   Updated: 2023/05/18 13:06:40 by davidbekic       ###   ########.fr       */
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
                ft_my_mlx_pixel_put(&d->back_img_buffer, x, y, ft_create_rgb(50, 0, 0));
            else
                ft_my_mlx_pixel_put(&d->back_img_buffer, x, y, ft_create_rgb(0, 0, 50));
            x++;
        }
        y++;
        x = 0;
    }
}