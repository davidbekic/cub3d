#include "../../include/cub3d.h"

void ft_init_vars(t_data *d)
{
    d->img.mlx = mlx_init();
    d->img.mlx_win = mlx_new_window(d->img.mlx, W, H, "cub3d - dbekic");
    ft_init_img(&d->img, d->img.mlx);
    ft_init_img(&d->back_img_buffer, d->img.mlx);
    ft_init_img(&d->front_img_buffer, d->img.mlx);

    // d->img.img = mlx_new_image(d->img.mlx, W, H);
    // d->img.addr = mlx_get_data_addr(d->img.img, &d->img.bits_per_pixel, &d->img.line_length,
    //                                 &d->img.endian);
    // mlx_put_image_to_window(d->img.mlx, d->img.mlx_win, d->img.img, 0, 0);
    d->rc.dir_x = -1;
    d->rc.dir_y = 0;
    d->rc.pos_x = 2;
    d->rc.pos_y = 2;
    d->rc.camera_plane_x = 0;
    d->rc.camera_plane_y = .66;
    d->rc.hit = 0;
    d->rc.camera_x = 0;
    d->rc.ray_dir_x = 0;
    d->rc.ray_dir_y = 0;
    d->rc.map_x = 0;
    d->rc.map_y = 0;
    d->rc.step_x = 0;
    d->rc.step_y = 0;
    d->rc.side = 0;
    d->rc.side_dist_x = 0;
    d->rc.side_dist_y = 0;
    d->rc.delta_dist_x = 0;
    d->rc.delta_dist_y = 0;
    d->rc.perp_wall_dist = 0;
    d->rc.time = 0;     // time of current frame
    d->rc.old_time = 0; // time of previous frame
    d->rc.moveMOVE_SPEED = 0;
    d->rc.rotMOVE_SPEED = 0;
}
