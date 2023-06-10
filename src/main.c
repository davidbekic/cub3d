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
  ft_exit(d);
  return (0);
}

bool hasValidBorder(char map[MAX_ROWS][MAX_COLS], int numRows, int numCols) {
    for (int col = 0; col < numCols; col++) {
        if (map[0][col] != '1' || map[numRows - 1][col] != '1') {
            return false;
        }
    }

    for (int row = 0; row < numRows; row++) {
        if (map[row][0] != '1' || map[row][numCols - 1] != '1') {
            return false;
        }
    }

    return true;
}

int main(int ac, char **av)
{
    // char map[MAX_ROWS][MAX_COLS];
    // int numRows, numCols;
    t_data d;

    if (ac != 2)
      return (1);

    ft_parse_cub(&d, av[1]);
    // ft_gpt_parser(av[1], map, &numRows, &numCols);

    ft_init_vars(&d);
    mlx_loop_hook(d.img.mlx, ft_render_frame, &d);
    mlx_hook(d.img.mlx_win, 17, 1L << 17, ft_exit_bruh, &d);
    mlx_hook(d.img.mlx_win, KEY_PRESS, 1L << 0, ft_key_down_check, &d);
    mlx_hook(d.img.mlx_win, KEY_RELEASE, 1L << 1, ft_key_up_check, &d);
    mlx_loop(d.img.mlx);
}