/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:17:18 by hasabir           #+#    #+#             */
/*   Updated: 2022/06/21 17:25:14 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int key_hook(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		data->mlx_win = NULL;
	}
	printf("key = %d\n", key);
	return (0);
}

int mouse_hook(int button, int x, int y, t_data *data)
{	
	data->x = x;
	data->y =y;
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("---------\n");
	// if (button == 1)
	// 		mlx_pixel_put(data->mlx_ptr,i
	// 					data->mlx_win, x, y, RED);
	// if (button == 4)
	// 		data->zoom +=10;
	// if (button == 1)
	// 		my_mlx_pixel_put(data, x, y, RED);
	return 0;
}