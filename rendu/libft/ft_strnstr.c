/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:55:31 by mtrudel           #+#    #+#             */
/*   Updated: 2016/11/09 19:16:20 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	tmp;

	i = 0;
	j = 0;
	tmp = ft_strlen(little);
	if (tmp == 0)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		if (little[j] == big[i])
		{
			while (little[j] == big[i + j] && little[j] != '\0')
				++j;
			if ((j + i) > len)
				return (NULL);
			if (j == tmp)
				return ((char *)big + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
