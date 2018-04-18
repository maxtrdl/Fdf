/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 11:32:06 by mtrudel           #+#    #+#             */
/*   Updated: 2017/10/02 17:28:55 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_image(t_env *env)
{
	mlx_hook(env->win->fen, 2, (1L << 0), get_key, env);
	mlx_hook(env->win->fen, 3, (1L << 1), release_key, env);
	mlx_loop_hook(env->win->mlx, event_key, env);
	mlx_loop(env->win->mlx);
}

void	iso_hor(t_window *win, t_image *image, \
		t_coordonnees *coo, t_bresenham *bre)
{
	bre->xi = ((coo->x - (coo->y)) * coo->zoom) + coo->offsetx;
	bre->yi = ((-coo->map[coo->y][coo->x] * coo->off_z) + coo->x + coo->y)\
				* coo->zoom / 2 + coo->offsety;
	bre->xf = ((coo->x + 1 - coo->y) * coo->zoom) + coo->offsetx;
	bre->yf = ((-coo->map[coo->y][coo->x + 1] * coo->off_z) + coo->x + 1 + \
			coo->y) * coo->zoom / 2 + coo->offsety;
	bresenham(win, image, bre);
}

void	iso_ver(t_window *win, t_image *image, \
		t_coordonnees *coo, t_bresenham *bre)
{
	bre->xi = ((coo->x - (coo->y)) * coo->zoom) + coo->offsetx;
	bre->yi = ((-coo->map[coo->y][coo->x] * coo->off_z) + coo->x + coo->y) * \
				coo->zoom / 2 + coo->offsety;
	bre->xf = ((coo->x - (coo->y + 1)) * coo->zoom) + coo->offsetx;
	bre->yf = ((-coo->map[coo->y + 1][coo->x] * coo->off_z) + coo->x +\
				(coo->y + 1)) * coo->zoom / 2 + coo->offsety;
	bresenham(win, image, bre);
}

void	ft_ray_linker(t_window *win, t_image *image, \
		t_coordonnees *coo, t_bresenham *bre)
{
	int		i;

	i = 0;
	coo->y = 0;
	while (coo->y < coo->inf[1])
	{
		coo->x = 0;
		while (coo->x < coo->inf[0])
		{
			if (coo->x < coo->inf[0] - 1)
				iso_hor(win, image, coo, bre);
			if (coo->y < coo->inf[1] - 1)
				iso_ver(win, image, coo, bre);
			coo->x++;
		}
		coo->y++;
	}
}
