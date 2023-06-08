/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheek_edge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:23:56 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/17 17:35:13 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_ch(t_data *data)
{
	int	j;

	j = 0;
	while (data->map[0][j])
	{
		if (data->map[0][j] != '1')
			ft_write_error(3, data);
		j++;
	}
}

static void	ft_c(char c, t_data *data)
{
	if (c != '1' && c != '0' && c != 'E' && c != 'P' && c != 'C')
		ft_write_error(3, data);
}

static void	ft_ch2(t_data *data, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			ft_c(data->map[i][j], data);
			j++;
		}
		if (j != size)
			ft_write_error(3, data);
		i++;
	}
}

void	ft_cheek_edge(t_data *data)
{
	int	i;
	int	j;
	int	width;
	int	height;

	i = 0;
	j = 0;
	width = (data->width / 50) - 1;
	height = (data->height / 50) - 1;
	while (data->map[i])
	{
		if (data->map[i][0] != '1' || data->map[i][width] != '1')
			ft_write_error(3, data);
		i++;
	}
	while (data->map[height][j])
	{
		if (data->map[height][j] != '1')
			ft_write_error(3, data);
		j++;
	}
	ft_ch(data);
	ft_ch2(data, width + 1);
}
