/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_linker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 14:30:55 by mtrudel           #+#    #+#             */
/*   Updated: 2017/10/02 17:29:45 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_bre(t_bresenham *bre)
{
	bre->x = bre->xi;
	bre->y = bre->yi;
	bre->dx = bre->xf - bre->xi;
	bre->dy = bre->yf - bre->yi;
	bre->xinc = (bre->dx > 0) ? 1 : -1;
	bre->yinc = (bre->dy > 0) ? 1 : -1;
	bre->dx = fabs(bre->dx);
	bre->dy = fabs(bre->dy);
	bre->i = 1;
}

void	draw_hor(t_window *win, t_image *image, t_bresenham *bre)
{
	bre->cumul = bre->dx / 2;
	while (bre->i <= bre->dx)
	{
		bre->x += bre->xinc;
		bre->cumul += bre->dy;
		if (bre->cumul >= bre->dx)
		{
			bre->cumul -= bre->dx;
			bre->y += bre->yinc;
		}
		bre->i++;
		if (bre->x >= 0 && bre->x < win->widht && bre->y >= 0 \
				&& bre->y < win->height)
			image->data[bre->x + (bre->y * win->widht)] = bre->col;
	}
}

void	draw_ver(t_window *win, t_image *image, t_bresenham *bre)
{
	bre->cumul = bre->dy / 2;
	while (bre->i <= bre->dy)
	{
		bre->y += bre->yinc;
		bre->cumul += bre->dx;
		if (bre->cumul >= bre->dy)
		{
			bre->cumul -= bre->dy;
			bre->x += bre->xinc;
		}
		bre->i++;
		if (bre->x >= 0 && bre->x < win->widht && bre->y >= 0 \
				&& bre->y < win->height)
			image->data[bre->x + (bre->y * win->widht)] = bre->col;
	}
}

void	bresenham(t_window *win, t_image *image, t_bresenham *bre)
{
	init_bre(bre);
	if (bre->x >= 0 && bre->x < win->widht && bre->y >= 0 \
			&& bre->y < win->height)
		image->data[bre->x + (bre->y * win->widht)] = bre->col;
	if (bre->dx > bre->dy)
		draw_hor(win, image, bre);
	else
		draw_ver(win, image, bre);
}
