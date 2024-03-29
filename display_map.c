/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:21:07 by hasabir           #+#    #+#             */
/*   Updated: 2022/07/07 10:16:35 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->img_height)
	{
		x = 0;
		while (x < data->map->img_width)
		{
			my_mlx_pixel_put(data, x, y, 0x000000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
	return ;
}

void	display(t_data *data, int x, int y, int i)
{
	if (x < data->map->size_x + data->mv_x - 1)
	{
		data->coordinate->x1 = x * data->map->zoom;
		data->coordinate->y1 = y * data->map->zoom;
		data->coordinate->x2 = (x + 1) * data->map->zoom;
		data->coordinate->y2 = y * data->map->zoom;
		data->coordinate->z1 = data->map->matrix[y][i];
		data->coordinate->z2 = data->map->matrix[y][i + 1];
		line_draw(data);
	}
	if (y < data->map->size_y - 1)
	{
		data->coordinate->x1 = x * data->map->zoom;
		data->coordinate->y1 = y * data->map->zoom;
		data->coordinate->x2 = x * data->map->zoom;
		data->coordinate->y2 = (y + 1) * data->map->zoom;
		data->coordinate->z1 = data->map->matrix[y][i];
		data->coordinate->z2 = data->map->matrix[y + 1][i];
		line_draw(data);
	}
	return ;
}

int	display_map(t_data *data)
{
	int	x;
	int	y;
	int	i;

	draw_background(data);
	data->coordinate = malloc(sizeof(t_data_coordinate));
	y = 0;
	while (y < data->map->size_y)
	{
		x = data->mv_x;
		i = 0;
		while (x < data->map->size_x + data->mv_x)
		{			
			data->color = data->map->color[y][i];
			display(data, x, y, i);
			x++;
			i++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img, data->x, data->y);
	return (0);
}
