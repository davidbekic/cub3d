/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:23:39 by dbekic            #+#    #+#             */
/*   Updated: 2023/05/19 18:04:53 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

extern int worldMap[24][24];

int ft_key_down(int keycode, t_data *d)
{
    ft_key_down_check(keycode, d);
    if (keycode == 53)
        exit(0);
    if (d->keys.up)
        ft_move_forward(d);
    if (d->keys.down)
        ft_move_backward(d);
    if (d->keys.right)
        ft_move_right(d);
    if (d->keys.left)
        ft_move_left(d);
    if (d->keys.rotate_right)
        ft_rotate_right(d);
    if (d->keys.rotate_left)
        ft_rotate_left(d);
    return (0);
}