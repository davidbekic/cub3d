/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:51:05 by dbekic            #+#    #+#             */
/*   Updated: 2023/05/19 18:02:58 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int ft_render_frame(t_data *d)
{
    usleep(3750);

    // clock_t startTime, endTime;
    // double deltaTime;
    // Perform the drawing operations.
    // startTime = clock();
    ft_draw_ceiling_and_floor(d);
    ft_cast_rays(d);
    // endTime = clock();
    //         deltaTime = ((double) (endTime - startTime)) / CLOCKS_PER_SEC;  // Time elapsed in seconds for the frame.
    //     printf("Time to render frame: %f seconds\n", deltaTime);

    // Now all drawing is done, so we can put the image to the window.
    // usleep(37500);
    mlx_put_image_to_window(d->img.mlx, d->img.mlx_win, d->back_img_buffer.img, 0, 0);

    // Destroy the old front buffer image.
    mlx_destroy_image(d->img.mlx, d->back_img_buffer.img);

    // Swap buffers: Move the back buffer to the front.
    d->front_img_buffer = d->back_img_buffer;

    // Create a new image for the back buffer for the next frame.
    ft_init_img(&d->back_img_buffer, d->img.mlx);

    return (0);
}