/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:51:05 by dbekic            #+#    #+#             */
/*   Updated: 2023/05/16 18:10:26 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void ft_draw_vertical_line(int x, int draw_start, int draw_end, int color, t_img *img)
{
    int y;

    y = draw_start;


    while (y < draw_end)
    {
        my_mlx_pixel_put(img, x, y, color);
        y++;
    }
}

double ft_abs(double nb)
{
    if (nb < 0)
        return (nb * -1);
    else
        return (nb);
}

int worldMap[2400][2400] =
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

int ft_render_frame(t_data *d)
{

    int x;
    
    x = 0;
    double frame_time = 0;
    // t_img front_img_buffer;
    // t_img temp_img_buffer;
    // while (1)
    //     {
    // temp_img_buffer = front_img_buffer;
    if (d->img.img)
        d->front_img_buffer = d->img;
    d->img.img = NULL;
    
    ft_init_img(d);

    while (x < W)
    {
        
        d->rc.camera_x = 2 * x / (double)W - 1; // value between -1 & 1. Normalised so that we can say how big "part of the camera plane" that part is
        d->rc.ray_dir_x = d->rc.dir_x + d->rc.camera_plane_x * d->rc.camera_x;
        d->rc.ray_dir_y = d->rc.dir_y + d->rc.camera_plane_y * d->rc.camera_x;

        d->rc.map_x = (int)d->rc.pos_x;
        d->rc.map_y = (int)d->rc.pos_y;
        d->rc.hit = 0;

        d->rc.delta_dist_x = (d->rc.ray_dir_x == 0) ? 1e30 : ft_abs(1 / d->rc.ray_dir_x);
        d->rc.delta_dist_y = (d->rc.ray_dir_y == 0) ? 1e30 : ft_abs(1 / d->rc.ray_dir_y);

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
            if (worldMap[d->rc.map_x][d->rc.map_y] > 0)
                d->rc.hit = 1;
        }
        // Check if ray has hit a wall
        // Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
        // hit to the camera plane. Euclidean to center camera point would give fisheye effect!
        // This can be computed as (mapX - pos_x + (1 - stepX) / 2) / rayd->rc.dir_x for side == 0, or same formula with Y
        // for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
        // because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
        // steps, but we subtract deltaDist once because one step more into the wall was taken above.
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
        {
            color = color / 2;
        }

        // draw the pixels of the stripe as a vertical line
        
        ft_draw_vertical_line(x, draw_start, draw_end, color, &d->img);



        // timing for input and FPS counter
        d->rc.old_time = d->rc.time;
        d->rc.time = clock();
        frame_time = (d->rc.time - d->rc.old_time) / 1000; // frame_time is the time this frame has taken, in seconds
        d->rc.moveSpeed = frame_time * 50.0;                      // the constant value is in squares/second
        d->rc.rotSpeed = frame_time * 30.0;                       // the constant value is in radians/second
        x++;
    }
// }   
    // printf("frame time: %f\n", 1.0 / frame_time);         // FPS counter
    d->front_img_buffer = d->img;
    mlx_put_image_to_window(d->img.mlx, d->img.mlx_win, d->front_img_buffer.img, 0, 0);

    return (0);
}