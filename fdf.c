/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 13:48:27 by mtrudel           #+#    #+#             */
/*   Updated: 2017/10/02 17:29:54 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_init_img(t_env *env)
{
	env->image->img = mlx_new_image(env->win->mlx, \
			env->win->widht, env->win->height);
	env->image->data = (int *)mlx_get_data_addr(env->image->img\
			, &env->image->bpp, &env->image->sl, &env->image->ed);
}

void	mlx_init_win(t_env *env)
{
	env->win->mlx = mlx_init();
	env->win->widht = 1000;
	env->win->height = 1000;
	env->win->fen = mlx_new_window(env->win->mlx\
			, env->win->widht, env->win->height, "mlx42");
	mlx_init_img(env);
}

int		init_env(t_env *env)
{
	if (!(env->win = (t_window *)malloc(sizeof(t_window))))
		return (0);
	if (!(env->image = (t_image *)malloc(sizeof(t_image))))
		return (0);
	if (!(env->bre = (t_bresenham *)malloc(sizeof(t_bresenham))))
		return (0);
	env->bre->xi = 0;
	env->bre->yi = 0;
	env->bre->xf = 0;
	env->bre->yf = 0;
	env->bre->col = (int)0xFFFFFF;
	if (!(env->coo = (t_coordonnees *)malloc(sizeof(t_coordonnees))))
		return (0);
	env->coo->zoom = 15;
	env->coo->off_z = 1;
	env->coo->offsetx = 200;
	env->coo->offsety = 200;
	return (1);
}

int		main(int argc, char **argv)
{
	t_env		*env;

	if (argc != 2)
		return (ft_usage(1));
	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (0);
	if (!(init_env(env)))
		return (-1);
	if (!(ft_parsing(argv[1], env->coo)))
		return (-1);
	mlx_init_win(env);
	ft_ray_linker(env->win, env->image, env->coo, env->bre);
	print_image(env);
	return (0);
}
