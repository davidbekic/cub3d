/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:51:05 by dbekic            #+#    #+#             */
/*   Updated: 2023/06/23 09:44:33 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_render_frame(t_data *d)
{
	ft_key_down(d);
	ft_draw_ceiling_and_floor(d);
	ft_cast_rays(d);
	mlx_put_image_to_window(d->img.mlx, d->img.mlx_win, d->img.img, 0, 0);
	mlx_destroy_image(d->img.mlx, d->img.img);
	ft_init_img(&d->img, d->img.mlx);
	return (0);
}
