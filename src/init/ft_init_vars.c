#include "../../include/cub3d.h"

void ft_init_vars(t_data *d)
{
    d->img.mlx = mlx_init();
    d->img.mlx_win = mlx_new_window(d->img.mlx, W, H, "cub3d - dbekic");
    d->rc.dir_x = 0;
    d->rc.dir_y = 1;
    d->rc.pos_x = 12;
    d->rc.pos_y = 12;
    d->rc.hit = 0;
    d->rc.camera_plane_x = 1;
    d->rc.camera_plane_y = 0;
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
    d->rc.moveSpeed = 0;
    d->rc.rotSpeed = 0;
}
