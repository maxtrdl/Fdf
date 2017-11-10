/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:24:31 by mtrudel           #+#    #+#             */
/*   Updated: 2017/03/08 01:04:18 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_go_to_fchar(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

static int		inter_gnl(char **resu, char **tmp, char **line)
{
	*line = ft_strnew(ft_go_to_fchar(*resu, '\n'));
	*line = ft_strncpy(*line, *resu, ft_go_to_fchar(*resu, '\n'));
	if (((int)ft_strlen(*resu) - 1) >= ft_go_to_fchar(*resu, '\n'))
	{
		*tmp = ft_strdup(ft_strchr(*resu, '\n') + 1);
		*resu = ft_strcpy(*resu, *tmp);
		ft_strdel(tmp);
	}
	return (1);
}

static int		last_gnl(char **resu, char **line)
{
	*line = ft_strnew(ft_strlen(*resu));
	*line = ft_strcpy(*line, *resu);
	*resu = ft_strcpy(*resu, "");
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	static char		*resu;
	char			*tmp;

	if (fd < 0 || BUFF_SIZE < 1 || (!resu && !(resu = ft_strnew(1)))\
			|| (ret = read(fd, buf, 0)) < 0)
		return (-1);
	if (ft_strchr(resu, '\n') != NULL)
		return (inter_gnl(&resu, &tmp, line));
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		resu = ft_strfreejoin(resu, buf);
		if (ft_strchr(buf, '\n') != NULL)
			return (inter_gnl(&resu, &tmp, line));
	}
	if (ft_strlen(resu) > 1)
		return (last_gnl(&resu, line));
	if (resu)
		ft_strdel(&resu);
	return (0);
}
