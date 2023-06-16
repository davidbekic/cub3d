/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:27:47 by davidbekic        #+#    #+#             */
/*   Updated: 2023/06/16 14:16:45 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <ctype.h>


void ft_remove_isspace_from_end_of_str(char *str)
{
    int i;
    
    i = strlen(str) - 1;
    printf("str[i]: %d\n", str[i]);
    while (str[i] == 32 || str[i] == 10)
    {
        printf("iterating\n");
        str[i] = 0;
        i--;
    }
}

int ft_is_configurated(t_data *d)
{
    if (!d->tex[NORTH_TEX_INDEX].ready)
        return (0);
    else if (!d->tex[SOUTH_TEX_INDEX].ready)
        return (0);
    else if (!d->tex[EAST_TEX_INDEX].ready)
        return (0);
    else if (!d->tex[WEST_TEX_INDEX].ready)
        return (0);
    else if (d->ceiling.r < 0)
        return (0);
    else if (d->floor.r < 0)
        return (0);
    else 
        return (1);
}

int ft_get_map_height(t_data *d, char *path) {
    int n;
    int fd;
    char *buf = "ha";
    int start_count;

    start_count = 0;

    fd = open(path, O_RDONLY);
    printf("fd in get map height: %d\n", fd);

    if (fd == -1) {
        printf("file didnt open\n");
        return (1);
    }
    n = 0;

    printf("d->map.width = %d\n", d->map.width);
    while (buf != NULL) {
        n++;
        buf = get_next_line(fd);
        if (!buf)
            break;
        if (n == d->map.start_line)
        {
            start_count = 1;
        }
        if (start_count)
        {
            if (d->map.width < (int)strlen(buf))
                d->map.width = (int)strlen(buf);
        }
        free(buf);
    }
    close(fd);
    printf("n = %d\n", n);
    return (n - d->map.start_line);
}

void ft_parse_tex_path(t_data *d, char *line, int index)
{
    int i;

    i = 0;
    while (line[i] == 32)
        i++;
    ft_remove_isspace_from_end_of_str(line + i);
    d->tex[index].path = ft_strdup(line + i);
    d->tex[index].path[strlen(line) - i] = 0;
    if (!d->tex[index].path)
        ft_exit(d, "Malloc failed\n", 1);
    printf("line[strlen]: %c\n", line[ft_strlen(line) - 1]); 
    d->tex[index].ready = 1;
}   

void ft_parse_color(char* line, t_color *color)
{
    int i = 0;  // Start at i 2 to skip the 'F' and the space

    while (line[i] == 32)
        i++;
    color->r = 0;
    while (line[i] != ',') {
        color->r = (color->r * 10) + (line[i] - '0');
        i++;
    }
    i++;  // Skip the comma
    color->g = 0;
    while (line[i] != ',') {
        color->g = (color->g * 10) + (line[i] - '0');
        i++;
    }
    i++;  // Skip the comma
    color->b = 0;
    while (ft_is_digit(line[i])) {
        color->b = (color->b * 10) + (line[i] - '0');
        i++;
    }
    printf("color.r: %d\n", color->r);
    printf("color->g: %d\n", color->g);
    printf("color->b: %d\n", color->b);
}



void ft_parse_line(t_data *d, char *line, char *path, int fd)
{
    while (*line == ' ' && !ft_is_configurated(d))
    {
        line++;
    }
    if (!strncmp(line, "NO ", 3))
        ft_parse_tex_path(d, line + 3, NORTH_TEX_INDEX);
    else if (!strncmp(line, "SO ", 3))
        ft_parse_tex_path(d, line + 3, SOUTH_TEX_INDEX);
    else if (!strncmp(line, "WE ", 3))
        ft_parse_tex_path(d, line + 3, WEST_TEX_INDEX);
    else if (!strncmp(line, "EA ", 3))
        ft_parse_tex_path(d, line + 3, EAST_TEX_INDEX);
    else if (!strncmp(line, "F ", 2))
        ft_parse_color(line + 2, &d->floor);
    else if (!strncmp(line, "C ", 2))
        ft_parse_color(line + 2, &d->ceiling);
    else if ((line[0] == '1' || (line[0] == ' ')) && ((ft_is_configurated(d))))
    {
        d->map.width = 0;
        d->map.height = ft_get_map_height(d, path);
        d->map.arr = malloc(sizeof(char *) * d->map.height + 1);
        if (!d->map.arr)
            ft_exit(d, "malloc error", 1);
        d->map.arr[0] = (char *) ft_calloc(d->map.width + 1, sizeof(char));
        if (!d->map.arr[0])
            ft_exit(d, "malloc error", 1);
        strcpy(d->map.arr[0], line);
        ft_parse_map(d, fd);
    }

}

static void ft_check_extension(char *str)
{
    int i;

    ft_remove_isspace_from_end_of_str(str);
    i = 0;
    str[strlen(str)] = 0;
    while (str[i] != 0)
        i++;
    if (!(str[i - 1] == 'b' && str[i - 2] == 'u' && str[i - 3] == 'c' && str[i - 4] == '.'))
        ft_exit(NULL, "Wrong file extension", 1);
}

int ft_parse_cub(t_data *d, char *path) {
    char *line;
    int fd;

    d->floor.r = -1;
    d->ceiling.r = -1;
    d->map.start_line = 0;
            d->tex[0].ready = 0;
    d->tex[1].ready = 0;
    d->tex[2].ready = 0;
    d->tex[3].ready = 0;
    ft_check_extension(path);
    fd = open(path, O_RDONLY);
    if (fd == -1)
        ft_exit(d, "File reading error", 1);
    line = get_next_line(fd);
    while (line) {
        d->map.start_line++;
        ft_parse_line(d, line, path, fd);
        free(line);
        line = get_next_line(fd);
    }

    // print d->map.arr
    int i = 0;
    while (i < d->map.height) {
        printf("d->map.arr[%d]: %s\n", i, d->map.arr[i]);
        i++;
    }
    return (0);
}