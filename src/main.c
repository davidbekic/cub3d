#include "../include/cub3d.h"

int worldMap[2400][2400] =
    {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1}};

int main(void)
{
    t_data d;

    ft_init_vars(&d);
    // mlx_key_hook(d.img.mlx_win, ft_key_down, &d);
    mlx_loop_hook(d.img.mlx, ft_render_frame, &d);
    mlx_hook(d.img.mlx_win, KEY_PRESS, 1L << 0, ft_key_down, &d);
    mlx_hook(d.img.mlx_win, KEY_RELEASE, 1L << 1, ft_key_down, &d);
    mlx_loop(d.img.mlx);
}