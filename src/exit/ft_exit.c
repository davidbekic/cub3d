/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:23:25 by davidbekic        #+#    #+#             */
/*   Updated: 2023/05/20 17:26:22 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void ft_exit(t_data *d) {
  free(d->tex[0].arr);
  free(d->tex[1].arr);
  free(d->tex[2].arr);
  free(d->tex[3].arr);
  exit(0);
}