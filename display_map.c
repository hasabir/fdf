/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:21:07 by hasabir           #+#    #+#             */
/*   Updated: 2022/06/27 19:53:44 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	display_map(t_data *data, t_map *map)
{
	t_data_coordinate *coordinate;
	int x; //add x and y to coordinate
	int y;
	int i;
	
	coordinate = malloc(sizeof(t_data_coordinate ));
	y = 0;
	while (y < map->size_y)
	{
		x = 10;
		i = 0;
		while (x < map->size_x + 10)
		{
			
					// data->color = map->color[y][i];
					// printf("data->color = %d\n",data->color);
			if  (x < map->size_x + 10 - 1)
				{
					coordinate->x1 = x;
					coordinate->y1 = y;
					coordinate->x2 = x + 1;
					coordinate->y2 = y;
					draw_line3(coordinate, data, map);
				}
			if (y < map->size_y + 0 - 1)
				{
					coordinate->x1 = x;
					coordinate->y1 = y;
					coordinate->x2 = x;
					coordinate->y2 = y + 1;
					// data->color = map->color[y][x];
					draw_line3(coordinate, data ,map);
				}
			x++;
			i++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
	return(0);
}
