/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:00:51 by davidbekic        #+#    #+#             */
/*   Updated: 2023/05/17 11:17:46 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

extern int worldMap[2400][2400];





void ft_cast_rays(t_data *d)
{
    int x = 0;
    double frame_time = 0;
    while (x < W)
    {
        d->rc.camera_x = 2 * x / (double)W - 1; // value between -1 & 1. Normalised so that we can say how big "part of the camera plane" that part is
        d->rc.ray_dir_x = d->rc.dir_x + d->rc.camera_plane_x * d->rc.camera_x;
        d->rc.ray_dir_y = d->rc.dir_y + d->rc.camera_plane_y * d->rc.camera_x;

        d->rc.map_x = (int)d->rc.pos_x;
        d->rc.map_y = (int)d->rc.pos_y;
        d->rc.hit = 0;

        d->rc.delta_dist_x = (d->rc.ray_dir_x == 0) ? 1e30 : fabs(1 / d->rc.ray_dir_x);
        d->rc.delta_dist_y = (d->rc.ray_dir_y == 0) ? 1e30 : fabs(1 / d->rc.ray_dir_y);

        // calculate step and initial sideDist
        if (d->rc.ray_dir_x < 0)
        {
            d->rc.step_x = -1;
            d->rc.side_dist_x = (d->rc.pos_x - d->rc.map_x) * d->rc.delta_dist_x;
        }
        else
        {
            d->rc.step_x = 1;
            d->rc.side_dist_x = (d->rc.map_x + 1.0 - d->rc.pos_x) * d->rc.delta_dist_x;
        }
        if (d->rc.ray_dir_y < 0)
        {
            d->rc.step_y = -1;
            d->rc.side_dist_y = (d->rc.pos_y - d->rc.map_y) * d->rc.delta_dist_y;
        }
        else
        {
            d->rc.step_y = 1;
            d->rc.side_dist_y = (d->rc.map_y + 1.0 - d->rc.pos_y) * d->rc.delta_dist_y;
        }

        // perform DDA
        while (d->rc.hit == 0)
        {
            // jump to next map square, either in x-direction, or in y-direction
            if (d->rc.side_dist_x < d->rc.side_dist_y)
            {
                d->rc.side_dist_x += d->rc.delta_dist_x;
                d->rc.map_x += d->rc.step_x;
                d->rc.side = 0;
            }
            else
            {
                d->rc.side_dist_y += d->rc.delta_dist_y;
                d->rc.map_y += d->rc.step_y;
                d->rc.side = 1;
            }
            // Check if ray has hit a wall
            if (worldMap[d->rc.map_x][d->rc.map_y] > 0)
                d->rc.hit = 1;
        }
        // Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
        // hit to the camera plane
        if (d->rc.side == 0)
            d->rc.perp_wall_dist = (d->rc.side_dist_x - d->rc.delta_dist_x);
        else
            d->rc.perp_wall_dist = (d->rc.side_dist_y - d->rc.delta_dist_y);

        // Calculate height of line to draw on screen
        int line_height = (int)(H / d->rc.perp_wall_dist);

        // calculate lowest and highest pixel to fill in current stripe
        int draw_start = -line_height / 2 + (H * 1) / 2;
        if (draw_start < 0)
            draw_start = 0;
        int draw_end = line_height / 2 + (H * 1) / 2;
        if (draw_end >= (H * 1))
            draw_end = (H * 1) - 1;

        // choose wall color
        int color = 255;
        switch (worldMap[d->rc.map_x][d->rc.map_y])
        {
        case 1:
            color = 25255;
            break; // red
        case 2:
            color = 534523;
            break; // green
        case 3:
            color = 392345;
            break; // blue
        case 4:
            color = 18593248;
            break; // white
        default:
            color = 134234;
            break; // yellow
        }

        // give x and y sides different brightness
        if (d->rc.side == 1)
            color = color / 2;

        // draw the pixels of the stripe as a vertical line

        ft_draw_vertical_line(x, draw_start, draw_end, color, &d->img);

        // timing for input and FPS counter
        d->rc.old_time = d->rc.time;
        d->rc.time = clock();
        frame_time = (d->rc.time - d->rc.old_time) / 1000; // frame_time is the time this frame has taken, in seconds
        d->rc.moveSpeed = frame_time * 50.0;               // the constant value is in squares/second
        d->rc.rotSpeed = frame_time * 30.0;                // the constant value is in radians/second
        x++;
    }
}