/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:23:39 by dbekic            #+#    #+#             */
/*   Updated: 2023/05/18 13:18:20 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

extern int worldMap[24][24];

int ft_key_down(int keycode, t_data *d)
{

    printf("Hello from key_hook!: %d\n", keycode);
    // mlx_clear_window(d->img.mlx, d->img.mlx_win);

    printf("player_pos_x: %f\n", d->rc.pos_x);
    printf("player_pos_y: %f\n", d->rc.pos_y);
    if (keycode == 53)
        exit(0);

    if (keycode == 126)
    {
        if (worldMap[(int)(d->rc.pos_x + d->rc.dir_x * MOVE_SPEED)][(int)(d->rc.pos_y)] == 0)
            d->rc.pos_x += d->rc.dir_x * MOVE_SPEED;
        if (worldMap[(int)(d->rc.pos_x)][(int)(d->rc.pos_y + d->rc.dir_y * MOVE_SPEED)] == 0)
            d->rc.pos_y += d->rc.dir_y * MOVE_SPEED;
    }
    if (keycode == 125)
    // move backwards if no wall behind you if (keycode == 125)
    {
        if (worldMap[(int)(d->rc.pos_x - d->rc.dir_x * MOVE_SPEED)][(int)(d->rc.pos_y)] == 0)
            d->rc.pos_x -= d->rc.dir_x * MOVE_SPEED;
        if (worldMap[(int)(d->rc.pos_x)][(int)(d->rc.pos_y - d->rc.dir_y * MOVE_SPEED)] == 0)
            d->rc.pos_y -= d->rc.dir_y * MOVE_SPEED;
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