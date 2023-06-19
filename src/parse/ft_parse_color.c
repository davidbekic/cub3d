/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:46:29 by dbekic            #+#    #+#             */
/*   Updated: 2023/06/19 10:51:27 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void ft_parse_color(char* line, t_color *color)
{
    int i = 0;

    while (line[i] == 32)
        i++;
    color->r = 0;
    while (line[i] != ',') {
        color->r = (color->r * 10) + (line[i] - '0');
        i++;
    }
    if (color->r > 255 || color->r < 0)
        printf("bad color but ok\n");
    i++;
    color->g = 0;
    while (line[i] != ',') {
        color->g = (color->g * 10) + (line[i] - '0');
        i++;
    }
    i++;
    color->b = 0;
    while (ft_is_digit(line[i])) {
        color->b = (color->b * 10) + (line[i] - '0');
        i++;
    }
}