/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:01:25 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/19 10:01:03 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_cheek_next(char **map, int i, int j)
{
	if (map[i][j] == '0' || map[i][j] == 'P' || map[i][j] == 'C')
		return (1);
	return (0);
}

int	ft_find_path(t_data *data, int i, int j)
{
	if (i == data->f_i && j == data->f_j)
		return (1);
	if (ft_cheek_next(data->map, i, j))
	{
		if (data->maze[i][j] == '0')
			return (0);
		data->maze[i][j] = '0';
		if (ft_find_path(data, i + 1, j))
			return (1);
		if (ft_find_path(data, i, j + 1))
			return (1);
		if (ft_find_path(data, i - 1, j))
			return (1);
		if (ft_find_path(data, i, j - 1))
			return (1);
		return (0);
	}
	return (0);
}
