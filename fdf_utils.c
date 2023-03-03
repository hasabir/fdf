/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 13:30:00 by hasabir           #+#    #+#             */
/*   Updated: 2022/07/06 18:40:24 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_zoom(t_map *map)
{
	if (map->size_x < 50 && map->size_y < 50)
		map->zoom = 15;
	else if (map->size_x >= 50 && map->size_x
		< 100 && map->size_y < 100 && map->size_y >= 50)
		map->zoom = 10;
	else if ((map->size_x >= 100 && map->size_x < 250)
		&& (map->size_y < 250 && map->size_y >= 100))
		map->zoom = 5;
	else
		map->zoom = 1;
	return (0);
}

void	towd_to_iso(int *x, int *y, int z, int i)
{
	int	isox;
	int	isoy;

	if (i == 2)
	{
		isox = *x * cos(0.8) - *y * sin(0.8);
		isoy = *x * sin(0.8) + *y * cos(0.8) - z;
	}
	else if (i == 0)
	{
		isox = *x - *y;
		isoy = (*x + *y) / 2 - z;
	}
	*x = isox;
	*y = isoy;
	return ;
}

int	set_colors(t_map *map, int coordinate, char *arg, int n)
{
	if (n == 0)
	{
		if (coordinate == 0)
			return (16777215);
		else
			return (65280);
	}
	return (ft_atoi_base(arg, "0123456789ABCDEF"));
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
		ft_perror ();
	ft_bzero (p, count * size);
	return (p);
}
