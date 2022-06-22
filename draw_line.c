/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:52:35 by hasabir           #+#    #+#             */
/*   Updated: 2022/06/22 12:39:54 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int dda(int x1, int y1, int x2, int y2 , t_data *data)
// {
	
// }

int draw_line(int x1, int y1, int x2, int y2, t_data *data, t_map *map)
{
	x1 *= data->zoom;
	x2 *= data->zoom;
	y2 *= data->zoom;
	y1 *= data->zoom;
	
	int e = abs(x2 -x1);
	int dx = 2 * e;
	int dy = 2 *abs(y2 - y1);
	
	
	if (x1 <= x2 && y1 <= y2)
	{
		while (x1 <= x2 && y1 <= y2)
		{
			my_mlx_pixel_put(data, x1, y1, RED);
			x1++;
			e -= dy;
			if (e < 0)
			{
				y1++;
				e+= dx;
			}
		}
		
	}
	else if (x1 >= x2 && y1 <= y2)
	{
		while (x1 >= x2 || y1 <= y2)
		{
			my_mlx_pixel_put(data, x1, y1, BLUE);
			x1--;
			e -= dy;
			if (e < 0)
			{
				y1++;
				e+= dx;
			}
		}
	}
	else if (x1 >= x2 && y1 >= y2)
	{
		while (x1 >= x2 || y1 >= y2)
		{
			my_mlx_pixel_put(data, x1, y1, RED);
			x1--;
			e -= dy;
			if (e < 0)
			{
				y1--;
				e+= dx;
			}
		}
	}
	else if(x1 <= x2 && y1 >= y2)
	{
		while (x1 <= x2 || y1 >= y2)
		{
			my_mlx_pixel_put(data, x1, y1, GREEN);
			x1++;
			e -= dy;
			if (e < 0)
			{
				y1--;
				e+= dx;
			}
		}
	}
	return(0);
}

int towD_to_iso(int *x, int *y)
{
	int isox;
	int isoy;

	isox = *x * cos(0.8) - *y * cos(0.8);
	isoy = *x * sin(0.8) + *y * sin(0.8);
	*x = isox;
	*y = isoy;
	return (0);
}

int draw_line2(int x1, int y1, int x2, int y2, t_data *data, t_map *map)
{	
	x1 *= data->zoom;
	x2 *= data->zoom;
	y2 *= data->zoom;
	y1 *= data->zoom;
	
	towD_to_iso(&x1, &y1);
	towD_to_iso(&x2, &y2);
	int ex = abs(x2 - x1);
	int ey = abs(y2 - y1);
	int dx = 2 * ex;
	int dy = 2 * ey;
	int i = 0;
	int xi = 1;
	int yi = 1;
	int px = ex;
	int py = ey;

	if (x1 > x2)
		xi = -1;
	if (y1 > y2)
		yi = -1;
	if (px > py)
	{
		while (i <= px)
		{
			my_mlx_pixel_put(data, x1, y1, GREEN);
			i++;
			x1 += xi;
			ex -= ey;
			if (ex <= 0)
			{
				y1+= yi;
				ex+= dx;
			}
		}	
	}
	else if (px <= py)
	{
		while (i <= py)
		{
			my_mlx_pixel_put(data, x1, y1, map->color);
			i++;
			y1+= yi;
			ey -= ex;
			if (ey <= 0)
			{
				x1+= xi;
				ey+= dy;
			}
		}
		
	}
	// else if(px == py)
	// {
	// 	while (x1 < x2)
	// 	{
	// 		my_mlx_pixel_put(data, x1, y1, BLUE);
	// 		x1++;
	// 	}
	// }
	return 0;
}