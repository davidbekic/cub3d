/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:00:51 by davidbekic        #+#    #+#             */
/*   Updated: 2023/06/20 10:06:07 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_init_rc_vars(t_data *d, int x)
{
	d->rc.camera_x = 2 * x / (double)W - 1;
	d->rc.ray_dir_x = d->rc.dir_x + d->rc.camera_plane_x * d->rc.camera_x;
	d->rc.ray_dir_y = d->rc.dir_y + d->rc.camera_plane_y * d->rc.camera_x;
	d->rc.ray_map_coor_x = (int)d->rc.pos_x;
	d->rc.ray_map_coor_y = (int)d->rc.pos_y;
	d->rc.hit = 0;
	d->rc.delta_dist_x = (d->rc.ray_dir_x == 0) ? 1e30 : fabs(1 / d->rc.ray_dir_x);
	d->rc.delta_dist_y = (d->rc.ray_dir_y == 0) ? 1e30 : fabs(1 / d->rc.ray_dir_y);
	if (d->rc.ray_dir_x < 0)
	{
		d->rc.step_x = -1;
		d->rc.side_dist_x = (d->rc.pos_x - d->rc.ray_map_coor_x) * d->rc.delta_dist_x;
	}
	else
	{
		d->rc.step_x = 1;
		d->rc.side_dist_x = (d->rc.ray_map_coor_x + 1.0 - d->rc.pos_x) * d->rc.delta_dist_x;
	}
	if (d->rc.ray_dir_y < 0)
	{
		d->rc.step_y = -1;
		d->rc.side_dist_y = (d->rc.pos_y - d->rc.ray_map_coor_y) * d->rc.delta_dist_y;
	}
	else
	{
		d->rc.step_y = 1;
		d->rc.side_dist_y = (d->rc.ray_map_coor_y + 1.0 - d->rc.pos_y) * d->rc.delta_dist_y;
	}
}

static void	ft_dda(t_data *d)
{
	while (d->rc.hit == 0)
	{
		if (d->rc.side_dist_x < d->rc.side_dist_y)
		{
			d->rc.side_dist_x += d->rc.delta_dist_x;
			d->rc.ray_map_coor_x += d->rc.step_x;
			d->rc.side = 0;
		}
		else
		{
			d->rc.side_dist_y += d->rc.delta_dist_y;
			d->rc.ray_map_coor_y += d->rc.step_y;
			d->rc.side = 1;
		}
		if (d->map.arr[d->rc.ray_map_coor_x][d->rc.ray_map_coor_y] > '0')
			d->rc.hit = 1;
	}
}

double	ft_set_perp_wall_dist(t_data *d)
{
	if (d->rc.side == 0)
		return ((d->rc.ray_map_coor_x - d->rc.pos_x + (1 - d->rc.step_x) / 2) / d->rc.ray_dir_x);
	else
		return ((d->rc.ray_map_coor_y - d->rc.pos_y + (1 - d->rc.step_y) / 2) / d->rc.ray_dir_y);
}

void	ft_init_wall_props(t_data *d)
{
	d->rc.wall_height = (int)(H / d->rc.perp_wall_dist);
	d->rc.draw_start = -d->rc.wall_height / 2 + (H * 1) / 2;
	if (d->rc.draw_start < 0)
		d->rc.draw_start = 0;
	d->rc.draw_end = d->rc.wall_height / 2 + (H * 1) / 2;
	if (d->rc.draw_end >= (H * 1))
		d->rc.draw_end = (H * 1) - 1;
	if (d->rc.side == 0)
		d->rc.wall_x = d->rc.pos_y + d->rc.perp_wall_dist * d->rc.ray_dir_y;
	else
		d->rc.wall_x = d->rc.pos_x + d->rc.perp_wall_dist * d->rc.ray_dir_x;
	d->rc.wall_x -= floor((d->rc.wall_x));
}

int	ft_get_wall_direction(int side, double ray_dir_x, double ray_dir_y) {
	if (side == 0 && ray_dir_x >= 0)
		return (0);
	else if (side == 0 && ray_dir_x <= 0)
		return (1);
	else if (side == 1 && ray_dir_y >= 0)
		return (2);
	else
		return (3);
}

void	ft_map_texture(t_data *d, int x)
{
	int	dir;
	double	step;
	double	texPos;
	int	texY;
	int	texX;
	int	color;

	dir = ft_get_wall_direction(d->rc.side, d->rc.ray_dir_x, d->rc.ray_dir_y);
	texX = (int)(d->rc.wall_x * (double)d->tex[dir].width);
	if ((d->rc.side == 0 && d->rc.ray_dir_x > 0) ||
		(d->rc.side == 1 && d->rc.ray_dir_y < 0))
		texX = d->tex[dir].width - texX - 1;

	step = (1.0 * d->tex[dir].height / d->rc.wall_height);
	texPos = (d->rc.draw_start - H / 2 + d->rc.wall_height / 2) * step;
	for (int y = d->rc.draw_start; y < d->rc.draw_end; y++)
	{
		texY = (int)texPos & (d->tex[dir].height - 1);
		texPos += step;
		color = d->tex[dir].arr[texX][texY];
		if (d->rc.side == 1)
			color = (color >> 1) & 8355711;
		ft_my_mlx_pixel_put(&d->img, x, y, color);
	}
}

void	ft_cast_rays(t_data *d)
{
	int	x;

	x = -1;
	while (++x < W)
	{
		ft_init_rc_vars(d, x);
		ft_dda(d);
		d->rc.perp_wall_dist = ft_set_perp_wall_dist(d);
		ft_init_wall_props(d);
		ft_map_texture(d, x);
	}
}
