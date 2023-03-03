/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:13:10 by hasabir           #+#    #+#             */
/*   Updated: 2022/07/07 10:33:13 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (y < 0 || y >= data->map->img_height
		|| x < 0 || x >= data->map->img_width)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return ;
}

int	mv_image(int key, t_data *data)
{
	if (key == 124 || key == 123 || key == 125
		|| key == 126 || key == 69 || key == 78
		|| key == 35 || key == 34 || key == 31)
	{
		if (key == 124)
			data->x += 20;
		else if (key == 123)
			data->x -= 20;
		else if (key == 125)
			data->y += 20;
		else if (key == 126)
			data->y -= 20;
		else if (key == 78)
			data->z_axis -= 1;
		else if (key == 69)
			data->z_axis += 1;
		else if (key == 35)
			data->map->i = 1;
		else if (key == 34)
			data->map->i = 0;
		else if (key == 31)
			data->map->i = 2;
		display_map(data);
	}
	return (0);
}

int	distroy_window_x(int key, t_data *data)
{
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_hook(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		data->mlx_win = NULL;
		exit (EXIT_SUCCESS);
	}
	mv_image(key, data);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{	
	static int	i;

	if (!i)
		i = 0;
	if (button == 2 || button == 1)
	{
		if (button == 2)
		{	
			if (i > 0 && i <= 5)
				data->map->zoom--;
			i--;
		}
		if (button == 1)
		{
			if (i >= 0 && i < 5)
				data->map->zoom++;
			i++;
		}
		display_map(data);
	}
	return (0);
}
