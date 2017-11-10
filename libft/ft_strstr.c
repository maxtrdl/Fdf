/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:51:33 by mtrudel           #+#    #+#             */
/*   Updated: 2016/11/09 14:53:50 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;
	size_t	tmp;

	i = 0;
	j = 0;
	tmp = ft_strlen(little);
	if (tmp == 0)
		return ((char *)big);
	while (big[i] != '\0')
	{
		if (little[j] == big[i])
		{
			while (little[j] == big[i + j] && little[j] != '\0')
				j++;
			if (j == tmp)
				return ((char *)big + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
