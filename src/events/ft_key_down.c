/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:50:13 by dbekic            #+#    #+#             */
/*   Updated: 2023/05/16 14:50:26 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int ft_key_down(int keycode, t_data *d)
{
    printf("Hello from key_hook!: %d\n", keycode);

    if (keycode == 125)
    {
        // if (worldMap[(int)(d->pos_x + d->dir_x * d->moveSpeed)][(int)(d->pos_y)] == 0)
        //     d->pos_x += d->dir_x * d->moveSpeed;
        // if (worldMap[(int)(d->pos_x)][(int)(d->pos_y + d->dir_y * d->moveSpeed)] == 0)
        //     d->pos_y += d->dir_y * d->moveSpeed;
    }
    // move backwards if no wall behind you
    if (keycode == 126)
    {
        // if (worldMap[(int)(d->pos_x - d->dir_x * d->moveSpeed)][(int)(d->pos_y)] == 0)
        //     d->pos_x -= d->dir_x * d->moveSpeed;
        // if (worldMap[(int)(d->pos_x)][(int)(d->pos_y - d->dir_y * d->moveSpeed)] == 0)
        //     d->pos_y -= d->dir_y * d->moveSpeed;
    }
    // rotate to the right
    if (keycode == 124)
    {
        // both camera direction and camera plane must be rotated
        // double old_dir_x = d->dir_x;
        // d->dir_x = d->dir_x * cos(-d->rotSpeed) - d->dir_y * sin(-d->rotSpeed);
        // d->dir_y = old_dir_x * sin(-d->rotSpeed) + d->dir_y * cos(-d->rotSpeed);
        // double old_camera_plane_x = d->camera_plane_x;
        // d->camera_plane_x = d->camera_plane_x * cos(-d->rotSpeed) - d->camera_plane_y * sin(-d->rotSpeed);
        // d->camera_plane_y = old_camera_plane_x * sin(-d->rotSpeed) + d->camera_plane_y * cos(-d->rotSpeed);
    }
    // rotate to the left
    if (keycode == 123)
    {
        // both camera direction and camera plane must be rotated
        // double old_dir_x = d->dir_x;
        // d->dir_x = d->dir_x * cos(d->rotSpeed) - d->dir_y * sin(d->rotSpeed);
        // d->dir_y = old_dir_x * sin(d->rotSpeed) + d->dir_y * cos(d->rotSpeed);
        // double old_camera_plane_x = d->camera_plane_x;
        // d->camera_plane_x = d->camera_plane_x * cos(d->rotSpeed) - d->camera_plane_y * sin(d->rotSpeed);
        // d->camera_plane_y = old_camera_plane_x * sin(d->rotSpeed) + d->camera_plane_y * cos(d->rotSpeed);
    }
    return (0);
}