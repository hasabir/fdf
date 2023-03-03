/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:17:29 by hasabir           #+#    #+#             */
/*   Updated: 2022/07/07 10:33:01 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	loop_hook(t_data *data, t_map *map)
{
	mlx_hook(data->mlx_win, 2, 0, key_hook, data);
	mlx_mouse_hook(data-> mlx_win, mouse_hook, data);
	mlx_hook(data->mlx_win, 17, 0, distroy_window_x, data);
	return (0);
}

int	set_window_size(t_data *data, int i)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (i == 0)
	{
		x = (data->map->size_x * data->map->zoom) * 3;
		return (x);
	}
	else
	{
		y = (data->map->size_y * data->map->zoom) * 2;
		return (y);
	}
	return (0);
}

void	set_data_mlx(t_data *data)
{
	int	x;
	int	y;

	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		ft_perror();
	x = set_window_size(data, 0);
	y = set_window_size(data, 1);
	data->mlx_win = mlx_new_window(data->mlx_ptr, x, y,
			"Fdf");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_win);
		ft_perror();
	}
	data->img = mlx_new_image(data->mlx_ptr, data->map->img_width,
			data->map->img_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	return ;
}

void	set_default(t_data *data)
{	
	int	i;

	data->y = 0;
	data->x = 0;
	if (data->map->size_x == data->map->size_y)
		data->mv_x = data->map->size_y + (data->map->size_y / 10);
	else
		data->mv_x = data->map->size_y;
	i = data->map->zoom;
	data->z_axis = i;
	display_map(data);
	mlx_loop_hook(data->mlx_ptr, loop_hook, data);
	return ;
}

int	main(int ac, char **av)
{
	int		fd;
	t_data	*data;

	if (ac != 2 || ft_strnstr(av[1], ".fdf", ft_strlen(av[1])) == -1)
		exit(EXIT_FAILURE);
	data = malloc(sizeof(t_data));
	if (!data)
		ft_perror();
	data->map = creat_map(av[1]);
	ft_zoom(data->map);
	set_data_mlx(data);
	set_default(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
