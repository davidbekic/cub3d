/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:23:25 by davidbekic        #+#    #+#             */
/*   Updated: 2023/06/21 12:35:36 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void    ft_exit(t_data *d, char *message, int flag)
{

    if (flag == 1)
    {
        write(2, "Error\n", 6);
        write(2, message, ft_strlen(message));
        write(2, "\n", 1);
    }
    else
    {
        write(2, message, ft_strlen(message));
        write(1, "\n", 1);
    }
    exit(flag);
    printf("print something of d struct: %d\n", d->keys.up);
}


