/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:46:59 by hasabir           #+#    #+#             */
/*   Updated: 2022/06/18 13:02:39 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

/*
	Bresenham algorithm:
	
	 
*/



// typedef struct	s_data {
// 	// void	*img;
// 	// char	*addr;
// 	// int		bits_per_pixel;
// 	// int		line_length;
// 	// int		endian;
// 	int x;
// 	int y;
// 	void	*mlx;
// 	void	*mlx_win;
// }				t_data;

// // void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// // {
// // 	char	*dst;

// // 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// // 	*(unsigned int*)dst = color;
// // }
// int fun(int key, t_data *img)
// {
// 	if (key == 53)
// 		mlx_destroy_window(img->mlx, img->mlx_win);
// 	printf("key = %d\n", key);
// 	return (0);
// }

// int mouse_hook(int button, int x, int y, t_data *img)
// {	
// 	img->x = x;
// 	img->y =y;
// 	if (button == 1)
// 			mlx_pixel_put(img->mlx, img->mlx_win, x, y, 0xFF0000);
// 	return 0;
// }

// int line(int x1, int x2, int y1, int y2, t_data *img)
// {
// 	int x = x1;
// 	int y = y1;
// 	int dx;
// 	int dy;
// 	int p;

// 	dx = x2 - x1;
// 	dy = y2 - y1;
// 	p = 2 * dy - dx;
// 	while (x <= x2)
// 	{
// 		mlx_pixel_put(img->mlx, img->mlx_win, x, y, 0xFF0000);
// 		if(p < 0)
// 			p = p +2 * dy;
// 		else
// 		{
// 			p = p + 2 * dy - 2 * dx;
// 			y++;
// 		}
// 		x++;
// 	}
// 	return 0;
// }

// int function(t_data *img)
// {
// 	mlx_mouse_hook(img->mlx_win, mouse_hook, img);
// 	int x1 = img->x;
// 	int y1 = img->y;
// 	// while (x1 < 500 && y1 < 500)
// 	// {
// 	// 	mlx_pixel_put(img->mlx, img->mlx_win, x1, y1, 0xFF0000);
// 	// 	x1++;
// 	// 	y1++;
// 	// }
// 	// mlx_mouse_hook(img->mlx_win, mouse_hook, img);
// 	int x2 = 900;
// 	int y2 = 800;
// 	line(x1, x2, y1, y2, img);
// 	return 0;
// }

// // int main()
// // {
	
// // 	t_data	*img;

// // 	img = malloc(sizeof(t_data));
// // 	img->mlx = mlx_init();
// // 	img->mlx_win = mlx_new_window(img->mlx, 1000, 1000, "Fdf");
// // 	// mlx_hook(img->mlx_win, 2, 0, fun, img);
// // 	// mlx_mouse_hook(img->mlx_win, mouse_hook, img);
// // 	mlx_loop_hook(img->mlx, function, img);
// // 	mlx_loop(img->mlx);
// // }

