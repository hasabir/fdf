/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 12:11:42 by hasabir           #+#    #+#             */
/*   Updated: 2022/07/07 10:33:56 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <limits.h>
# include <mlx.h>
# include <math.h> 
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

struct s_map
{
	int	size_x;
	int	size_y;
	int	img_height;
	int	img_width;
	int	**matrix;
	int	**color;
	int	i;
	int	zoom;	
};
typedef struct s_map				t_map;

struct s_data_coordinate
{
	int	z1;
	int	z2;
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	ex;
	int	ey;
	int	dx;
	int	dy;
	int	px;
	int	py;
};
typedef struct s_data_coordinate	t_data_coordinate;

struct	s_data {
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					x;
	int					y;
	int					mv_x;
	void				*mlx_ptr;
	void				*mlx_win;
	int					color;
	int					z_axis;
	t_map				*map;
	t_data_coordinate	*coordinate;
};

typedef struct s_data				t_data;
char	*get_next_line(int fd);
int		ft_strlen(const char *str);
int		ft_strlcpy(char *dst, const char *src, int dstsize);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, int start, int len);
int		ft_atoi(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		get_ordinate(char *av);
void	get_map(t_map *map, int fd);
void	ft_perror(void);
t_map	*creat_map(char *av);
int		ft_strlenmap(const char *str);
char	**ft_split(char *s, char c);
void	ft_bzero(void *s, size_t n);
void	*ft_malloc(size_t count, size_t size);
void	*ft_calloc(size_t count, size_t size);
int		line_draw(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_hook(int key, t_data *data);
int		mouse_hook(int button, int x, int y, t_data *data);
int		loop_hook(t_data *data, t_map *map);
int		display_map(t_data *data);
int		ft_strnstr(const char *s1, const char *s2, int len);
char	*ft_strchr(const char *s, int c);
int		ft_atoi_base(char	*str, char	*base);
int		ft_strcmp(char *s1, char *s2);
int		set_colors(t_map *map, int coordinate, char *arg, int n);
void	towd_to_iso(int *x, int *y, int z, int i);
int		ft_zoom(t_map *map);
void	set_default_x(t_data *data, int i);
int		distroy_window_x(int key, t_data *data);

#endif