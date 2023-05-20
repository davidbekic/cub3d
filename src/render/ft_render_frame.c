/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:51:05 by dbekic            #+#    #+#             */
/*   Updated: 2023/05/20 19:22:41 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int ft_render_frame(t_data *d)
{
    usleep(3750);
    ft_draw_ceiling_and_floor(d);
    ft_cast_rays(d);
    mlx_put_image_to_window(d->img.mlx, d->img.mlx_win, d->back_img_buffer.img,
                            0, 0);
    // Destroy the old front buffer image.
    mlx_destroy_image(d->img.mlx, d->back_img_buffer.img);
    // Swap buffers: Move the back buffer to the front.
    d->front_img_buffer = d->back_img_buffer;
    // Create a new image for the back buffer for the next frame.
    ft_init_img(&d->back_img_buffer, d->img.mlx);
    return (0);
}