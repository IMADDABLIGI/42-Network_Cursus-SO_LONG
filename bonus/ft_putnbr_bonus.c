/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:15:46 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/17 17:30:20 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	*ft_memcpy_bonus(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src == dst)
		return (dst);
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dst);
}

static void	ft_putchar_fd_bonus(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_fd_bonus(int n)
{
	long	nb;

	nb = n;
	if (nb > 9)
	{
		ft_putnbr_fd_bonus(nb / 10);
		ft_putnbr_fd_bonus(nb % 10);
	}
	if (nb >= 0 && nb <= 9)
		ft_putchar_fd_bonus(nb + '0');
}
