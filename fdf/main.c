/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:53:35 by hasabir           #+#    #+#             */
/*   Updated: 2022/06/28 15:51:30 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int loop_hook(t_data *img, t_map *map)
// {
// 	mlx_mouse_hook(img->mlx_win, mouse_hook, img);
// 	int x1 = img->x;
// 	int y1 = img->y;
	
// 	int x2 = 900;
// 	int y2 = 800;
// 	draw_line(x1, y1, x2, y2, img,map);
// 	// dda_line_draw(100, 200, 500, 300, img, map);
// 	// dda_line_draw(x1, x2, y1, y2, img, map);
// 	// mlx_put_image_to_window(img->mlx_ptr, img->mlx_win, img->img, 0, 0);
	
// 	return 0;
// }
void putmap(t_map *map)
{
	int i;
	int j;

	printf("x = %d\n", map->size_x);
	printf("y = %d\n", map->size_y);
	i = 0;
	while (i < map->size_y)
	{
		j = 0;
		while (j < map->size_x )
		{
			printf("%d",map->matrix[i][j]);
			printf(" ");
			j++;
		}
		printf("\n");
		i++;
	}
}

// void	data_mlx(t_data *data, t_map *map)
// {
// 	data->mlx_win = mlx_new_window(data->mlx_ptr,
//  						1000, 1000, "Fdf");
// 	if (data->mlx_win == NULL)
// 	{
// 		free(data->mlx_win);
// 		printf("error\n");
// 	}
// 	data->img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
// 	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
// 									&data->line_length, &data->endian);
// 	mlx_hook(data->mlx_win, 2, 0, key_hook, data);

// 	// mlx_mouse_hook(data->mlx_win, mouse_hook, data);
// 	display_map(data, map);        
// 	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
// 	return ;
// }

int main(int ac, char **av)
{
	int 	fd;
	t_data	*data;
	t_map	*map;
	
	if (ac != 2 || ft_strnstr(av[1], ".fdf", ft_strlen(av[1])) == -1 )
		ft_perror();
	map = creat_map(av[1]);
	// putmap(map);
	data = malloc(sizeof(t_data));
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		ft_perror();
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
	display_map(data, map);
	mlx_loop(data->mlx_ptr);
	return(0);	
}
	// data_mlx(data, map);
	// mlx_loop_hook(data->mlx_ptr, loop_hook, data);    
	// mlx_mouse_hook(data-> mlx_win, mouse_hook, data);
	// mlx_destroy_display(data->mlx_ptr);
	// mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);

