#include "../../include/cub3d.h"

static void ft_init_keys(t_keys *keys)
{
    keys->up = 0;
    keys->down = 0;
    keys->left = 0;
    keys->right = 0;
    keys->rotate_left = 0;
    keys->rotate_right = 0;
    keys->exit_key = 0;
}

static void ft_init_rc(t_rc_data *rc)
{
    rc->wall_height = 0;
    rc->draw_start = 0;
    rc->draw_end = 0;
    rc->wall_x = 0;
    rc->hit = 0;
    rc->camera_x = 0;
    rc->ray_dir_x = 0;
    rc->ray_dir_y = 0;
    rc->ray_map_coor_x = 0;
    rc->ray_map_coor_y = 0;
    rc->step_x = 0;
    rc->step_y = 0;
    rc->side = 0;
    rc->side_dist_x = 0;
    rc->side_dist_y = 0;
    rc->delta_dist_x = 0;
    rc->delta_dist_y = 0;
    rc->perp_wall_dist = 0;
}

void ft_init_vars(t_data *d)
{
    d->img.mlx = mlx_init();
    if (!d->img.mlx)
        ft_exit(d, "Failed to init MLX\n", 1);
    d->img.mlx_win = mlx_new_window(d->img.mlx, W, H, "cub3d - dbekic");
    if (!d->img.mlx_win)
        ft_exit(d, "Failed to create window\n", 1);
    ft_init_img(&d->img, d->img.mlx);
    ft_init_img(&d->back_img_buffer, d->img.mlx);
    ft_init_img(&d->front_img_buffer, d->img.mlx);
    ft_init_textures(d);
    ft_init_rc(&d->rc);
    ft_init_keys(&d->keys);

    d->map.start_line = 0;
}