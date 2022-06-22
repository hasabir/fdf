/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:01:59 by hasabir           #+#    #+#             */
/*   Updated: 2022/06/21 10:52:00 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int draw_line(int x1, int y1, int x2, int y2, t_data *data)
{
	int e = abs(x2 -x1);
	int dx = 2* e;
	int dy = 2 *abs(y2 - y1);
	
	if (x1 < x2 && y1 < y2)
	{
		while (x1 <= x2)
		{
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, x1, y1, RED);
			x1++;
			e -= dy;
			if (e < 0)
			{
				y1++;
				e+= dx;
			}
		}
		
	}
	else if (x1 > x2 && y1 < y2)
	{
		while (x1 >= x2)
		{
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, x1, y1, RED);
			x1--;
			e -= dy;
			if (e < 0)
			{
				y1++;
				e+= dx;
			}
		}
	}
	else if (x1 > x2 && y1 > y2)
	{
		while (x1 >= x2)
		{
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, x1, y1, RED);
			x1--;
			e -= dy;
			if (e < 0)
			{
				y1--;
				e+= dx;
			}
		}
	}
	else if(x1 < x2 && y1 > y2)
	{
		while (x1 <= x2)
		{
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, x1, y1, RED);
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

int	draw_line_low(int x1, int y1, int x2, int y2, t_data *data)
{
	int dx;
	int dy;
	int x ;
	int yi;
	int y;
	int p;
	
	yi = 1;
	dx = x2 - x1;
	dy = y2 - y1;
	p = 2 * dy - dx;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	y = y1;
	x = x1;
	while (x <= x2)
	{
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, x, y, RED);
		if (p > 0)
		{
			y += yi;
			p = p + (2 *(dy - dx));
		}
		else
			p = p+ 2 * dy;
	}
	return(0);
}

int	draw_line_high(int x1, int y1, int x2, int y2, t_data *data)
{
	int dx;
	int dy;
	int x ;
	int xi;
	int y;
	int p;
	
	xi = 1;
	dx = x2 - x1;
	dy = y2 - y1;
	p = 2 * dx - dy;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	y = y1;
	x = x1;
	while (y <= y2)
	{
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, x, y, RED);
		if (p > 0)
		{
			x += xi;
			p = p + (2 *(dx - dy));
		}
		else
			p = p + 2 * dx;
	}
	return(0);
}

typedef struct s_data_line
{
	// int x1;
	// int y1;
	// int x2;
	// int y2;
	int ex;
	int ey;
	int dx;
	int dy;
} t_data_line;

void intialline(t_data_line *data_line)
{
	data_line->ex = abs(x2 - x1);
	data_line->ey = abs(y2 - y1);
	data_line->dx = 2 * ex;
	data_line->dy = 2 * ey;
	
}