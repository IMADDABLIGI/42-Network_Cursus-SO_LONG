/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheek_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:53:24 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/18 18:55:04 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_cheek_ber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i < 5)
	{
		write(1, "ERROR IN MAP NAME\n", 18);
		exit (1);
	}
	i--;
	if (str[i] != 'r' && str[i - 1] != 'e' && str[i - 2] != 'b')
	{
		write(1, "ERROR IN MAP NAME\n", 18);
		exit (1);
	}
}

static void	ft_cheek_n(t_data *data)
{
	int	i;

	i = 0;
	while (data->av[i])
	{
		if (data->av[i] == '\n' && data->av[i + 1] == '\n')
			ft_write_error(5, data);
		i++;
	}
	if (i < 17)
		ft_write_error(5, data);
	if (data->av[--i] == '\n')
		ft_write_error(5, data);
}

static int	ft_cheek_count(t_data *data, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (data->av[i])
	{
		if (data->av[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	ft_cheek_map(t_data *data)
{
	ft_cheek_n(data);
	if (ft_cheek_count(data, 'P') != 1)
		ft_write_error(5, data);
	if (!ft_cheek_count(data, 'C'))
		ft_write_error(5, data);
	if (!ft_cheek_count(data, '\n'))
		ft_write_error(5, data);
	if (ft_cheek_count(data, 'E') != 1)
		ft_write_error(5, data);
}
