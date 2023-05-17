/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:54:17 by dbekic            #+#    #+#             */
/*   Updated: 2023/05/17 10:56:14 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void ft_init_img(t_data *d)
{
    d->img.img = mlx_new_image(d->img.mlx, W, H);
    d->img.addr = mlx_get_data_addr(d->img.img, &d->img.bits_per_pixel, &d->img.line_length,
                                    &d->img.endian);
}