/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 23:11:52 by iel-mach          #+#    #+#             */
/*   Updated: 2022/07/28 19:52:21 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# define WIN_HEIGHT 1080
# define WIN_WIDTH 1920
# define SIZE_IMG 64

typedef struct cub
{
	char	*n;
	char	*s;
	char	*w;
	char	*e;
	char	*f;
	char	*c;
	char	**map;
	int		redf;
	int		greenf;
	int		bluef;
	int		redc;
	int		greenc;
	int		bluec;
}	t_cub;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct ddi
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		dx;
	int		dy;
	int		steps;
	float	xinc;
	float	yinc;
	float	x;
	float	y;
	int		dwall;
	float	c;
}	t_ddi;

typedef struct img
{
	int		whidth;
	int		height;
	void	*black;
	void	*white;
	void	*red;
	void	*no9ta;
	char	**map;
	void	*mlx;
	void	*mlx_win;
	t_data	data;
	t_data	*pics;
	int		floor;
	int		ceilling;
	int		i;
	int		j;
	int		x;
	int		y;
	float	y0;
	float	x0;
	float	a;
	int		r;
}	t_img;

typedef struct check
{
	int	n;
	int	s;
	int	w;
	int	e;
	int	i;
	int	f;
	int	c;
	int	no;
	int	so;
	int	we;
	int	ea;
	int	g;
}	t_check;

int		ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strrchr(char *s, int c);
int		ft_strlen(char *str);
void	ft_checkex(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
int		check_line(char *s);
char	*get_next_line(int fd);
char	*ft_strdup(char *s1);
char	**ft_split(char *s, char c);
char	*ft_skip(char *s1);
void	ft_checkcomma(t_cub *cub);
int		ft_checktexture(t_cub *cub);
int		ft_initcolor(t_cub *cub);
int		ft_return(char *str);
char	*ft_strjoin1(char *s1, char *s2);
int		ft_atoi(char *s);
void	ft_checkmap(char **map);
t_cub	*ft_parse(char **map);
int		ft_isdigit(int c);
int		last_char(char *str);
int		ft_skipspace(char *str);
void	ft_checkfile(char **map);
int		ft_checkspace(char *str);
char	*ft_getmap(char *str);
void	ft_hooks(t_img img);
t_check	ft_check_init(void);
t_img	ft_img(t_img img, t_cub *cub);
void	ft_errors(t_check check);
int		ft_exit(void);
int		ft_keyhook(int key, t_img *img);
void	ft_dda(t_img *img, t_ddi *ddi);
void	ft_rays(t_img *img);
int		ft_checkzero(int i, char *str, char *str1);
void	ft_sheftcolor(t_img *img, t_cub *cub);
void	ft_check_norm(void);
void	ft_exit_f(void);
int		ft_getcolor_norm(t_ddi *ddi, t_img *img, int y, int x);
void	ft_draw(t_img *img, t_ddi *ddi);
int		ft_getcolor(t_ddi *ddi, t_img *img, int y, int x);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_draw_norm(t_img *img, t_ddi *ddi, int dakshi);
void	ft_key_13(t_img *img);
void	ft_key_0(t_img *img);
void	ft_key_1(t_img *img);
void	ft_key_2(t_img *img);
int		ft_checkzero(int i, char *str, char *str1);
t_cub	*ft_parse(char **map);

#endif