/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 13:10:13 by hasabir           #+#    #+#             */
/*   Updated: 2022/06/21 18:12:50 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_ordinate(char *av)
{
	char	*tmp;
	int		fd;
	int		y;

	y = 0;
	fd = open(av, O_RDONLY);
	if (!fd)
		ft_perror();
	tmp = get_next_line(fd);
	while(tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		y++;
	}
	close(fd);
	return (y);
}

int	*map_line(char *line, int x)
{
	int		*mapline;
	char	**tmp;
	int		i;
	
	mapline = malloc(x * sizeof(int));
	if (!mapline)
		ft_perror();
	tmp = ft_split(line, ' ');
	i = 0;
	while (tmp[i] && i < x)
	{
		mapline[i] = ft_atoi(tmp[i]);
		i++;
	}
	return (mapline);
}

void	get_map(t_map *map, int fd)
{
	char	*line;
	int		i;
		
	i = 0;
	line = get_next_line(fd);
	map->size_x = ft_strlenmap(line);
	while(line && i < map->size_y)
	{
		map->matrix[i] = map_line(line, map->size_x);
		i++;
		free(line);
		line = get_next_line(fd);	
	}
	return ;
}

t_map *creat_map(char *av)
{
	t_map *new_map;
	int fd;
	
	fd = open(av, O_RDONLY);
	if (!fd)
		ft_perror();
	new_map = (t_map *)malloc(sizeof(t_map));
	if (!new_map)
		ft_perror();
	new_map->size_x = 0;
	new_map->size_y = get_ordinate(av);
	new_map->color = RED;
	new_map->matrix = malloc(new_map->size_y * sizeof(int **));
	get_map(new_map, fd);
	return (new_map);
}
