/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:39:21 by dbekic            #+#    #+#             */
/*   Updated: 2023/06/18 13:28:50 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// extern int d->map.arr[24][24];

int	is_x_forwards_wall(t_data *d)
{
	int			y;
	int			x;

	
	if (d->rc.dir_x > 0)
		y = (int)((d->rc.pos_x + d->rc.dir_x * MOVE_SPEED) + WALL_DISTANCE);
	else
		y = (int)((d->rc.pos_x + d->rc.dir_x * MOVE_SPEED) - WALL_DISTANCE);
	x = (int)(d->rc.pos_y);
	if (d->rc.pos_y - (int)d->rc.pos_y == 0 && ((d->map.arr[y][x - 1] != '0'
			&& 1 - (d->rc.pos_x - (int)d->rc.pos_x) < CORNER_DISTANCE)
		|| (d->map.arr[y][x - 1] != '0' && (d->rc.pos_x - (int)d->rc.pos_x)
		< CORNER_DISTANCE) || (d->map.arr[y][x + 1] != '0'
		&& sqrt(pow((d->rc.pos_x - (int)d->rc.pos_x), 2)
		+ pow(1 - (d->rc.pos_y - (int)d->rc.pos_y), 2)) < CORNER_DISTANCE)))
		return (1);
	if (d->map.arr[y][x] == '0')
		return (0);
	return (1);
}

int	is_y_forwards_wall(t_data *d)
{
	int			y;
	int			x;

	if (d->rc.dir_y > 0)
		y = (int)(d->rc.pos_y + d->rc.dir_y * MOVE_SPEED + WALL_DISTANCE);
	else
		y = (int)(d->rc.pos_y + d->rc.dir_y * MOVE_SPEED - WALL_DISTANCE);
	x = (int)(d->rc.pos_x);
	if (d->rc.pos_x - (int)d->rc.pos_x == 0 && ((d->map.arr[x - 1][y] != '0'
			&& (1 - (d->rc.pos_y - (int)d->rc.pos_y) < CORNER_DISTANCE))
		|| (d->map.arr[x - 1][y] != '0' && (d->rc.pos_y - (int)d->rc.pos_y)
		< CORNER_DISTANCE) || (d->map.arr[x + 1][y] != '0'
		&& sqrt(pow(1 - (d->rc.pos_x - (int)d->rc.pos_x), 2)
		+ pow(1 - (d->rc.pos_y - (int)d->rc.pos_y), 2)) < CORNER_DISTANCE)))
		return (1);
	if (d->map.arr[x][y] == '0')
		return (0);
	return (1);
}



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
	{
		if (!is_x_forwards_wall(d))
			d->rc.pos_x += d->rc.dir_x * move_speed;
	}
	if (d->map.arr[(int)(d->rc.pos_x)]
				[(int)(d->rc.pos_y + d->rc.dir_y * move_speed)] == '0')
	{
		if (!is_y_forwards_wall(d))
			d->rc.pos_y += d->rc.dir_y * move_speed;
	}
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
    // if (d->map.arr[(int)(d->rc.pos_x - d->rc.dir_x * move_speed - WALL_DISTANCE)][(int)(d->rc.pos_y)] == '0'
	// 	&& d->map.arr[(int)(d->rc.pos_x - d->rc.dir_x * move_speed + WALL_DISTANCE)][(int)(d->rc.pos_y)] == '0')
	// 	d->rc.pos_x += d->rc.dir_y * move_speed * .7;
    // if (d->map.arr[(int)(d->rc.pos_x)][(int)(d->rc.pos_y - d->rc.dir_y * move_speed  - WALL_DISTANCE)] == '0'
	// 	&& d->map.arr[(int)(d->rc.pos_x)][(int)(d->rc.pos_y - d->rc.dir_y * move_speed  + WALL_DISTANCE)] == '0')
    //     d->rc.pos_y -= d->rc.dir_x * move_speed * .7;
	if (d->map.arr[(int)new_pos_x][(int)(d->rc.pos_y - WALL_DISTANCE)] == '0' 
			|| d->map.arr[(int)new_pos_x][(int)(d->rc.pos_y + WALL_DISTANCE)] == '0')
		d->rc.pos_x = new_pos_x;

	if  (d->map.arr[(int)(d->rc.pos_x - WALL_DISTANCE)][(int)new_pos_y] == '0'
			|| d->map.arr[(int)(d->rc.pos_x + WALL_DISTANCE)][(int)new_pos_y] == '0')
    	d->rc.pos_y = new_pos_y;

    // No collision detected, update the player's position
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
	{
		d->rc.pos_x = new_pos_x;
	}
	if  (d->map.arr[(int)(d->rc.pos_x + WALL_DISTANCE)][(int)new_pos_y] == '0'
			|| d->map.arr[(int)(d->rc.pos_x - WALL_DISTANCE)][(int)new_pos_y] == '0')
    {
    	d->rc.pos_y = new_pos_y;
    }

}
