/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:53:46 by mtrudel           #+#    #+#             */
/*   Updated: 2017/09/28 16:28:55 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

typedef struct		s_coordonnees
{
	int				**map;
	double			off_z;
	int				inf[2];
	int				fd;
	int				x;
	int				y;
	int				zoom;
	int				offsetx;
	int				i;
	int				offsety;
}					t_coordonnees;

typedef struct		s_bresenham
{
	double			dx;
	double			dy;
	double			i;
	double			xinc;
	double			yinc;
	double			cumul;
	int				x;
	int				y;
	double			xi;
	double			xf;
	double			yi;
	double			yf;
	int				col;
}					t_bresenham;

typedef struct		s_window
{
	int				widht;
	int				height;
	void			*mlx;
	void			*fen;
}					t_window;

typedef struct		s_image
{
	void			*img;
	int				*data;
	int				bpp;
	int				sl;
	int				ed;
}					t_image;

typedef struct		s_env
{
	t_coordonnees	*coo;
	t_bresenham		*bre;
	t_window		*win;
	t_image			*image;
}					t_env;

void				print_image(t_env *env);
int					ft_parsing(char *str, t_coordonnees *coo);
int					ft_usage(int code_err);
int					get_key(int key_code, t_env *env);
int					release_key(void);
int					event_key(t_env *env);
int					init_env(t_env *env);
void				mlx_init_img(t_env *env);
void				ft_fill_struct(t_coordonnees *coo, char *str);
int					ft_nb_of_point(int fd);
void				ft_ray_linker(t_window *win, t_image *image\
		, t_coordonnees *coo, t_bresenham *bre);
void				bresenham(t_window *win, t_image *image, t_bresenham *bre);
void				init_bre(t_bresenham *bre);
void				draw_hor(t_window *win, t_image *image, t_bresenham *bre);
void				draw_ver(t_window *win, t_image *image, t_bresenham *bre);
void				iso_hor(t_window *win, t_image *image, t_coordonnees *coo\
		, t_bresenham *bre);
void				iso_ver(t_window *win, t_image *image, t_coordonnees *coo\
		, t_bresenham *bre);
#endif
