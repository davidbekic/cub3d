/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:51:05 by dbekic            #+#    #+#             */
/*   Updated: 2023/06/12 19:11:41 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int ft_render_frame(t_data *d)
{
    // usleep(3750);
    ft_key_down(d);
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
    // printf("d->rc.dir_x = %f\n", d->rc.dir_x);
    // printf("d->rc.dir_y = %f\n", d->rc.dir_y);
    // printf("d->rc.camera_plane_x: %f\n", d->rc.camera_plane_x);
    // printf("d->rc.camera_plane_y: %f\n", d->rc.camera_plane_y);
    return (0);
}