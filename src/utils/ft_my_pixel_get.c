/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_pixel_get.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:25:36 by davidbekic        #+#    #+#             */
/*   Updated: 2023/05/20 16:26:08 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int ft_my_pixel_get(t_img *img, int x, int y) {
  int color;
  char *dst;

  dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
  color = *(unsigned int *)dst;
  return (color);
}