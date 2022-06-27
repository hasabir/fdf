/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:52:35 by hasabir           #+#    #+#             */
/*   Updated: 2022/06/27 19:39:42 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void towD_to_iso(int *x, int *y)
{
	int isox;
	int isoy;

	isox = *x * cos(0.6) - *y * sin(0.6)+ 30;
	isoy = *x * sin(0.6) + *y * cos(0.6)+ 30;
	*x = isox;
	*y = isoy;
	return;
}

void creat_coordinate(t_data_coordinate	*coordinate, t_data *data)
{
	data->zoom = 20;// zoom function	
	coordinate->x1 *= data->zoom;
	coordinate->x2 *= data->zoom;
	coordinate->y1 *= data->zoom;
	coordinate->y2 *= data->zoom;
	towD_to_iso(&coordinate->x1, &coordinate->y1);
	towD_to_iso(&coordinate->x2, &coordinate->y2);
	coordinate->ex = abs(coordinate->x2 - coordinate->x1);
	coordinate->ey = abs(coordinate->y2 - coordinate->y1);
	coordinate->dx = 2 * coordinate->ex;
	coordinate->dy = 2 * coordinate->ey;
	coordinate->px = coordinate->ex;
	coordinate->py = coordinate->ey;
}

void first_case(t_data_coordinate *coordinate, t_data *data, int xi, int yi)
{
	int i;

	i = 0;
	while (i <= coordinate->px)
	{
		my_mlx_pixel_put(data, coordinate->x1, coordinate->y1, GREEN);
		i++;
		coordinate->x1 += xi;
		coordinate->ex -= coordinate->dy;
		if (coordinate->ex <= 0)
		{
			coordinate->y1+= yi;
			coordinate->ex+= coordinate->dx;
		}
	}
	return ;	
}

void second_case(t_data_coordinate *coordinate, t_data *data, int xi, int yi)
{
	int	i;

	i = 0;
	while (i <= coordinate->py)
	{
		my_mlx_pixel_put(data, coordinate->x1, coordinate->y1, GREEN);
		i++;
		coordinate->y1+= yi;
		coordinate->ey -= coordinate->dx;
		if (coordinate->ey <= 0)
		{
			coordinate->x1+= xi;
			coordinate->ey+= coordinate->dy;
		}
	}
	return ;
}

void third_case(t_data_coordinate *coordinate, t_data *data, int xi, int yi)
{
	while (coordinate->x1 <= coordinate->x2 || coordinate->y1 <= coordinate->y2)
	{
		my_mlx_pixel_put(data, coordinate->x1, coordinate->y1, GREEN);
		coordinate->x1++;
		coordinate->y1++;
	}
}
int draw_line3(t_data_coordinate *coordinate, t_data *data, t_map *map)
{	
	int i = 0;
	int xi = 1;
	int yi = 1;
	
	creat_coordinate(coordinate, data);
	if (coordinate->x1 > coordinate->x2)
		xi = -1;
	if (coordinate->y1 > coordinate->y2)
		yi = -1;
	if (coordinate->px > coordinate->py)
		first_case(coordinate, data, xi, yi);
	else if (coordinate->px < coordinate->py)
		second_case(coordinate, data, xi, yi);
	else if (coordinate->px == coordinate->py)
		third_case(coordinate, data, xi, yi);
	return 0;
}
