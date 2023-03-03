/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:52:35 by hasabir           #+#    #+#             */
/*   Updated: 2022/07/06 14:59:31 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	creat_coordinate(t_data *data)
{
	data->coordinate->z1 *= data->z_axis;
	data->coordinate->z2 *= data->z_axis;
	if (data->map->i != 1)
	{
		towd_to_iso(&data->coordinate->x1, &data->coordinate->y1,
			data->coordinate->z1, data->map->i);
		towd_to_iso(&data->coordinate->x2, &data->coordinate->y2,
			data->coordinate->z2, data->map->i);
	}
	data->coordinate->ex = abs(data->coordinate->x2 - data->coordinate->x1);
	data->coordinate->ey = abs(data->coordinate->y2 - data->coordinate->y1);
	data->coordinate->dx = 2 * data->coordinate->ex;
	data->coordinate->dy = 2 * data->coordinate->ey;
	data->coordinate->px = data->coordinate->ex;
	data->coordinate->py = data->coordinate->ey;
	return ;
}

void	first_case(t_data *data, int xi, int yi)
{
	int	i;

	i = 0;
	while (i <= data->coordinate->px)
	{
		my_mlx_pixel_put(data, data->coordinate->x1,
			data->coordinate->y1, data->color);
		i++;
		data->coordinate->x1 += xi;
		data->coordinate->ex -= data->coordinate->dy;
		if (data->coordinate->ex <= 0)
		{
			data->coordinate->y1 += yi;
			data->coordinate->ex += data->coordinate->dx;
		}
	}
	return ;
}

void	second_case(t_data *data, int xi, int yi)
{
	int	i;

	i = 0;
	while (i <= data->coordinate->py)
	{
		my_mlx_pixel_put(data, data->coordinate->x1,
			data->coordinate->y1, data->color);
		i++;
		data->coordinate->y1 += yi;
		data->coordinate->ey -= data->coordinate->dx;
		if (data->coordinate->ey <= 0)
		{
			data->coordinate->x1 += xi;
			data->coordinate->ey += data->coordinate->dy;
		}
	}
	return ;
}

void	third_case(t_data *data, int xi, int yi)
{
	while (data->coordinate->x1 <= data->coordinate->x2
		|| data->coordinate->y1 <= data->coordinate->y2)
	{
		my_mlx_pixel_put(data, data->coordinate->x1, data->coordinate->y1,
			data->color);
		data->coordinate->x1++;
		data->coordinate->y1--;
	}
	return ;
}

int	line_draw(t_data *data)
{	
	int	i;
	int	xi;
	int	yi;

	i = 0;
	xi = 1;
	yi = 1;
	creat_coordinate(data);
	if (data->coordinate->x1 > data->coordinate->x2)
		xi = -1;
	if (data->coordinate->y1 > data->coordinate->y2)
		yi = -1;
	if (data->coordinate->px > data->coordinate->py)
		first_case(data, xi, yi);
	else if (data->coordinate->px <= data->coordinate->py)
		second_case(data, xi, yi);
	return (0);
}
