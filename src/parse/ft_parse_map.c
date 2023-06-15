/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:25:30 by davidbekic        #+#    #+#             */
/*   Updated: 2023/06/15 16:00:25 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void ft_parse_player_pos(t_data *d)
{
    int i;
    int j;
    int pos_char_found;

    i = 0;
    j = 0;
    pos_char_found = 0;
    while (d->map.arr[i] != NULL)
    {
        while (d->map.arr[i][j] != 0)
        {
            if (d->map.arr[i][j] == 'N' || d->map.arr[i][j] == 'S' || d->map.arr[i][j] == 'E' || d->map.arr[i][j] == 'W')
            {
                if (pos_char_found)
                    ft_exit(d, "Multiple player positions found", 1);
                ft_init_pos(d, i, j, d->map.arr[i][j]);
                pos_char_found = 1;
                d->map.arr[i][j] = '0';
            }
            j++;
        }
        i++;
        j = 0;
    }
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

void ft_fill_spaces_with_points(t_data *d)
{
    int i;
    int j;

    i = 0;
    j = 0;

    printf("map height = %d\n", d->map.height);
    printf("map width = %d\n", d->map.width);

    while (d->map.arr[i] != NULL)
    {
        while (j < d->map.width)
        {
            if (d->map.arr[i][j] == ' ' || (d->map.arr[i][j] == 0 && j != d->map.width - 1) || d->map.arr[i][j] == 10)
                d->map.arr[i][j] = '.';
            j++;
        }
        i++;
        j = 0;
    }
}

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
        if (d->map.arr[i][strlen(d->map.arr[i]) - 1] != '1' && d->map.arr[i][strlen(d->map.arr[i]) - 1] != '.' && d->map.arr[i][strlen(d->map.arr[i]) - 1] != 10)
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
                count++;
            j++;
        }
        i++;
        j = 0;
    }
    printf("count = %d\n", count);
    if (count != 1)
        ft_exit(d, "Map has no player", 1);
}



void ft_parse_map(t_data *d, int fd)
{
    char *line;
    int i;

    i = 0;

    printf("d->map.height = %d\n", d->map.height);
    printf("d->map.width = %d\n", d->map.width);
    line = get_next_line(fd);
    while (line)
    {
        // d->map.arr[++i] = ft_strdup(line);
        d->map.arr[++i] = (char *) ft_calloc(sizeof(char) * (d->map.width + 1), 1);
        if (!d->map.arr[i])
            ft_exit(d, "Malloc error", 1);
        strcpy(d->map.arr[i], line);
        free(line);
        line = get_next_line(fd);
    }
    printf("dying here\n");
    d->map.arr[++i] = NULL;
    ft_check_if_map_has_player_pos_and_dir(d);
    ft_parse_player_pos(d);

    ft_check_allowed_chars(d);
    ft_fill_spaces_with_points(d);
    ft_check_if_surrounded_by_walls(d);
    ft_check_if_first_and_last_line_is_one_or_point(d);
    ft_check_if_first_and_last_columns_is_one_or_point(d);
}