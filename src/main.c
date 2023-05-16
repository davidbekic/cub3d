#include "../include/cub3d.h"



int main(void)
{
    t_data d;
    
    mlx_key_hook(d.img.mlx_win, ft_key_down, &d.img);
    mlx_loop_hook(d.img.mlx, ft_render_frame, &d);
    mlx_loop(d.img.mlx);

}