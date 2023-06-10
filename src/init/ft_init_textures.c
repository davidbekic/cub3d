/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:23:54 by davidbekic        #+#    #+#             */
/*   Updated: 2023/06/10 19:05:39 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char *ft_choose_texture(t_data *d, int i) {
  printf("d->tex[%d].path: %s\n", i, d->tex[i].path);
  if (i == 0)
  {
    return (d->tex[0].path);
  }
  if (i == 1)
    return (d->tex[1].path);
  if (i == 2)
    return (d->tex[2].path);
  else
    return (d->tex[3].path);
}

void ft_init_textures(t_data *d) {
  int i;

  i = -1;
  while (++i < 4) {
    d->tex[i].img.img = mlx_xpm_file_to_image(
        d->img.mlx, ft_choose_texture(d, i), &d->tex[i].width, &d->tex[i].height);
    d->tex[i].img.addr =
        mlx_get_data_addr(d->tex[i].img.img, &d->tex[i].img.bits_per_pixel,
                          &d->tex[i].img.line_length, &d->tex[i].img.endian);
    d->tex[i].arr = ft_fill_texture(d->tex[i]);
    free(d->tex[i].img.addr);
  }
}

int **ft_fill_texture(t_tex tex) {
  int x;
  int y;
  int **arr;

  x = -1;
  y = -1;
  arr = malloc(tex.height * sizeof(int *));
  while (++y < tex.height) {
    arr[y] = malloc(tex.width * sizeof(int));
    while (++x < tex.width) {
      arr[y][x] = ft_my_pixel_get(&tex.img, y, x);
    }
    if (x == tex.width)
      x = 0;
  }
  return (arr);
}