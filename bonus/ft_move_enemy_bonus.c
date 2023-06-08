/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemy_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:20:54 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/19 12:32:40 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

static void	ft_find_enemy(t_data *data, int i, int j)
{
	while (data->map[i])
	{	
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'A')
			{	
				data->en_i = i;
				data->en_j = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	ft_norme_enemy(t_data *data, int num)
{
	if (num == 2)
	{
		data->map[data->en_i][data->en_j] = '0';
		data->map[data->en_i][--(data->en_j)] = 'A';
	}
	if (num == 50)
	{
		data->map[data->en_i][data->en_j] = '0';
		data->map[data->en_i][++(data->en_j)] = 'A';
	}
}

int	ft_move_enemy(t_data *data)
{
	static int	count;

	if (count == 6000)
	{
		ft_find_enemy(data, 0, 0);
		if ((((data->map[data->en_i][(data->en_j) - 1]) == '0')
			|| (data->map[data->en_i][(data->en_j) - 1]) == 'P')
		&& (data->dey == 'l'))
			ft_norme_enemy(data, 2);
		else if ((((data->map[data->en_i][(data->en_j) + 1]) == '0')
			|| (data->map[data->en_i][(data->en_j) + 1]) == 'P')
		&& (data->dey == 'r'))
			ft_norme_enemy(data, 50);
		if (((data->map[data->en_i][(data->en_j) - 1]) != '0')
		&& ((data->map[data->en_i][(data->en_j) - 1]) != 'P'))
			data->dey = 'r';
		if ((data->map[data->en_i][(data->en_j) + 1]) != '0'
		&& ((data->map[data->en_i][(data->en_j) + 1]) != 'P'))
			data->dey = 'l';
		count = 0;
		push_images_bonus(data, 0, 0);
	}
	else
		count++;
	return (1);
}
