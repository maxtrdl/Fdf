/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 10:03:08 by mtrudel           #+#    #+#             */
/*   Updated: 2017/09/21 15:57:03 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_struct(t_coordonnees *coo, char *str)
{
	char	*line;

	coo->y = 0;
	coo->fd = open(str, O_RDONLY);
	coo->map = (int **)malloc(1 + (coo->inf[1]) * sizeof(int *));
	while (get_next_line(coo->fd, &line))
	{
		coo->i = 0;
		coo->x = 0;
		coo->map[coo->y] = (int *)malloc(1 + (coo->inf[0]) * sizeof(int));
		while (line[coo->i])
		{
			if (((line[coo->i] > 47 && line[coo->i] < 58) || (line[coo->i] \
					== '-')) && (line[coo->i - 1] == ' ' || coo->i == 0))
			{
				coo->map[coo->y][coo->x] = ft_atoi(&line[coo->i]);
				if (coo->map[coo->y][coo->x] > 100)
					coo->map[coo->y][coo->x] = 100;
				coo->x++;
			}
			coo->i++;
		}
		coo->y++;
	}
	close(coo->fd);
}
