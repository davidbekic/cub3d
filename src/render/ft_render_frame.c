/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:51:05 by dbekic            #+#    #+#             */
/*   Updated: 2023/05/17 11:10:57 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int ft_render_frame(t_data *d)
{

    // t_img front_img_buffer;
    // t_img temp_img_buffer;
    // while (1)
    //     {
    // temp_img_buffer = front_img_buffer;
    if (d->img.img)
        d->front_img_buffer = d->img;
    d->img.img = NULL;

    ft_init_img(d);
    ft_cast_rays(d);

    // }
    // printf("frame time: %f\n", 1.0 / frame_time);         // FPS counter
    d->front_img_buffer = d->img;
    mlx_put_image_to_window(d->img.mlx, d->img.mlx_win, d->front_img_buffer.img, 0, 0);

    return (0);
}