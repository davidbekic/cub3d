#include "../include/cub3d.h"

int worldMap[2400][2400] =
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1}};

static int ft_exit_bruh(t_data *d)
{
  ft_exit(d, "Exited successfully\n", 0);
  exit (0);
}




int main(int ac, char **av)
{
    // char map[MAX_ROWS][MAX_COLS];
    // int numRows, numCols;
    t_data d;



    if (ac != 2)
    {
        write(2, "wrong num of args\n", 18);
        exit(1);
        return (1);
    }

    ft_parse_cub(&d, av[1]);
    // ft_gpt_parser(av[1], map, &numRows, &numCols);

    ft_init_vars(&d);


    mlx_loop_hook(d.img.mlx, ft_render_frame, &d);
    mlx_hook(d.img.mlx_win, 17, 1L << 17, ft_exit_bruh, &d);
    mlx_hook(d.img.mlx_win, KEY_PRESS, 1L << 0, ft_key_down_check, &d);
    mlx_hook(d.img.mlx_win, KEY_RELEASE, 1L << 1, ft_key_up_check, &d);
    mlx_loop(d.img.mlx);
}