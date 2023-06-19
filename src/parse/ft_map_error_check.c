/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_error_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:36:57 by davidbekic        #+#    #+#             */
/*   Updated: 2023/06/19 22:49:24 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


void ft_check_if_first_and_last_line_is_one_or_point(t_data *d)
{
    int i;

    i = 0;
    while (d->map.arr[0][i] != 0)
    {
        if (d->map.arr[0][i] != '1' && d->map.arr[0][i] != '.' && d->map.arr[0][i] != 10)
            ft_exit(d, "Map is not surrounded by walls", 1);
        i++;
    }
    i = 0;
    while (d->map.arr[d->map.height - 1][i] != 0)
    {
        if (d->map.arr[d->map.height - 1][i] != '1' && d->map.arr[d->map.height - 1][i] != '.' && d->map.arr[d->map.height - 1][i] != 10 )
            ft_exit(d, "Map is not surrounded by walls", 1);
        i++;
    }
}

void ft_check_if_first_and_last_columns_is_one_or_point(t_data *d)
{
    int i;

    i = 0;
    while (d->map.arr[i] != NULL)
    {
        if (d->map.arr[i][0] != '1' && d->map.arr[i][0] != '.' && d->map.arr[i][0] != 10)
            ft_exit(d, "Map is not surrounded by walls", 1);
        i++;
    }
    i = 0;
    while (d->map.arr[i] != NULL)
    {
        if (d->map.arr[i][ft_strlen(d->map.arr[i]) - 1] != '1' && d->map.arr[i][ft_strlen(d->map.arr[i]) - 1] != '.' && d->map.arr[i][ft_strlen(d->map.arr[i]) - 1] != 10)
            ft_exit(d, "Map is not surrounded by walls", 1);
        i++;
    }
}

void ft_check_if_map_has_player_pos_and_dir(t_data *d)
{
    int i;
    int j;
    int count;

    i = 0;
    j = 0;
    count = 0;
    while (d->map.arr[i] != NULL)
    {
        while (d->map.arr[i][j] != 0)
        {
            if (d->map.arr[i][j] == 'N' || d->map.arr[i][j] == 'S' || d->map.arr[i][j] == 'E' || d->map.arr[i][j] == 'W')
            {
                if (i == 0 || i == d->map.height - 1 || j == 0 || (size_t) j ==  ft_strlen(d->map.arr[i]) - 1)
                    ft_exit(d, "Player position is not valid", 1);
                count++;
            }
            j++;
        }
        i++;
        j = 0;
    }
    if (count != 1)
        ft_exit(d, "Map has no player", 1);
}


void ft_check_allowed_chars(t_data *d)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (d->map.arr[i] != NULL)
    {
        while (d->map.arr[i][j] != 0)
        {
            // printf("d->map.arr[%d][%d] = %c\n", i, j, d->map.arr[i][j]);
            if (d->map.arr[i][j] != '1'
                && d->map.arr[i][j] != '0'
                && d->map.arr[i][j] != 'N'
                && d->map.arr[i][j] != 'S'
                && d->map.arr[i][j] != 'E'
                && d->map.arr[i][j] != 'W'
                && d->map.arr[i][j] != 10
                && d->map.arr[i][j] != ' ')
                {
                    ft_exit(d, "Invalid character in map", 1);
                }
            j++;
        }
        i++;
        j = 0;
    }
}

void ft_check_if_surrounded_by_walls(t_data *d)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (d->map.arr[i] != NULL)
    {
        while (d->map.arr[i][j] != 0)
        {
            if (d->map.arr[i][j] == '0')
            {
                //print map values
                
                if (d->map.arr[i][j - 1] == '.' || d->map.arr[i][j + 1] == '.' || d->map.arr[i - 1][j] == '.' || d->map.arr[i + 1][j] == '.' || d->map.arr[i][j + 1] == 10)
                {
                    ft_exit(d, "Map is not surrounded by walls", 1);
                }
            }
            j++;
        }
        i++;
        j = 0;
    }
}
