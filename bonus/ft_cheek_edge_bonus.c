/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheek_edge_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:23:56 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/18 09:56:40 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

static void	ft_ch_bonus(t_data *data)
{
	int	j;

	j = 0;
	while (data->map[0][j])
	{
		if (data->map[0][j] != '1')
			ft_write_error_bonus(3, data);
		j++;
	}
}

static void	ft_c_bonus(char c, t_data *data)
{
	if (c != '1' && c != '0' && c != 'E' && c != 'P' && c != 'C' && c != 'A')
		ft_write_error_bonus(3, data);
}

static void	ft_ch2_bonus(t_data *data, int size)
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
			ft_c_bonus(data->map[i][j], data);
			j++;
		}
		if (j != size)
			ft_write_error_bonus(3, data);
		i++;
	}
}

void	ft_cheek_edge_bonus(t_data *data)
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
			ft_write_error_bonus(3, data);
		i++;
	}
	while (data->map[height][j])
	{
		if (data->map[height][j] != '1')
			ft_write_error_bonus(3, data);
		j++;
	}
	ft_ch_bonus(data);
	ft_ch2_bonus(data, width + 1);
}
