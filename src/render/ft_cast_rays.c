/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:00:51 by davidbekic        #+#    #+#             */
/*   Updated: 2023/05/20 19:48:35 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

extern int worldMap[2400][2400];

static void ft_init_rc_vars(t_data *d, int x)
{
    d->rc.camera_x = 2 * x / (double)W - 1; // value between -1 & 1. Normalised so that we can say how big "part of the camera plane" that part is
    d->rc.ray_dir_x = d->rc.dir_x + d->rc.camera_plane_x * d->rc.camera_x;
    d->rc.ray_dir_y = d->rc.dir_y + d->rc.camera_plane_y * d->rc.camera_x;

    d->rc.ray_map_coor_x = (int)d->rc.pos_x;
    d->rc.ray_map_coor_y = (int)d->rc.pos_y;
    d->rc.hit = 0;

    // d->rc.delta_dist_x = sqrt(1 + (d->rc.ray_dir_y * d->rc.ray_dir_y) / (d->rc.ray_dir_x * d->rc.ray_dir_x));
    // d->rc.delta_dist_y = sqrt(1 + (d->rc.ray_dir_x * d->rc.ray_dir_x) / (d->rc.ray_dir_y* d->rc.ray_dir_y));
    d->rc.delta_dist_x = (d->rc.ray_dir_x == 0) ? 1e30 : fabs(1 / d->rc.ray_dir_x);
    d->rc.delta_dist_y = (d->rc.ray_dir_y == 0) ? 1e30 : fabs(1 / d->rc.ray_dir_y);

    // calculate step and initial sideDist
    if (d->rc.ray_dir_x < 0)
    {
        d->rc.step_x = -1;
        d->rc.side_dist_x = (d->rc.pos_x - d->rc.ray_map_coor_x) * d->rc.delta_dist_x;
    }
    else
    {
        d->rc.step_x = 1;
        d->rc.side_dist_x = (d->rc.ray_map_coor_x + 1.0 - d->rc.pos_x) * d->rc.delta_dist_x;
    }
    if (d->rc.ray_dir_y < 0)
    {
        d->rc.step_y = -1;
        d->rc.side_dist_y = (d->rc.pos_y - d->rc.ray_map_coor_y) * d->rc.delta_dist_y;
    }
    else
    {
        d->rc.step_y = 1;
        d->rc.side_dist_y = (d->rc.ray_map_coor_y + 1.0 - d->rc.pos_y) * d->rc.delta_dist_y;
    }
}

static void ft_dda(t_data *d)
{
    while (d->rc.hit == 0)
    {
        // jump to next map square, either in x-direction, or in y-direction
        if (d->rc.side_dist_x < d->rc.side_dist_y)
        {
            d->rc.side_dist_x += d->rc.delta_dist_x;
            d->rc.ray_map_coor_x += d->rc.step_x;
            d->rc.side = 0;
        }
        else
        {
            d->rc.side_dist_y += d->rc.delta_dist_y;
            d->rc.ray_map_coor_y += d->rc.step_y;
            d->rc.side = 1;
        }
        // Check if ray has hit a wall
        if (worldMap[d->rc.ray_map_coor_x][d->rc.ray_map_coor_y] > 0)
            d->rc.hit = 1;
    }
}

double ft_set_perp_wall_dist(t_data *d)
{
    // Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
    // hit to the camera plane
    if (d->rc.side == 0)
        return ((d->rc.ray_map_coor_x - d->rc.pos_x + (1 - d->rc.step_x) / 2) / d->rc.ray_dir_x);
    else
        return ((d->rc.ray_map_coor_y - d->rc.pos_y + (1 - d->rc.step_y) / 2) / d->rc.ray_dir_y);
}

void    ft_init_wall_props(t_data *d)
{
        // Calculate height of line to draw on screen
        d->rc.wall_height = (int)(H / d->rc.perp_wall_dist);

        // calculate lowest and highest pixel to fill in current stripe
        d->rc.draw_start = -d->rc.wall_height / 2 + (H * 1) / 2;
        if (d->rc.draw_start < 0)
            d->rc.draw_start = 0;
        d->rc.draw_end = d->rc.wall_height / 2 + (H * 1) / 2;
        if (d->rc.draw_end >= (H * 1))
            d->rc.draw_end = (H * 1) - 1;

        //calculate value of d->rc.wall_x
        if (d->rc.side == 0)
            d->rc.wall_x = d->rc.pos_y + d->rc.perp_wall_dist * d->rc.ray_dir_y;
        else
            d->rc.wall_x = d->rc.pos_x + d->rc.perp_wall_dist * d->rc.ray_dir_x;
        d->rc.wall_x -= floor((d->rc.wall_x));
}

int ft_get_wall_direction(int side, double ray_dir_x, double ray_dir_y) {
        if (side == 0 && ray_dir_x >= 0)
            return (0);
        else if (side == 0 && ray_dir_x <= 0)
            return (1);
        else if (side == 1 && ray_dir_y >= 0)
            return (2);
        else
            return (3);
        // printf("raydirs: %d %d\n", ray_dir_x, ray_dir_y);
        // if (side == 0)
        //     return (0);
        // if (side == 1)
        //     return (1);
}

void    ft_map_texture(t_data *d, int x)
{
        //x coordinate on the texture
        int dir;
        dir =
            ft_get_wall_direction(d->rc.side, d->rc.ray_dir_x, d->rc.ray_dir_y);
        int texX = (int)(d->rc.wall_x * (double)d->tex[dir].width);
        if ((d->rc.side == 0 && d->rc.ray_dir_x > 0) ||
            (d->rc.side == 1 && d->rc.ray_dir_y < 0))
            texX = d->tex[dir].width - texX - 1;

        // How much to increase the texture coordinate per screen pixel
        // double step = 1.0 * (d->tex[0].height / d->rc.wall_height);
        // // Starting texture coordinate
        // double texPos = (d->rc.draw_start - H / 2 + d->rc.wall_height / 2) *
        // step;

        double step = (1.0 * d->tex[dir].height / d->rc.wall_height);
        double texPos =
            (d->rc.draw_start - H / 2 + d->rc.wall_height / 2) * step;
        // double texPos = 0;

        // double texPos = 0;
        // double texPos = 0;
        for (int y = d->rc.draw_start; y < d->rc.draw_end; y++) {
            // Cast the texture coordinate to integer, and mask with (64 - 1) in
            // case of overflow int texY = (int)texPos & (d->tex[0].height -
            // 1);
            int texY = (int)texPos & (d->tex[dir].height - 1);
            texPos += step;
            // int color = d->tex[0].img.addr[64 * texY + texX];
            // int color = *(int *)(d->tex[0].img.addr + (texY *
            // d->tex[0].img.line_length
            //             + x * (d->tex[0].img.bits_per_pixel / 8)));
            int color = d->tex[dir].arr[texX][texY];
            // int color = *(int*)(d->tex[0].img.addr + (texY *
            // d->tex[0].img.line_length
            //             + x * (d->tex[0].img.bits_per_pixel / 8)));
            // int color =
            // int color = *(int*) d->tex[0].img.addr + (texY *
            // d->img.line_length + x * (d->img.bits_per_pixel / 8));

            // printf("color: %d\n", color);
            // make color darker for y-sides: R, G and B byte each divided
            // through two with a "shift" and an "and"
            if (d->rc.side == 1)
            color = (color >> 1) & 8355711;
            // if (color > 100)j
            ft_my_mlx_pixel_put(&d->back_img_buffer, x, y, color);
            // buffer[y][x] = color;
        }
}

void ft_cast_rays(t_data *d)
{
    int x = -1;
    // double frame_time = 0;
    // int buffer[H][W];
    while (++x < W)
    {
        ft_init_rc_vars(d, x);
        ft_dda(d);
        d->rc.perp_wall_dist = ft_set_perp_wall_dist(d);
        ft_init_wall_props(d);
        ft_map_texture(d, x);
    }
        // ft_draw_buffer(d, buffer);
        // for(int y = 0; y < H; y++) for(int x = 0; x < W; x++) buffer[y][x] = 0; //clear the buffer instead of cls()

        // ft_draw_vertical_line(x, d->rc.draw_start, d->rc.draw_end, color, &d->back_img_buffer);

        // timing for input and FPS counter
        // d->rc.old_time = d->rc.time;
        // d->rc.time = clock();
        // double frame_time = (d->rc.time - d->rc.old_time) / 1000; // frame_time is the time this frame has taken, in seconds
        // printf("frame_time: %f\n", frame_time);
        // d->rc.moveMOVE_SPEED = frame_time * 5.0; // the constant value is in squares/second
        // d->rc.rotMOVE_SPEED = frame_time * 3.0;  // the constant value is in radians/second
        // printf("rotMOVE_SPEED: %f\n", d->rc.rotMOVE_SPEED);

    }
