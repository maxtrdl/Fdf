/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 10:24:12 by mtrudel           #+#    #+#             */
/*   Updated: 2017/09/21 15:44:19 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int				i;
	long double		nbr;
	int				neg;

	i = 0;
	nbr = 0;
	neg = 0;
	while (nptr[i] == '\n' || nptr[i] == '\t' || nptr[i] == '\v' || \
			nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == 45)
		neg = 1;
	if (nptr[i] == 45 || nptr[i] == 43)
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		nbr = nbr * 10;
		nbr = nbr + (int)nptr[i] - 48;
		i++;
	}
	if (nbr >= 2147483647)
		nbr = 2147483646;
	if (neg == 1)
		return (-nbr);
	return (nbr);
}
