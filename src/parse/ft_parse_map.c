/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:25:30 by davidbekic        #+#    #+#             */
/*   Updated: 2023/06/14 16:44:37 by dbekic           ###   ########.fr       */
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
    while (i < d->map.height)
    {
        while (d->map.arr[i][j] != 0)
        {
            if (d->map.arr[i][j] == 'N' || d->map.arr[i][j] == 'S' || d->map.arr[i][j] == 'E' || d->map.arr[i][j] == 'W')
            {
                if (pos_char_found)
                    ft_exit(d);
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
    while (i < d->map.height)
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
                    printf("invalid char\n");
                    ft_exit(d);
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
    while (i < d->map.height)
    {
        printf("line = %s\n", d->map.arr[i]);
        while (d->map.arr[i][j] != 0)
        {
            if (d->map.arr[i][j] == '0')
            {
                //print map values
                printf("d->map.arr[%d][%d] = %c\n", i, j, d->map.arr[i][j]);
                
                if (d->map.arr[i][j - 1] == '.' || d->map.arr[i][j + 1] == '.' || d->map.arr[i - 1][j] == '.' || d->map.arr[i + 1][j] == '.' || d->map.arr[i][j + 1] == 10)
                {
                    printf("map not surrounded by walls\n");
                    ft_exit(d);
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

    while (i < d->map.height)
    {
        while (j < d->map.width - 1)
        {
            printf("d->map.arr[%d][%d] = %c\n", i, j, d->map.arr[i][j]);
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
        {
            printf("first line not 1 or point\n");
            ft_exit(d);
        }
        i++;
    }
    i = 0;
    while (d->map.arr[d->map.height - 1][i] != 0)
    {
        if (d->map.arr[d->map.height - 1][i] != '1' && d->map.arr[d->map.height - 1][i] != '.' && d->map.arr[d->map.height - 1][i] != 10 )
        {
            printf("last line not 1 or point\n");
            ft_exit(d);
        }
        i++;
    }
}

void ft_check_if_first_and_last_columns_is_one_or_point(t_data *d)
{
    int i;

    i = 0;
    while (i < d->map.height)
    {
        if (d->map.arr[i][0] != '1' && d->map.arr[i][0] != '.' && d->map.arr[i][0] != 10)
        {
            printf("first column not 1 or point\n");
            ft_exit(d);
        }
        i++;
    }
    i = 0;
    while (i < d->map.height)
    {
        if (d->map.arr[i][strlen(d->map.arr[i]) - 1] != '1' && d->map.arr[i][strlen(d->map.arr[i]) - 1] != '.' && d->map.arr[i][strlen(d->map.arr[i]) - 1] != 10)
        {
            printf("map not surrounded by walls\n");
            ft_exit(d);
        }
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
    while (i < d->map.height)
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
    {
        printf("map has no player\n");
        ft_exit(d);
    }
}

// void ft_fill_zeros_that_are_not_null_termination_with_points(t_data *d)
// {
//     int i;
//     int j;

//     i = 0;
//     j = 0;
//     while (i < d->map.height)
//     {
//         while (d->map.arr[i][j] != 0)
//         {
//             if (d->map.arr[i][j] == 0 && j != d->map.width - 1)
//                 d->map.arr[i][j] = '.';
//             j++;
//         }
//         i++;
//         j = 0;
//     }
// }

void ft_parse_map(t_data *d, int fd)
{
    char *line;
    int i;

    i = 0;
    printf("d->map.height = %d\n", d->map.height);
    line = get_next_line(fd);
    while (line)
    {
        // d->map.arr[++i] = ft_strdup(line);
        d->map.arr[++i] = (char *) calloc(sizeof(char) * (d->map.width + 1), 1);
        strcpy(d->map.arr[i], line);
        free(line);
        line = get_next_line(fd);
    }
    d->map.arr[++i] = NULL;
    ft_check_if_map_has_player_pos_and_dir(d);
    ft_parse_player_pos(d);
    ft_check_allowed_chars(d);
    ft_fill_spaces_with_points(d);
    // ft_fill_zeros_that_are_not_null_termination_with_points(d);
    ft_check_if_surrounded_by_walls(d);
    ft_check_if_first_and_last_line_is_one_or_point(d);
    ft_check_if_first_and_last_columns_is_one_or_point(d);
}