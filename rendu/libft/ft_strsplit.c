/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 15:30:22 by mtrudel           #+#    #+#             */
/*   Updated: 2017/02/13 14:53:29 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countword(const char *s, char c)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if ((s[i - 1] == c && s[i] != c && i > 0) || (i < 1 && s[i] != c))
			k++;
		i++;
	}
	return (k);
}

static char		*ft_letter(const char *s, char c, size_t i)
{
	size_t k;

	k = i;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (ft_strsub(s, k, i - k));
}

char			**ft_strsplit(const char *s, char c)
{
	int		i;
	char	**dst;
	int		m;

	i = 0;
	m = 0;
	if (!s)
		return (NULL);
	if (!(dst = (char**)malloc(sizeof(char*) * (ft_countword(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if ((s[i - 1] == c && s[i] != c && i > 0) || (i < 1 && s[i] != c))
		{
			dst[m] = ft_letter(s, c, i);
			m++;
			while (s[i] != c && s[i + 1] != '\0')
				i++;
		}
		i++;
	}
	dst[m] = NULL;
	return (dst);
}
