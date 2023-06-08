/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norme_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:16:00 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/19 11:50:56 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	ft_enemy(t_data *data)
{
	ft_end_bonus(data);
	write(1, "\033[0;31m\nGame Over\n\033[0m", 22);
	exit (0);
}

void	ft_norme1_bonus(t_data *data)
{
	if (data->map[data->p_i][data->p_j + 1] == 'A')
		ft_enemy(data);
	if (data->map[data->p_i][data->p_j + 1] != 'E')
	{
		write(1, "\nmove : ", 8);
		ft_putnbr_fd_bonus(++data->move);
		data->map[data->p_i][data->p_j++] = '0';
		data->map[data->p_i][data->p_j] = 'P';
	}
	else if (data->map[data->p_i][data->p_j + 1] == 'E')
	{
		if (ft_cheek_coins_bonus(data))
		{
			write(1, "\nmove : ", 8);
			ft_putnbr_fd_bonus(++data->move);
			data->map[data->p_i][data->p_j++] = '0';
			data->map[data->p_i][data->p_j] = 'P';
		}
		else
			return ;
	}
}

void	ft_norme2_bonus(t_data *data)
{
	if (data->map[data->p_i +1][data->p_j] == 'A')
		ft_enemy(data);
	if (data->map[data->p_i +1][data->p_j] != 'E')
	{
		write(1, "\nmove : ", 8);
		ft_putnbr_fd_bonus(++data->move);
		data->map[data->p_i++][data->p_j] = '0';
		data->map[data->p_i][data->p_j] = 'P';
	}
	else if (data->map[data->p_i +1][data->p_j] == 'E')
	{
		if (ft_cheek_coins_bonus(data))
		{
			write(1, "\nmove : ", 8);
			ft_putnbr_fd_bonus(++data->move);
			data->map[data->p_i++][data->p_j] = '0';
			data->map[data->p_i][data->p_j] = 'P';
		}
		else
			return ;
	}
}

void	ft_norme3_bonus(t_data *data)
{
	if (data->map[data->p_i -1][data->p_j] == 'A')
		ft_enemy(data);
	if (data->map[data->p_i -1][data->p_j] != 'E')
	{
		write(1, "\nmove : ", 8);
		ft_putnbr_fd_bonus(++data->move);
		data->map[data->p_i--][data->p_j] = '0';
		data->map[data->p_i][data->p_j] = 'P';
	}
	else if (data->map[data->p_i -1][data->p_j] == 'E')
	{
		if (ft_cheek_coins_bonus(data))
		{
			write(1, "\nmove : ", 8);
			ft_putnbr_fd_bonus(++data->move);
			data->map[data->p_i--][data->p_j] = '0';
			data->map[data->p_i][data->p_j] = 'P';
		}
		else
			return ;
	}
}

void	ft_norme4_bonus(t_data *data)
{
	if (data->map[data->p_i][data->p_j -1] == 'A')
		ft_enemy(data);
	if (data->map[data->p_i][data->p_j -1] != 'E')
	{
		write(1, "\nmove : ", 8);
		ft_putnbr_fd_bonus(++data->move);
		data->map[data->p_i][data->p_j--] = '0';
		data->map[data->p_i][data->p_j] = 'P';
	}
	else if (data->map[data->p_i][data->p_j -1] == 'E')
	{
		if (ft_cheek_coins_bonus(data))
		{
			write(1, "\nmove : ", 8);
			ft_putnbr_fd_bonus(++data->move);
			data->map[data->p_i][data->p_j--] = '0';
			data->map[data->p_i][data->p_j] = 'P';
		}
		else
			return ;
	}
}
