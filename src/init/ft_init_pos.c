/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:39:06 by davidbekic        #+#    #+#             */
/*   Updated: 2023/06/13 14:29:06 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void ft_init_pos(t_data *d, int i, int j, char pos)
{
    d->rc.pos_x = i + WALL_DISTANCE;
    d->rc.pos_y = j + WALL_DISTANCE;
    if (pos == 'N')
    {
        d->rc.dir_x = -1;
        d->rc.dir_y = 0;
        d->rc.camera_plane_x = 0;
        d->rc.camera_plane_y = .66;
    }
    else if (pos == 'E')
    {
        d->rc.dir_x = 0;
        d->rc.dir_y = 1;
        d->rc.camera_plane_x = .66;
        d->rc.camera_plane_y = 0;
    }
    else if (pos == 'S')
    {
        d->rc.dir_x = 1;
        d->rc.dir_y = 0;
        d->rc.camera_plane_x = 0;
        d->rc.camera_plane_y = -.66;
    }
    else if (pos == 'W')
    {
        d->rc.dir_x = 0;
        d->rc.dir_y = -1;
        d->rc.camera_plane_x = -0.66;
        d->rc.camera_plane_y = 0;
    }
}