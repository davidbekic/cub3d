/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:39:21 by dbekic            #+#    #+#             */
/*   Updated: 2023/05/19 15:45:01 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

extern int worldMap[24][24];

void ft_move_forward(t_data *d)
{
    if (worldMap[(int)(d->rc.pos_x + d->rc.dir_x * MOVE_SPEED)][(int)(d->rc.pos_y)] == 0)
        d->rc.pos_x += d->rc.dir_x * MOVE_SPEED;
    if (worldMap[(int)(d->rc.pos_x)][(int)(d->rc.pos_y + d->rc.dir_y * MOVE_SPEED)] == 0)
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
