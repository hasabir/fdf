/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:53:35 by hasabir           #+#    #+#             */
/*   Updated: 2022/06/22 12:40:41 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	loop_hook(t_data *data, t_map *map)
{
		// mlx_pixel_put(data->mlx_ptr, data->mlx_win, 
		// 		WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, RED);
		// mlx_mouse_hook(data->mlx_win, mouse_hook, data);
		// int x2 = data->x;
		// int y2 = data->y;
		// // my_mlx_pixel_put(data, 400, 400, GREEN);
		// draw_line(500,500,x2, y2,data);
		// // draw_line(500,900,256, 900,data);
		// // draw_line(500,900,256, 900,data);
		// // draw_line(500,900,256, 900,data);
		// mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
	return (0);
}

int main(int ac, char **av)
{
	int 	fd;
	t_data	*data;
	t_map	*map;
	
	if (ac == 1)
		return (1);
	map = creat_map(av[1]);
	putmap(map);
	data = malloc(sizeof(t_data));
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return(1);
	data->mlx_win = mlx_new_window(data->mlx_ptr,
 						1000, 1000, "Fdf");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_win);
		printf("error\n");
	}
	data->img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
									&data->line_length, &data->endian);
	mlx_hook(data->mlx_win, 2, 0, key_hook, data);
	data->zoom = 40;
	mlx_mouse_hook(data->mlx_win, mouse_hook, data);
	display_map(data, map);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
	mlx_loop(data->mlx_ptr);
	return(0);	
}
	// mlx_loop_hook(data->mlx_ptr, loop_hook, data);    
	// mlx_destroy_display(data->mlx_ptr);

