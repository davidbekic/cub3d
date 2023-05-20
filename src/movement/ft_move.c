/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:39:21 by dbekic            #+#    #+#             */
/*   Updated: 2023/05/20 19:48:49 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

extern int worldMap[24][24];

int	is_x_forwards_wall(t_data *data)
{
	int			y;
	int			x;


	if (data->rc.dir_x > 0)
		y = (int)((data->rc.pos_x + data->rc.dir_x * MOVE_SPEED) + WALL_DISTANCE);
	else
		y = (int)((data->rc.pos_x + data->rc.dir_x * MOVE_SPEED) - WALL_DISTANCE);
	x = (int)(data->rc.pos_y);
	if (data->rc.pos_y - (int)data->rc.pos_y == 0 && ((worldMap[y][x - 1] != 0
			&& 1 - (data->rc.pos_x - (int)data->rc.pos_x) < CORNER_DISTANCE)
		|| (worldMap[y][x - 1] != 0 && (data->rc.pos_x - (int)data->rc.pos_x)
		< CORNER_DISTANCE) || (worldMap[y][x + 1] != 0
		&& sqrt(pow((data->rc.pos_x - (int)data->rc.pos_x), 2)
		+ pow(1 - (data->rc.pos_y - (int)data->rc.pos_y), 2)) < CORNER_DISTANCE)))
		return (1);
	if (worldMap[y][x] == 0)
		return (0);
	return (1);
}

int	is_y_forwards_wall(t_data *data)
{
	int			y;
	int			x;

	if (data->rc.dir_y > 0)
		y = (int)(data->rc.pos_y + data->rc.dir_y * MOVE_SPEED + WALL_DISTANCE);
	else
		y = (int)(data->rc.pos_y + data->rc.dir_y * MOVE_SPEED - WALL_DISTANCE);
	x = (int)(data->rc.pos_x);
	if (data->rc.pos_x - (int)data->rc.pos_x == 0 && ((worldMap[x - 1][y] != '0'
			&& (1 - (data->rc.pos_y - (int)data->rc.pos_y) < CORNER_DISTANCE))
		|| (worldMap[x - 1][y] != '0' && (data->rc.pos_y - (int)data->rc.pos_y)
		< CORNER_DISTANCE) || (worldMap[x + 1][y] != '0'
		&& sqrt(pow(1 - (data->rc.pos_x - (int)data->rc.pos_x), 2)
		+ pow(1 - (data->rc.pos_y - (int)data->rc.pos_y), 2)) < CORNER_DISTANCE)))
		return (1);
	if (worldMap[x][y] == '0')
		return (0);
	return (1);
}


void ft_move_forward(t_data *d)
{
	if (worldMap[(int)(d->rc.pos_x + d->rc.dir_x * MOVE_SPEED)]
				[(int)(d->rc.pos_y)] == 0)
		// if (!is_x_forwards_wall(d))
		d->rc.pos_x += d->rc.dir_x * MOVE_SPEED;
	if (worldMap[(int)(d->rc.pos_x)]
				[(int)(d->rc.pos_y + d->rc.dir_y * MOVE_SPEED)] == 0)
		// if (!is_y_forwards_wall(d))
		d->rc.pos_y += d->rc.dir_y * MOVE_SPEED;
}

void ft_move_backward(t_data *d)
{
    if (worldMap[(int)(d->rc.pos_x - d->rc.dir_x * MOVE_SPEED)][(int)(d->rc.pos_y)] == 0)
        d->rc.pos_x -= d->rc.dir_x * MOVE_SPEED;
    if (worldMap[(int)(d->rc.pos_x)][(int)(d->rc.pos_y - d->rc.dir_y * MOVE_SPEED)] == 0)
        d->rc.pos_y -= d->rc.dir_y * MOVE_SPEED;
}

void ft_move_right(t_data *d)
{
    if (worldMap[(int)(d->rc.pos_x - d->rc.dir_x * MOVE_SPEED)][(int)(d->rc.pos_y)] == 0)
        d->rc.pos_x -= d->rc.dir_y * MOVE_SPEED;
    if (worldMap[(int)(d->rc.pos_x)][(int)(d->rc.pos_y - d->rc.dir_y * MOVE_SPEED)] == 0)
        d->rc.pos_y -= d->rc.dir_x * MOVE_SPEED;
}

void ft_move_left(t_data *d)
{
    if (worldMap[(int)(d->rc.pos_x - d->rc.dir_x * MOVE_SPEED)][(int)(d->rc.pos_y)] == 0)
        d->rc.pos_x += d->rc.dir_y * MOVE_SPEED;
    if (worldMap[(int)(d->rc.pos_x)][(int)(d->rc.pos_y - d->rc.dir_y * MOVE_SPEED)] == 0)
        d->rc.pos_y += d->rc.dir_x * MOVE_SPEED;
}
