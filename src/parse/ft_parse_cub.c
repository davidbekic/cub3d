/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:27:47 by davidbekic        #+#    #+#             */
/*   Updated: 2023/06/12 12:56:29 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <ctype.h>


int ft_is_configurated(t_data *d)
{
    // check if all textures and floor and ceiling colors exist
    if (!d->tex[NORTH_TEX_INDEX].path)
        return (0);
    else if (!d->tex[SOUTH_TEX_INDEX].path)
        return (0);
    else if (!d->tex[EAST_TEX_INDEX].path)
        return (0);
    else if (!d->tex[WEST_TEX_INDEX].path)
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
    // printf("d->map.height = %d\n", d->map.height);
    n = 0;

    while (buf != NULL) {
        buf = get_next_line(fd);
        if (!buf)
            break;
        if ((buf[0] == '1' || (buf[0] == ' ')) && ((ft_is_configurated(d))))
            start_count = 1;
        if (start_count)
            n++;
        free(buf);
    }
    close(fd);
    return (n);
}

void ft_parse_tex_path(t_data *d, char *line, int index)
{
    int i;

    i = 0;
    while (line[i] == 32)
        i++;
    printf("entering\n");
    d->tex[index].path = strdup(line + i);
    if (!d->tex[index].path)
        ft_exit(d);
    d->tex[index].path[strlen(line) - 1 - i] = 0;
    printf("strlen of path: %lu\n", strlen(line));
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
    if ((line[0] == '1' || (line[0] == ' ')) && ((ft_is_configurated(d))))
    {
        d->map.height = ft_get_map_height(d, path);
        d->map.arr = malloc(sizeof(char *) * d->map.height + 1);
        d->map.arr[0] = strdup(line);
        printf("dying here\n");
        ft_parse_map(d, fd);
    }

}

int ft_parse_cub(t_data *d, char *path) {
    char *line;
    int fd;

    d->floor.r = -1;
    d->ceiling.r = -1;
    fd = open(path, O_RDONLY);
    printf("fd in orase cub: %d\n", fd);
    printf("d->map.height = %d\n", d->map.height);
    if (fd == -1) {
        printf("file didnt open\n");
        return (1);
    }
    line = get_next_line(fd);
    while (line) {
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