/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:56:56 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/18 18:52:23 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_cheek(t_data *data, int keycode, int i, int j)
{
	if ((i == (data->e_i)) && (j == (data->e_j)) && ft_cheek_coins(data))
	{
		ft_end(data);
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit (0);
	}
	else if (keycode == 53)
	{
		ft_end(data);
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit (0);
	}
}

void	ft_push(int keycode, t_data *data)
{
	if (((keycode == 2) || (keycode == 124))
		&& (data->map[data->p_i][data->p_j + 1] != '1'))
		ft_norme1(data);
	else if ((keycode == 1 || keycode == 125)
		&& (data->map[data->p_i + 1][data->p_j] != '1'))
		ft_norme2(data);
	else if ((keycode == 13 || keycode == 126)
		&& (data->map[data->p_i - 1][data->p_j] != '1'))
		ft_norme3(data);
	else if ((keycode == 0 || keycode == 123)
		&& (data->map[data->p_i][data->p_j - 1] != '1'))
		ft_norme4(data);
	ft_cheek(data, keycode, data->p_i, data->p_j);
}
