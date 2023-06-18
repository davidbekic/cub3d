/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:39:21 by dbekic            #+#    #+#             */
/*   Updated: 2023/06/18 17:21:03 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void ft_slow_down(double *speed)
{
	*speed /= 1.5;
}

void ft_move_forward(t_data *d)
{
	double move_speed = MOVE_SPEED;

	if ((d->keys.up && d->keys.right) || (d->keys.up && d->keys.left))	
		ft_slow_down(&move_speed);
	if (d->map.arr[(int)(d->rc.pos_x + d->rc.dir_x * move_speed)]
				[(int)(d->rc.pos_y)] == '0')
			d->rc.pos_x += d->rc.dir_x * move_speed;
	if (d->map.arr[(int)(d->rc.pos_x)]
				[(int)(d->rc.pos_y + d->rc.dir_y * move_speed)] == '0')
			d->rc.pos_y += d->rc.dir_y * move_speed;
}

void ft_move_backward(t_data *d)
{
	double move_speed = MOVE_SPEED;

	if ((d->keys.down && d->keys.right) || (d->keys.down && d->keys.left))	
		ft_slow_down(&move_speed);
    if (d->map.arr[(int)(d->rc.pos_x - d->rc.dir_x * move_speed)][(int)(d->rc.pos_y)] == '0')
        d->rc.pos_x -= d->rc.dir_x * move_speed;
    if (d->map.arr[(int)(d->rc.pos_x)][(int)(d->rc.pos_y - d->rc.dir_y * move_speed)] == '0') 
        d->rc.pos_y -= d->rc.dir_y * move_speed;
}

void ft_move_right(t_data *d)
{
	double move_speed = MOVE_SPEED;
	double new_pos_x = d->rc.pos_x + d->rc.dir_y * move_speed * 0.7;
    double new_pos_y = d->rc.pos_y - d->rc.dir_x * move_speed * 0.7;

	if ((d->keys.up && d->keys.right) || (d->keys.up && d->keys.left))	
		ft_slow_down(&move_speed);
	if (d->map.arr[(int)new_pos_x][(int)(d->rc.pos_y - WALL_DISTANCE)] == '0' 
			|| d->map.arr[(int)new_pos_x][(int)(d->rc.pos_y + WALL_DISTANCE)] == '0')
		d->rc.pos_x = new_pos_x;

	if  (d->map.arr[(int)(d->rc.pos_x - WALL_DISTANCE)][(int)new_pos_y] == '0'
			|| d->map.arr[(int)(d->rc.pos_x + WALL_DISTANCE)][(int)new_pos_y] == '0')
    	d->rc.pos_y = new_pos_y;
}

void ft_move_left(t_data *d)
{
	double move_speed = MOVE_SPEED;
	double new_pos_x = d->rc.pos_x - d->rc.dir_y * move_speed * 0.7;
    double new_pos_y = d->rc.pos_y + d->rc.dir_x * move_speed * 0.7;

	if ((d->keys.up && d->keys.right) || (d->keys.up && d->keys.left))	
		ft_slow_down(&move_speed);
	if  (d->map.arr[(int)new_pos_x][(int)(d->rc.pos_y + WALL_DISTANCE)] == '0' 
			|| d->map.arr[(int)new_pos_x][(int)(d->rc.pos_y - WALL_DISTANCE)] == '0' )
		d->rc.pos_x = new_pos_x;
	if  (d->map.arr[(int)(d->rc.pos_x + WALL_DISTANCE)][(int)new_pos_y] == '0'
			|| d->map.arr[(int)(d->rc.pos_x - WALL_DISTANCE)][(int)new_pos_y] == '0')
    	d->rc.pos_y = new_pos_y;
}
