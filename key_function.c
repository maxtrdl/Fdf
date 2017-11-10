/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 10:18:20 by mtrudel           #+#    #+#             */
/*   Updated: 2017/10/02 17:31:28 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_key_plus(t_env *env, int key_code)
{
	if (key_code == 84)
		env->coo->off_z -= 0.1;
	if (key_code == 91)
		env->coo->off_z += 0.1;
	return (0);
}

int			get_key(int key_code, t_env *env)
{
	if (key_code == 53)
		exit(EXIT_SUCCESS);
	if (key_code == 69 && env->coo->zoom < 100)
		env->coo->zoom += 1;
	if (key_code == 78 && env->coo->zoom > 1)
		env->coo->zoom -= 1;
	if (key_code == 124)
		env->coo->offsetx += 10;
	if (key_code == 125)
		env->coo->offsety += 10;
	if (key_code == 123)
		env->coo->offsetx -= 10;
	if (key_code == 126)
		env->coo->offsety -= 10;
	if (key_code == 18)
		env->bre->col = (int)0xFFFFFF;
	if (key_code == 19)
		env->bre->col = (int)0xFF0000;
	if (key_code == 20)
		env->bre->col = (int)0x00FF00;
	if (key_code == 21)
		env->bre->col = (int)0x0000FF;
	get_key_plus(env, key_code);
	return (0);
}

int			release_key(void)
{
	return (1);
}

int			event_key(t_env *env)
{
	mlx_destroy_image(env->win->mlx, env->image->img);
	mlx_init_img(env);
	ft_ray_linker(env->win, env->image, env->coo, env->bre);
	mlx_put_image_to_window(env->win->mlx, env->win->fen,\
			env->image->img, 0, 0);
	return (1);
}
