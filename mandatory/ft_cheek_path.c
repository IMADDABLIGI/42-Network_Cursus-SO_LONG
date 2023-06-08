/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheek_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:46:53 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/19 10:01:36 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_remaze(t_data *data, int i, int j)
{
	while (data->maze[i])
	{
		j = 0;
		while (data->maze[i][j])
		{
			if (data->maze[i][j] != '1')
				data->maze[i][j] = '1';
			j++;
		}
		i++;
	}
}

void	ft_cheek_exit(t_data *data)
{
	data->f_i = data->e_i;
	data->f_j = data->e_j;
	if (!ft_find_path(data, data->p_i, data->p_j))
	{
		write(1, "No Path Available For Exit\n", 27);
		ft_end(data);
		exit (1);
	}
}

static void	ft_cheek_coins_path(t_data *data, int i, int j)
{
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
			{
				data->f_i = i;
				data->f_j = j;
				if (!ft_find_path(data, data->p_i, data->p_j))
				{
					write(1, "No Path Available For Coin\n", 27);
					ft_end(data);
					exit (1);
				}
				ft_remaze(data, 0, 0);
			}
			j++;
		}
		i++;
	}
}

void	ft_cheek_path(t_data *data)
{
	ft_get_maze(data);
	ft_cheek_coins_path(data, 0, 0);
	ft_cheek_exit(data);
}
