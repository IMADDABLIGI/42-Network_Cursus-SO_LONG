/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:16:36 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/19 10:06:09 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

static int	ft_cheek_next(char **map, int i, int j)
{
	if (map[i][j] == '0' || map[i][j] == 'P' || map[i][j] == 'C')
		return (1);
	return (0);
}

int	ft_find_path_bonus(t_data *data, int i, int j)
{
	if (i == data->f_i && j == data->f_j)
		return (1);
	if (ft_cheek_next(data->map, i, j))
	{
		if (data->maze[i][j] == '0')
			return (0);
		data->maze[i][j] = '0';
		if (ft_find_path_bonus(data, i + 1, j))
			return (1);
		if (ft_find_path_bonus(data, i, j + 1))
			return (1);
		if (ft_find_path_bonus(data, i - 1, j))
			return (1);
		if (ft_find_path_bonus(data, i, j - 1))
			return (1);
		return (0);
	}
	return (0);
}
