/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:23:39 by dbekic            #+#    #+#             */
/*   Updated: 2023/05/16 17:00:21 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cub3d.h"



int ft_key_down(int keycode, t_data *d)
{
    int worldMap2[24][24] =
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};


    printf("Hello from key_hook!: %d\n", keycode);
    mlx_clear_window(d->img.mlx, d->img.mlx_win);

    printf("player_pos_x: %f\n", d->rc.pos_x);
    printf("player_pos_y: %f\n", d->rc.pos_y);
    if (keycode == 53)
        exit(0);

    if (keycode == 125)
    {
        if (worldMap2[(int)(d->rc.pos_x + d->rc.dir_x * d->rc.moveSpeed)][(int)(d->rc.pos_y)] == 0)
            d->rc.pos_x += d->rc.dir_x * d->rc.moveSpeed;
        if (worldMap2[(int)(d->rc.pos_x)][(int)(d->rc.pos_y + d->rc.dir_y * d->rc.moveSpeed)] == 0)
            d->rc.pos_y += d->rc.dir_y * d->rc.moveSpeed;
    }
    // move backwards if no wall behind you
    if (keycode == 126)
    {
        if (worldMap2[(int)(d->rc.pos_x - d->rc.dir_x * d->rc.moveSpeed)][(int)(d->rc.pos_y)] == 0)
            d->rc.pos_x -= d->rc.dir_x * d->rc.moveSpeed;
        if (worldMap2[(int)(d->rc.pos_x)][(int)(d->rc.pos_y - d->rc.dir_y * d->rc.moveSpeed)] == 0)
            d->rc.pos_y -= d->rc.dir_y * d->rc.moveSpeed;
    }
    // rotate to the right
    if (keycode == 124)
    {
        //both camera direction and camera plane must be rotated
        double old_dir_x = d->rc.dir_x;
        d->rc.dir_x = d->rc.dir_x * cos(-d->rc.rotSpeed) - d->rc.dir_y * sin(-d->rc.rotSpeed);
        d->rc.dir_y = old_dir_x * sin(-d->rc.rotSpeed) + d->rc.dir_y * cos(-d->rc.rotSpeed);
        double old_camera_plane_x = d->rc.camera_plane_x;
        d->rc.camera_plane_x = d->rc.camera_plane_x * cos(-d->rc.rotSpeed) - d->rc.camera_plane_y * sin(-d->rc.rotSpeed);
        d->rc.camera_plane_y = old_camera_plane_x * sin(-d->rc.rotSpeed) + d->rc.camera_plane_y * cos(-d->rc.rotSpeed);
    }
    // rotate to the left
    if (keycode == 123)
    {
        // both camera direction and camera plane must be rotated
        double old_dir_x = d->rc.dir_x;
        d->rc.dir_x = d->rc.dir_x * cos(d->rc.rotSpeed) - d->rc.dir_y * sin(d->rc.rotSpeed);
        d->rc.dir_y = old_dir_x * sin(d->rc.rotSpeed) + d->rc.dir_y * cos(d->rc.rotSpeed);
        double old_camera_plane_x = d->rc.camera_plane_x;
        d->rc.camera_plane_x = d->rc.camera_plane_x * cos(d->rc.rotSpeed) - d->rc.camera_plane_y * sin(d->rc.rotSpeed);
        d->rc.camera_plane_y = old_camera_plane_x * sin(d->rc.rotSpeed) + d->rc.camera_plane_y * cos(d->rc.rotSpeed);
    }
    return (0);
}