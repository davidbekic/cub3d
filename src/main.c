/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:34:27 by dbekic            #+#    #+#             */
/*   Updated: 2023/06/23 09:41:21 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_exit_bruh(void)
{
	ft_exit("Exited successfully", 0);
	exit (0);
}

int	main(int ac, char **av)
{
	t_data	d;

	if (ac != 2)
	{
		write(2, "wrong num of args\n", 18);
		return (1);
	}
	ft_parse_cub(&d, av[1]);
	ft_init_vars(&d);
	d.map.width = 0;
	mlx_loop_hook(d.img.mlx, ft_render_frame, &d);
	mlx_hook(d.img.mlx_win, 17, 1L << 17, ft_exit_bruh, &d);
	mlx_hook(d.img.mlx_win, KEY_PRESS, 1L << 0, ft_key_down_check, &d);
	mlx_hook(d.img.mlx_win, KEY_RELEASE, 1L << 1, ft_key_up_check, &d);
	mlx_loop(d.img.mlx);
}
