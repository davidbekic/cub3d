/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_trgb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:44:00 by davidbekic        #+#    #+#             */
/*   Updated: 2023/06/20 14:03:37 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

unsigned char	ft_get_t(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

unsigned char	ft_get_r(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

unsigned char	ft_get_g(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

unsigned char	ft_get_b(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}
