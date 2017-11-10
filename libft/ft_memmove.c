/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:40:37 by mtrudel           #+#    #+#             */
/*   Updated: 2016/11/10 09:40:36 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst2;
	unsigned char	*src2;
	size_t			i;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	i = len;
	if (len == 0 || dst == src)
		return (dst);
	if (dst > src)
	{
		while (i > 0)
		{
			i--;
			dst2[i] = src2[i];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
