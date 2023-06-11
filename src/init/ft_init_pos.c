/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:39:06 by davidbekic        #+#    #+#             */
/*   Updated: 2023/06/11 14:46:37 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void ft_init_pos(t_data *d, int i, int j, char pos)
{
    d->rc.pos_x = i;
    d->rc.pos_y = j;
    if (pos == 'N')
    {
        d->rc.dir_x = 0;
        d->rc.dir_y = 1;
    }
    if (pos == 'E')
    {
        d->rc.dir_x = 1;
        d->rc.dir_y = 0;
    }
    if (pos == 'S')
    {
        d->rc.dir_x = 0;
        d->rc.dir_y = -1;
    }
    if (pos == 'W')
    {
        d->rc.dir_x = -1;
        d->rc.dir_y = 0;
    }
}