/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 12:11:42 by hasabir           #+#    #+#             */
/*   Updated: 2022/06/21 18:43:23 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "get_next_line.h"
#include <limits.h>
#include <mlx.h>
#include <math.h> 

#define WINDOW_WIDTH 1000
#define	WINDOW_HEIGHT 1000
#define RED 0xFF0000
#define BLUE 0x0000FF
#define GREEN 0x00FF00
// #define WHITHE 0xFFFFFF

typedef struct s_map
{
	int	size_x;
	int	size_y;
	int	**matrix;
	int	color;
	
}t_map ;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int 	x;
	int 	y;
	int	zoom;
	// t_map	*map;
	void	*mlx_ptr;
	void	*mlx_win;
	int	color;
}	t_data;

// typedef struct s_map	t_map; 
int		ft_atoi(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		get_ordinate(char *av);
void	get_map(t_map *map, int fd);
void	ft_perror(void);
t_map 	*creat_map(char *av);
int		ft_strlenmap(const char *str);
char	**ft_split(char *s, char c);
void    ft_bzero(void   *s, size_t n);
void    *ft_calloc(size_t count, size_t size);
int		*map_line(char *line, int x);
int 	draw_line2(int x1, int y1, int x2, int y2, t_data *data, t_map *map);
int 	draw_line(int x1, int y1, int x2, int y2, t_data *data, t_map *map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int 	key_hook(int key, t_data *data);
int		mouse_hook(int button, int x, int y, t_data *data);
int		loop_hook(t_data *data, t_map *map);
int		display_map(t_data *data, t_map *map);
void 	putmap(t_map *map);



#endif