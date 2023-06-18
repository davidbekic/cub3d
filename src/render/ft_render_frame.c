/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:51:05 by dbekic            #+#    #+#             */
/*   Updated: 2023/06/18 19:31:31 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int ft_render_frame(t_data *d)
{
    usleep(1000);
    ft_key_down(d);
    ft_draw_ceiling_and_floor(d);
    ft_cast_rays(d);
    mlx_put_image_to_window(d->img.mlx, d->img.mlx_win, d->back_img_buffer.img,
                            0, 0);
    mlx_destroy_image(d->img.mlx, d->back_img_buffer.img);
    d->front_img_buffer = d->back_img_buffer;
    ft_init_img(&d->back_img_buffer, d->img.mlx);
    return (0);
}