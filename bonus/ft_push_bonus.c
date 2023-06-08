/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:15:51 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/19 12:46:53 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	ft_cheek_bonus(t_data *data, int keycode, int i, int j)
{
	if ((i == (data->e_i)) && (j == (data->e_j)) && ft_cheek_coins_bonus(data))
	{
		ft_end_bonus(data);
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit (0);
	}
	else if (keycode == 53)
	{
		ft_end_bonus(data);
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit (0);
	}
}

void	ft_push_bonus(int keycode, t_data *data)
{
	if (((keycode == 2) || (keycode == 124))
		&& (data->map[data->p_i][data->p_j + 1] != '1'))
		ft_norme1_bonus(data);
	else if ((keycode == 1 || keycode == 125)
		&& (data->map[data->p_i + 1][data->p_j] != '1'))
		ft_norme2_bonus(data);
	else if ((keycode == 13 || keycode == 126)
		&& (data->map[data->p_i - 1][data->p_j] != '1'))
		ft_norme3_bonus(data);
	else if ((keycode == 0 || keycode == 123)
		&& (data->map[data->p_i][data->p_j - 1] != '1'))
		ft_norme4_bonus(data);
	ft_cheek_bonus(data, keycode, data->p_i, data->p_j);
}
