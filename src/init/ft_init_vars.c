/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:42:01 by dbekic            #+#    #+#             */
/*   Updated: 2023/06/23 08:56:10 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_init_step_and_side_dist(t_data *d)
{
	if (d->rc.ray_dir_x < 0)
	{
		d->rc.step_x = -1;
		d->rc.side_dist_x = (d->rc.pos_x - d->rc.ray_map_coor_x)
			* d->rc.delta_dist_x;
	}
	else
	{
		d->rc.step_x = 1;
		d->rc.side_dist_x = (d->rc.ray_map_coor_x + 1.0 - d->rc.pos_x)
			* d->rc.delta_dist_x;
	}
	if (d->rc.ray_dir_y < 0)
	{
		d->rc.step_y = -1;
		d->rc.side_dist_y = (d->rc.pos_y - d->rc.ray_map_coor_y)
			* d->rc.delta_dist_y;
	}
	else
	{
		d->rc.step_y = 1;
		d->rc.side_dist_y = (d->rc.ray_map_coor_y + 1.0 - d->rc.pos_y)
			* d->rc.delta_dist_y;
	}
}

void	ft_init_rc_vars(t_data *d, int x)
{
	d->rc.camera_x = 2 * x / (double)W - 1;
	d->rc.ray_dir_x = d->rc.dir_x + d->rc.camera_plane_x * d->rc.camera_x;
	d->rc.ray_dir_y = d->rc.dir_y + d->rc.camera_plane_y * d->rc.camera_x;
	d->rc.ray_map_coor_x = (int)d->rc.pos_x;
	d->rc.ray_map_coor_y = (int)d->rc.pos_y;
	d->rc.hit = 0;
	if (d->rc.ray_dir_x == 0)
		d->rc.delta_dist_x = 1e30;
	else
		d->rc.delta_dist_x = fabs(1 / d->rc.ray_dir_x);
	if (d->rc.ray_dir_y == 0)
		d->rc.delta_dist_y = 1e30;
	else
		d->rc.delta_dist_y = fabs(1 / d->rc.ray_dir_y);
	ft_init_step_and_side_dist(d);
}

static void	ft_init_keys(t_keys *keys)
{
	keys->up = 0;
	keys->down = 0;
	keys->left = 0;
	keys->right = 0;
	keys->rotate_left = 0;
	keys->rotate_right = 0;
	keys->exit_key = 0;
}

static void	ft_init_rc(t_rc_data *rc)
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

void	ft_init_vars(t_data *d)
{
	d->img.mlx = mlx_init();
	if (!d->img.mlx)
		ft_exit("Failed to init MLX\n", 1);
	d->img.mlx_win = mlx_new_window(d->img.mlx, W, H,
			"cub3d - dbekic & irifarac");
	if (!d->img.mlx_win)
		ft_exit("Failed to create window\n", 1);
	ft_init_img(&d->img, d->img.mlx);
	ft_init_textures(d);
	ft_init_rc(&d->rc);
	ft_init_keys(&d->keys);
}
