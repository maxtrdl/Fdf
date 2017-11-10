/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 14:58:48 by mtrudel           #+#    #+#             */
/*   Updated: 2017/09/29 09:27:15 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_usage(int code_err)
{
	if (code_err == 1)
		ft_putstr("usage: ./fdf source_file.fdf\n");
	else if (code_err == 2)
		ft_putstr("usage: ./fdf source_file.fdf\n");
	else if (code_err == 3)
		ft_putstr("No data found.\n");
	else if (code_err == 4)
		ft_putstr("File error.\n");
	else if (code_err == 5)
		ft_putstr("Unreadable file.\n");
	else if (code_err == 6)
		ft_putstr("Missing data.\n");
	return (0);
}

static int	if_char(char *line, t_coordonnees *coo)
{
	if ((line[coo->i] > '9' || line[coo->i] < '0') && \
			line[coo->i] != ' ' && line[coo->i] != '-')
		return (-1);
	else if (line[coo->i] != ' ' && line[coo->i] != '\n' && \
			line[coo->i] != '-' && (line[coo->i - 1] == ' ' || \
			coo->i == 0 || line[coo->i - 1] == '-'))
		coo->x++;
	return (1);
}

static int	ft_checkchar(int fd, t_coordonnees *coo)
{
	char	*line;

	line = NULL;
	coo->inf[0] = 0;
	coo->inf[1] = 0;
	while (get_next_line(fd, &line))
	{
		coo->i = 0;
		coo->x = 0;
		while (line[coo->i] != '\0')
		{
			if (!(if_char(line, coo)))
				return (-1);
			coo->i++;
		}
		if (coo->inf[1] == 0)
			coo->inf[0] = coo->x;
		else if (coo->inf[0] > coo->x)
			return (-1);
		coo->inf[1]++;
	}
	if (line)
		free(line);
	return (1);
}

int			ft_parsing(char *str, t_coordonnees *coo)
{
	char	*filed;
	int		fd;

	filed = ".fdf";
	if (ft_strchr(str, '.') == NULL)
		return (ft_usage(2));
	if (ft_strcmp(ft_strchr(str, '.'), filed) != 0)
		return (ft_usage(2));
	if ((fd = open(str, O_DIRECTORY)) >= 0)
		return (ft_usage(4));
	if ((fd = open(str, O_RDONLY)) < 1)
		return (ft_usage(4));
	if ((ft_checkchar(fd, coo)) == -1)
		return (ft_usage(5));
	if (coo->inf[0] == 0)
		return (ft_usage(6));
	if (coo->inf[0] == 1 && coo->inf[1] == 1)
		return (ft_usage(6));
	ft_fill_struct(coo, str);
	close(fd);
	return (1);
}
