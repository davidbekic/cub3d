#include "../../include/cub3d.h"

void ft_init_vars(t_data *d)
{
    d->img.mlx = mlx_init();
    d->img.mlx_win = mlx_new_window(d->img.mlx, W, H, "cub3d - dbekic");
    ft_init_img(&d->img, d->img.mlx);
    ft_init_img(&d->back_img_buffer, d->img.mlx);
    ft_init_img(&d->front_img_buffer, d->img.mlx);
    ft_init_textures(d);
    // d->tex[0].img.img =
    //     mlx_xpm_file_to_image(d->img.mlx, "./textures/test/east.xpm",
    //                           &d->tex[0].width, &d->tex[0].height);
    // d->tex[0].img.addr = mlx_get_data_addr(d->tex[0].img.img,
    // &d->tex[0].img.bits_per_pixel, &d->tex[0].img.line_length,
    //                               &d->tex[0].img.endian);
    // d->tex[0].arr = ft_fill_texture(d->tex[0]);
    // free(d->tex[0].img.addr);
    // for (int x = 0; x < 64; x++)
    // {
    //     for (int y = 0; y < 64; y++)
    //     {
    //         printf("%d ", d->tex[0].arr[x][y]);
    //     }
    //     printf("\n");
    // }

    // ACCESS PIXELS OF TEXTURE int pixel_color = *(int *)(tex.addr +
    // tex.line_length + (tex.bits_per_pixel / 8));

    // mlx_put_image_to_window(d->img.mlx, d->img.mlx_win, tex, 0, 0);

    // d->img.img = mlx_new_image(d->img.mlx, W, H);
    // d->img.addr = mlx_get_data_addr(d->img.img, &d->img.bits_per_pixel,
    // &d->img.line_length,
    //                                 &d->img.endian);
    // mlx_put_image_to_window(d->img.mlx, d->img.mlx_win, d->img.img, 0,
    // 0);
    printf("tex_width: %d\n", d->tex->width);
    printf("tex_height: %d\n", d->tex->height);
    d->rc.wall_height = 0;
    d->rc.draw_start = 0;
    d->rc.draw_end = 0;
    d->rc.wall_x = 0;
    d->rc.dir_x = -1;
    d->rc.dir_y = 0;
    d->rc.pos_x = 4;
    d->rc.pos_y = 4;
    d->rc.camera_plane_x = 0;
    d->rc.camera_plane_y = .71;
    d->rc.hit = 0;
    d->rc.camera_x = 0;
    d->rc.ray_dir_x = 0;
    d->rc.ray_dir_y = 0;
    d->rc.ray_map_coor_x = 0;
    d->rc.ray_map_coor_y = 0;
    d->rc.step_x = 0;
    d->rc.step_y = 0;
    d->rc.side = 0;
    d->keys.up = 0;
    d->keys.down = 0;
    d->keys.left = 0;
    d->keys.right = 0;
    d->keys.rotate_left = 0;
    d->keys.rotate_right = 0;
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
