/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:27:47 by davidbekic        #+#    #+#             */
/*   Updated: 2023/05/19 11:35:07 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int ft_parse_map(t_data *d, char *path) {
    int fd;
    char buf[1];
    int col_count = 0;
    d->map.width = 0;
    d->map.height = 0;

    // Open the file
    fd = open(path, O_RDONLY);
    if (fd == -1) {
        // Error handling...
    }

    // First pass: count rows and columns
    while (read(fd, buf, 1) > 0) {
        if (buf[0] == '\n') {
            d->map.height++;
            if (col_count > d->map.width) {
                d->map.width = col_count;
            }
            col_count = 0;
        } else {
            col_count++;
            printf("col_count: %d\n", col_count);
        }
    }
    if (col_count > 0) { // Last line doesn't end with a newline
        d->map.height++;
        if (col_count > d->map.width) {
            d->map.width = col_count;
        }
    }

    // Close and reopen the file for the second pass
    close(fd);
    fd = open(path, O_RDONLY);
    if (fd == -1) {
        // Error handling...
    }

    // Allocate the 2D array
    d->map.arr = malloc(d->map.height * sizeof(int *));
    for (int i = 0; i < d->map.height; i++) {
        d->map.arr[i] = malloc((d->map.width + 1) * sizeof(int)); // +1 for null terminator
    }

    printf("map.width: %d\n", d->map.width);
    printf("map.height: %d\n", d->map.height);

    // Second pass: read and store the data
    int row = 0, col = 0;
    while (read(fd, buf, 1) > 0) {
        if (buf[0] == '\n') {
            // d->map.arr[row][col] = '\0'; // null terminate the string
            row++;
            col = 0;
        } else {
            if (buf[0] == 'N')
            {
                d->map.arr[row][col] = 0;
                col++;
            }
            else if (buf[0] == 32)  
            {
                d->map.arr[row][col] = 1;
                col++;
            }

            else if (buf[0] != 10)
            {
                d->map.arr[row][col] = buf[0] - 48;
                col++;
            }

        }
    }
    if (col > 0) { // Last line doesn't end with a newline
        d->map.arr[row][col] = '\0'; // null terminate the string
    }

    // Close the file
    close(fd);

    // Print the 2D array to verify the result
    for (int i = 0; i < d->map.height; i++) {
        for (int j = 0; j < d->map.width; j++)
        {
            printf("%d ", d->map.arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}