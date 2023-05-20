/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_pixel_put.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:18:09 by davidbekic        #+#    #+#             */
/*   Updated: 2023/05/20 17:48:53 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void ft_my_mlx_pixel_put(t_img *img, int x, int y, int color) {
  char *dst;

  dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
  *(unsigned int *)dst = color;
}