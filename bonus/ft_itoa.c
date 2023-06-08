/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:09:05 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/19 12:11:38 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

static int	ln_n(long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	long	nb;
	char	*ptr;

	i = 0;
	nb = n;
	n = ln_n(nb);
	ptr = (char *)malloc((n + 1) * sizeof(char));
	if (!ptr)
		return (0);
	if (nb == 0)
		ptr[0] = '0';
	while (nb > 0)
	{
		ptr[n - i - 1] = (nb % 10) + '0';
		nb = nb / 10;
		i++;
	}
	ptr[n] = '\0';
	return (ptr);
}
