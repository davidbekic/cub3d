/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:23:25 by davidbekic        #+#    #+#             */
/*   Updated: 2023/06/11 14:37:25 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void ft_free_textures(t_data *d)
{
  // free the whole 2d tex arr grid
  int i;
  int j;

  i = 0;
  j = 0;
  while (i < 4)
  {
    while (j < d->tex[i].height)
    {
      free(d->tex[i].arr[j]);
      j++;
    }
    free(d->tex[i].arr);
    free(d->tex[i].path);
    i++;
    j = 0;
  }
}

void ft_exit(t_data *d) {
  ft_free_textures(d);
  exit(0);
}