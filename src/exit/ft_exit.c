/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:23:25 by davidbekic        #+#    #+#             */
/*   Updated: 2023/06/20 10:09:20 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_exit(t_data *d, char *message, int flag)
{
	if (flag == 1)
		printf("Error\n%s\n", message);
	else
		printf("%s\n", message);
	exit(flag);
	printf("print something of d struct: %d\n", d->keys.up);
}
