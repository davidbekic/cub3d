/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:39:21 by dbekic            #+#    #+#             */
/*   Updated: 2023/06/12 13:02:06 by dbekic           ###   ########.fr       */
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


void ft_move_forward(t_data *d)
{
	if (d->map.arr[(int)(d->rc.pos_x + d->rc.dir_x * MOVE_SPEED)]
				[(int)(d->rc.pos_y)] == '0')
		// if (!is_x_forwards_wall(d))
		d->rc.pos_x += d->rc.dir_x * MOVE_SPEED;
	if (d->map.arr[(int)(d->rc.pos_x)]
				[(int)(d->rc.pos_y + d->rc.dir_y * MOVE_SPEED)] == '0')
		// if (!is_y_forwards_wall(d))
		d->rc.pos_y += d->rc.dir_y * MOVE_SPEED;
}

void ft_move_backward(t_data *d)
{
    if (d->map.arr[(int)(d->rc.pos_x - d->rc.dir_x * MOVE_SPEED)][(int)(d->rc.pos_y)] == '0')
        d->rc.pos_x -= d->rc.dir_x * MOVE_SPEED;
    if (d->map.arr[(int)(d->rc.pos_x)][(int)(d->rc.pos_y - d->rc.dir_y * MOVE_SPEED)] == '0')
        d->rc.pos_y -= d->rc.dir_y * MOVE_SPEED;
}

void ft_move_right(t_data *d)
{
    if (d->map.arr[(int)(d->rc.pos_x - d->rc.dir_x * MOVE_SPEED)][(int)(d->rc.pos_y)] == '0')
        d->rc.pos_x -= d->rc.dir_y * MOVE_SPEED;
    if (d->map.arr[(int)(d->rc.pos_x)][(int)(d->rc.pos_y - d->rc.dir_y * MOVE_SPEED)] == '0')
        d->rc.pos_y -= d->rc.dir_x * MOVE_SPEED;
}

void ft_move_left(t_data *d)
{
    if (d->map.arr[(int)(d->rc.pos_x - d->rc.dir_x * MOVE_SPEED)][(int)(d->rc.pos_y)] == '0')
        d->rc.pos_x += d->rc.dir_y * MOVE_SPEED;
    if (d->map.arr[(int)(d->rc.pos_x)][(int)(d->rc.pos_y - d->rc.dir_y * MOVE_SPEED)] == '0')
        d->rc.pos_y += d->rc.dir_x * MOVE_SPEED;
}
