/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 00:01:39 by davidbekic        #+#    #+#             */
/*   Updated: 2023/05/21 00:04:29 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int     ft_key_down_check(int keycode, t_data *d)
{
    if (keycode == W_KEY)
        d->keys.up = 1;
    if (keycode == S_KEY)
        d->keys.down = 1;
    if (keycode == A_KEY)
        d->keys.left = 1;
    if (keycode == D_KEY)
        d->keys.right = 1;
    if (keycode == LEFT_KEY)
        d->keys.rotate_left = 1;
    if (keycode == RIGHT_KEY)
        d->keys.rotate_right = 1;
    if (keycode == EXIT_KEY)
        d->keys.exit_key = 1;
    return (0);
}

int     ft_key_up_check(int keycode, t_data *d)
{
    if (keycode == W_KEY)
        d->keys.up = 0;
    if (keycode == S_KEY)
        d->keys.down = 0;
    if (keycode == A_KEY)
        d->keys.left = 0;
    if (keycode == D_KEY)
        d->keys.right = 0;
    if (keycode == LEFT_KEY)
        d->keys.rotate_left = 0;
    if (keycode == RIGHT_KEY)
        d->keys.rotate_right = 0;
    if (keycode == EXIT_KEY)
        d->keys.exit_key = 0;
    return (0);
}