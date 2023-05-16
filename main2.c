#include "./mlx/mlx.h"
#include <stdio.h>
#include <time.h>
#include "./cub3d.h"

#define H 1080
#define W 1920

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

void my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int key_hook(int keycode, t_data *d)
{
    printf("Hello from key_hook!: %d\n", keycode);

    if (keycode == 125)
    {
        if (worldMap[(int)(d->pos_x + d->dir_x * d->moveSpeed)][(int)(d->pos_y)] == 0)
            d->pos_x += d->dir_x * d->moveSpeed;
        if (worldMap[(int)(d->pos_x)][(int)(d->pos_y + d->dir_y * d->moveSpeed)] == 0)
            d->pos_y += d->dir_y * d->moveSpeed;
    }
    // move backwards if no wall behind you
    if (keycode == 126)
    {
        if (worldMap[(int)(d->pos_x - d->dir_x * d->moveSpeed)][(int)(d->pos_y)] == 0)
            d->pos_x -= d->dir_x * d->moveSpeed;
        if (worldMap[(int)(d->pos_x)][(int)(d->pos_y - d->dir_y * d->moveSpeed)] == 0)
            d->pos_y -= d->dir_y * d->moveSpeed;
    }
    // rotate to the right
    if (keycode == 124)
    {
        // both camera direction and camera plane must be rotated
        double old_dir_x = d->dir_x;
        d->dir_x = d->dir_x * cos(-d->rotSpeed) - d->dir_y * sin(-d->rotSpeed);
        d->dir_y = old_dir_x * sin(-d->rotSpeed) + d->dir_y * cos(-d->rotSpeed);
        double old_camera_plane_x = d->camera_plane_x;
        d->camera_plane_x = d->camera_plane_x * cos(-d->rotSpeed) - d->camera_plane_y * sin(-d->rotSpeed);
        d->camera_plane_y = old_camera_plane_x * sin(-d->rotSpeed) + d->camera_plane_y * cos(-d->rotSpeed);
    }
    // rotate to the left
    if (keycode == 123)
    {
        // both camera direction and camera plane must be rotated
        double old_dir_x = d->dir_x;
        d->dir_x = d->dir_x * cos(d->rotSpeed) - d->dir_y * sin(d->rotSpeed);
        d->dir_y = old_dir_x * sin(d->rotSpeed) + d->dir_y * cos(d->rotSpeed);
        double old_camera_plane_x = d->camera_plane_x;
        d->camera_plane_x = d->camera_plane_x * cos(d->rotSpeed) - d->camera_plane_y * sin(d->rotSpeed);
        d->camera_plane_y = old_camera_plane_x * sin(d->rotSpeed) + d->camera_plane_y * cos(d->rotSpeed);
    }
    return (0);
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

void ft_init_vars(t_data *d)
{
    d->dir_x = -1;
    d->dir_y = 0;
    d->pos_x = 12;
    d->pos_y = 12;
    d->camera_plane_x = 0;
    d->camera_plane_y = .66;
    d->hit = 0;
    d->camera_x = 0;
    d->ray_dir_x = 0;
    d->ray_dir_y = 0;
    d->map_x = 0;
    d->map_y = 0;
    d->step_x = 0;
    d->step_y = 0;
    d->side = 0;
    d->side_dist_x = 0;
    d->side_dist_y = 0;
    d->delta_dist_x = 0;
    d->delta_dist_y = 0;
    d->perp_wall_dist = 0;
    d->time = clock(); // time of current frame
    d->old_time = 0;   // time of previous frame
    d->moveSpeed = 0;
    d->rotSpeed = 0;
}

int render_next_frame(t_data *d)
{

    while (1)
    {
        while (d->x < W)
        {
            printf("W: %d\n", W);
            d->camera_x = 2 * d->x / (double)W - 1; // value between -1 & 1. Normalised so that we can say how big "part of the camera plane" that part is
            d->ray_dir_x = d->dir_x + d->camera_plane_x * d->camera_x;
            d->ray_dir_y = d->dir_y + d->camera_plane_y * d->camera_x;

            d->map_x = (int)d->pos_x;
            d->map_y = (int)d->pos_y;
            d->hit = 0;

            d->delta_dist_x = (d->ray_dir_x == 0) ? 1e30 : ft_abs(1 / d->ray_dir_x);
            d->delta_dist_y = (d->ray_dir_y == 0) ? 1e30 : ft_abs(1 / d->ray_dir_y);

            // calculate step and initial sideDist
            if (d->ray_dir_x < 0)
            {
                d->step_x = -1;
                d->side_dist_x = (d->pos_x - d->map_x) * d->delta_dist_x;
            }
            else
            {
                d->step_x = 1;
                d->side_dist_x = (d->map_x + 1.0 - d->pos_x) * d->delta_dist_x;
            }
            if (d->ray_dir_y < 0)
            {
                d->step_y = -1;
                d->side_dist_y = (d->pos_y - d->map_y) * d->delta_dist_y;
            }
            else
            {
                d->step_y = 1;
                d->side_dist_y = (d->map_y + 1.0 - d->pos_y) * d->delta_dist_y;
            }

            // perform DDA
            while (d->hit == 0)
            {
                // jump to next map square, either in x-direction, or in y-direction
                if (d->side_dist_x < d->side_dist_y)
                {
                    d->side_dist_x += d->delta_dist_x;
                    d->map_x += d->step_x;
                    d->side = 0;
                }
                else
                {
                    d->side_dist_y += d->delta_dist_y;
                    d->map_y += d->step_y;
                    d->side = 1;
                }
                if (worldMap[d->map_x][d->map_y] > 0)
                    d->hit = 1;
            }
            // Check if ray has hit a wall
            // Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
            // hit to the camera plane. Euclidean to center camera point would give fisheye effect!
            // This can be computed as (mapX - pos_x + (1 - stepX) / 2) / rayd->dir_x for side == 0, or same formula with Y
            // for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
            // because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
            // steps, but we subtract deltaDist once because one step more into the wall was taken above.
            if (d->side == 0)
                d->perp_wall_dist = (d->side_dist_x - d->delta_dist_x);
            else
                d->perp_wall_dist = (d->side_dist_y - d->delta_dist_y);

            // Calculate height of line to draw on screen
            int line_height = (int)(H / d->perp_wall_dist);

            // calculate lowest and highest pixel to fill in current stripe
            int draw_start = -line_height / 2 + (H * 1) / 2;
            if (draw_start < 0)
                draw_start = 0;
            int draw_end = line_height / 2 + (H * 1) / 2;
            if (draw_end >= (H * 1))
                draw_end = (H * 1) - 1;

            // choose wall color
            int color = 255;
            switch (worldMap[d->map_x][d->map_y])
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
            if (d->side == 1)
            {
                color = color / 2;
            }

            // draw the pixels of the stripe as a vertical line
            ft_draw_vertical_line(d->x, draw_start, draw_end, color, &d->img);
            printf("wtf\n");
            mlx_put_image_to_window(d->vars.mlx, d->vars.win, d->img.img, 0, 0);
            mlx_key_hook(d->vars.win, key_hook, &d->vars);

            d->x++;

            // timing for input and FPS counter
            d->old_time = d->time;
            d->time = clock();
            double frame_time = (d->time - d->old_time) / 1000.0; // frame_time is the time this frame has taken, in seconds
            printf("frame time: %f\n", 1.0 / frame_time);         // FPS counter
            d->moveSpeed = frame_time * 5.0;                      // the constant value is in squares/second
            d->rotSpeed = frame_time * 3.0;                       // the constant value is in radians/second
        }
    }
}

int main(void)
{
    t_data *d;
    // void	*mlx;
    // void	*mlx_win;

    d->vars.mlx = mlx_init();
    d->vars.win = mlx_new_window(d->vars.mlx, W, H, "Hello world!");
    d->img.img = mlx_new_image(d->vars.mlx, W, H);

    d = malloc(20000);

    ft_init_vars(d);
    // vars.mlx = mlx_init();
    // vars.win = mlx_new_window(vars.mlx, W, H, "Hello world!");
    // img.img = mlx_new_image(vars.mlx, W, H);
    d->img.addr = mlx_get_data_addr(d->img.img, &d->img.bits_per_pixel, &d->img.line_length,
                                    &d->img.endian);
    // int offset = (y * line_length + x * (bits_per_pixel / 8));

    d->x = 0;

    mlx_loop_hook(d->vars.mlx, render_next_frame, &d);
    mlx_loop(d->vars.mlx);
}