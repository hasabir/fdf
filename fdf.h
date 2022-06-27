/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 12:11:42 by hasabir           #+#    #+#             */
/*   Updated: 2022/06/27 19:29:21 by hasabir          ###   ########.fr       */
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
#define WHITHE 0xFFFFFF

typedef struct s_map
{
	int	size_x;
	int	size_y;
	int	**matrix;
	int	**color;
	
}t_map ;

typedef struct s_data_coordinate
{
	// int x;
	// int y;
	int z;
	int x1;
	int	y1;
	int x2;
	int y2;
	int ex;
	int ey;
	int dx;
	int dy;
	// int p1;
	// int p2;
	int px;
	int py;
}t_data_coordinate ;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int 	x;
	int 	y;
	int		zoom;
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
// int		*map_line(t_map map, char *line, int x);
// int 	draw_line2(int x1, int y1, int x2, int y2, t_data *data, t_map *map);
// int 	draw_line(int x1, int y1, int x2, int y2, t_data *data, t_map *map);
int		draw_line3(t_data_coordinate *coordinate, t_data *data, t_map *map);
// int		draw_line4(t_data_coordinate *coordinate, t_data *data, t_map *map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int 	key_hook(int key, t_data *data);
int		mouse_hook(int button, int x, int y, t_data *data);
int		loop_hook(t_data *data, t_map *map);
int		display_map1(t_data *data, t_map *map);
int		display_map(t_data *data, t_map *map);
void 	putmap(t_map *map);
int	ft_strnstr(const char *s1, const char *s2, int len);
char	*ft_strchr(const char *s, int c);
int	ft_atoi_base(char	*str, char	*base);



#endif