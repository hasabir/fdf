/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:21:07 by hasabir           #+#    #+#             */
/*   Updated: 2022/06/22 12:42:35 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int towD_to_iso(int *x, int *y)
// {
// 	int isox;
// 	int isoy;

// 	isox = *x * (3 / 4) - *y * (3 / 4);
// 	isoy = *x * (3 / 4) - *y * (3 / 4);
// 	return (0);
// }

int	display_map(t_data *data, t_map *map)
{
	int i;
	int j;
	int x;
	int y;
	int isox = 0;
	int isoy = 0;
// WINDOW_HEIGHT / 100 WINDOW_HEIGHT / 100
	y = 0;
	while (y < map->size_y)
	{
		x = 0;
		while (x < map->size_x)
		{
			if  (x < map->size_x - 1)
				{
				// isox = x * (3 / 4) - y * (3 / 4);
				// isoy = x * (3 / 4) + y * (3 / 4);
				// towD_to_iso(&x, &y);
					draw_line(x, y, x + 1, y, data, map);
				}
			if (y < map->size_y - 1)
				{
					// x = x * (3 / 4) - y * (3 / 4);
					// isoy = x * (3 / 4) - y * (3 / 4);
					// towD_to_iso(&x, &y);
					draw_line(x, y, x, y + 1, data ,map);
				}
			x++;
		}
		y++;
	}
	return(0);
}