/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:00:51 by davidbekic        #+#    #+#             */
/*   Updated: 2023/06/21 13:17:19 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

static void	ft_init_wall_props(t_data *d)
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

static int	ft_get_wall_direction(int side, double ray_dir_x, double ray_dir_y)
{
	if (side == 0 && ray_dir_x >= 0)
		return (0);
	else if (side == 0 && ray_dir_x <= 0)
		return (1);
	else if (side == 1 && ray_dir_y >= 0)
		return (2);
	else
		return (3);
}

static void	ft_map_texture(t_data *d, int x)
{
	t_i_love_norminette	var;

	var.y = d->rc.draw_start - 1;
	var.dir = ft_get_wall_direction(d->rc.side,
			d->rc.ray_dir_x, d->rc.ray_dir_y);
	var.tex_x = (int)(d->rc.wall_x * (double)d->tex[var.dir].width);
	if ((d->rc.side == 0 && d->rc.ray_dir_x > 0)
		|| (d->rc.side == 1 && d->rc.ray_dir_y < 0))
		var.tex_x = d->tex[var.dir].width - var.tex_x - 1;
	var.step = (1.0 * d->tex[var.dir].height / d->rc.wall_height);
	var.tex_pos = (d->rc.draw_start - H / 2 + d->rc.wall_height / 2) * var.step;
	while (++var.y < d->rc.draw_end)
	{
		var.tex_y = (int)var.tex_pos & (d->tex[var.dir].height - 1);
		var.tex_pos += var.step;
		var.color = d->tex[var.dir].arr[var.tex_x][var.tex_y];
		if (d->rc.side == 1)
			var.color = (var.color >> 1) & 8355711;
		ft_my_mlx_pixel_put(&d->img, x, var.y, var.color);
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
		if (d->rc.side == 0)
			d->rc.perp_wall_dist = (d->rc.ray_map_coor_x - d->rc.pos_x
					+ (1 - d->rc.step_x) / 2) / d->rc.ray_dir_x;
		else
			d->rc.perp_wall_dist = (d->rc.ray_map_coor_y - d->rc.pos_y
					+ (1 - d->rc.step_y) / 2) / d->rc.ray_dir_y;
		ft_init_wall_props(d);
		ft_map_texture(d, x);
	}
}
