/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:54:17 by dbekic            #+#    #+#             */
/*   Updated: 2023/05/16 18:10:49 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void    ft_init_img(t_data *d)
{
    t_img temp;
    t_img front_image;

    d->img.img = mlx_new_image(d->img.mlx, W, H);
    d->img.addr = mlx_get_data_addr(d->img.img, &d->img.bits_per_pixel, &d->img.line_length,
                                &d->img.endian);
    // front_image = d->img;
    
    // mlx_put_image_to_window(d->img.mlx, d->img.mlx_win, d->img.img, 0, 0);
}