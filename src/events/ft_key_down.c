/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:23:39 by dbekic            #+#    #+#             */
/*   Updated: 2023/05/19 00:32:21 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

extern int worldMap[24][24];

int ft_key_down(int keycode, t_data *d)
{
    // ft_key_down_check(keycode, d);
    ft_key_up_check(keycode, d);

    printf("keycode: %d\n", keycode);
    printf("d->keys.up: %d\n", d->keys.up);
    if (keycode == 53)
        exit(0);

    if (d->keys.down)
    {
        if (worldMap[(int)(d->rc.pos_x + d->rc.dir_x * MOVE_SPEED)][(int)(d->rc.pos_y)] == 0)
            d->rc.pos_x += d->rc.dir_x * MOVE_SPEED;
        if (worldMap[(int)(d->rc.pos_x)][(int)(d->rc.pos_y + d->rc.dir_y * MOVE_SPEED)] == 0)
            d->rc.pos_y += d->rc.dir_y * MOVE_SPEED;
    }
    if (d->keys.up)
    {
        if (worldMap[(int)(d->rc.pos_x - d->rc.dir_x * MOVE_SPEED)][(int)(d->rc.pos_y)] == 0)
            d->rc.pos_x -= d->rc.dir_x * MOVE_SPEED;
        if (worldMap[(int)(d->rc.pos_x)][(int)(d->rc.pos_y - d->rc.dir_y * MOVE_SPEED)] == 0)
            d->rc.pos_y -= d->rc.dir_y * MOVE_SPEED;
    }
    if (d->keys.left)
    {
        if (worldMap[(int)(d->rc.pos_x - d->rc.dir_x * MOVE_SPEED)][(int)(d->rc.pos_y)] == 0)
            d->rc.pos_x -= d->rc.dir_y * MOVE_SPEED;
        if (worldMap[(int)(d->rc.pos_x)][(int)(d->rc.pos_y - d->rc.dir_y * MOVE_SPEED)] == 0)
            d->rc.pos_y -= d->rc.dir_x * MOVE_SPEED;
    }
    if (d->keys.right)
    // move backwards if no wall behind you if (keycode == 125)
    {
        if (worldMap[(int)(d->rc.pos_x - d->rc.dir_x * MOVE_SPEED)][(int)(d->rc.pos_y)] == 0)
            d->rc.pos_x += d->rc.dir_y * MOVE_SPEED;
        if (worldMap[(int)(d->rc.pos_x)][(int)(d->rc.pos_y - d->rc.dir_y * MOVE_SPEED)] == 0)
            d->rc.pos_y += d->rc.dir_x * MOVE_SPEED;
    }
    // rotate to the right
    if (keycode == 124)
    {
        //both camera direction and camera plane must be rotated
        double old_dir_x = d->rc.dir_x;
        d->rc.dir_x = d->rc.dir_x * cos(-ROT_SPEED) - d->rc.dir_y * sin(-ROT_SPEED);
        d->rc.dir_y = old_dir_x * sin(-ROT_SPEED) + d->rc.dir_y * cos(-ROT_SPEED);
        double old_camera_plane_x = d->rc.camera_plane_x;
        d->rc.camera_plane_x = d->rc.camera_plane_x * cos(-ROT_SPEED) - d->rc.camera_plane_y * sin(-ROT_SPEED);
        d->rc.camera_plane_y = old_camera_plane_x * sin(-ROT_SPEED) + d->rc.camera_plane_y * cos(-ROT_SPEED);
    }
    // rotate to the left
    if (keycode == 123)
    {
        // both camera direction and camera plane must be rotated
        double old_dir_x = d->rc.dir_x;
        d->rc.dir_x = d->rc.dir_x * cos(ROT_SPEED) - d->rc.dir_y * sin(ROT_SPEED);
        d->rc.dir_y = old_dir_x * sin(ROT_SPEED) + d->rc.dir_y * cos(ROT_SPEED);
        double old_camera_plane_x = d->rc.camera_plane_x;
        d->rc.camera_plane_x = d->rc.camera_plane_x * cos(ROT_SPEED) - d->rc.camera_plane_y * sin(ROT_SPEED);
        d->rc.camera_plane_y = old_camera_plane_x * sin(ROT_SPEED) + d->rc.camera_plane_y * cos(ROT_SPEED);
    }
    return (0);
}