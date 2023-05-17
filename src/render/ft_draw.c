/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:15:37 by davidbekic        #+#    #+#             */
/*   Updated: 2023/05/17 11:20:39 by davidbekic       ###   ########.fr       */
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