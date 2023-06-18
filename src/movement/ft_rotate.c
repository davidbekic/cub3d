/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:45:53 by dbekic            #+#    #+#             */
/*   Updated: 2023/06/18 17:21:19 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void ft_rotate_left(t_data *d)
{
    double old_dir_x = d->rc.dir_x;
    d->rc.dir_x = d->rc.dir_x * cos(ROT_SPEED) - d->rc.dir_y * sin(ROT_SPEED);
    d->rc.dir_y = old_dir_x * sin(ROT_SPEED) + d->rc.dir_y * cos(ROT_SPEED);
    double old_camera_plane_x = d->rc.camera_plane_x;
    d->rc.camera_plane_x = d->rc.camera_plane_x * cos(ROT_SPEED) - d->rc.camera_plane_y * sin(ROT_SPEED);
    d->rc.camera_plane_y = old_camera_plane_x * sin(ROT_SPEED) + d->rc.camera_plane_y * cos(ROT_SPEED);
}

void ft_rotate_right(t_data *d)
{
    double old_dir_x = d->rc.dir_x;
    d->rc.dir_x = d->rc.dir_x * cos(-ROT_SPEED) - d->rc.dir_y * sin(-ROT_SPEED);
    d->rc.dir_y = old_dir_x * sin(-ROT_SPEED) + d->rc.dir_y * cos(-ROT_SPEED);
    double old_camera_plane_x = d->rc.camera_plane_x;
    d->rc.camera_plane_x = d->rc.camera_plane_x * cos(-ROT_SPEED) - d->rc.camera_plane_y * sin(-ROT_SPEED);
    d->rc.camera_plane_y = old_camera_plane_x * sin(-ROT_SPEED) + d->rc.camera_plane_y * cos(-ROT_SPEED);
}
