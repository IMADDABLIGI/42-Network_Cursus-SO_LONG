/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norme.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:30:49 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/17 21:07:08 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_norme1(t_data *data)
{
	if (data->map[data->p_i][data->p_j + 1] != 'E')
	{
		write(1, "\nmove : ", 8);
		ft_putnbr_fd(++data->move);
		data->map[data->p_i][data->p_j++] = '0';
		data->map[data->p_i][data->p_j] = 'P';
	}
	else if (data->map[data->p_i][data->p_j + 1] == 'E')
	{
		if (ft_cheek_coins(data))
		{
			write(1, "\nmove : ", 8);
			ft_putnbr_fd(++data->move);
			data->map[data->p_i][data->p_j++] = '0';
			data->map[data->p_i][data->p_j] = 'P';
		}
		else
			return ;
	}
}

void	ft_norme2(t_data *data)
{
	if (data->map[data->p_i +1][data->p_j] != 'E')
	{
		write(1, "\nmove : ", 8);
		ft_putnbr_fd(++data->move);
		data->map[data->p_i++][data->p_j] = '0';
		data->map[data->p_i][data->p_j] = 'P';
	}
	else if (data->map[data->p_i +1][data->p_j] == 'E')
	{
		if (ft_cheek_coins(data))
		{
			write(1, "\nmove : ", 8);
			ft_putnbr_fd(++data->move);
			data->map[data->p_i++][data->p_j] = '0';
			data->map[data->p_i][data->p_j] = 'P';
		}
		else
			return ;
	}
}

void	ft_norme3(t_data *data)
{
	if (data->map[data->p_i -1][data->p_j] != 'E')
	{
		write(1, "\nmove : ", 8);
		ft_putnbr_fd(++data->move);
		data->map[data->p_i--][data->p_j] = '0';
		data->map[data->p_i][data->p_j] = 'P';
	}
	else if (data->map[data->p_i -1][data->p_j] == 'E')
	{
		if (ft_cheek_coins(data))
		{
			write(1, "\nmove : ", 8);
			ft_putnbr_fd(++data->move);
			data->map[data->p_i--][data->p_j] = '0';
			data->map[data->p_i][data->p_j] = 'P';
		}
		else
			return ;
	}
}

void	ft_norme4(t_data *data)
{
	if (data->map[data->p_i][data->p_j -1] != 'E')
	{
		write(1, "\nmove : ", 8);
		ft_putnbr_fd(++data->move);
		data->map[data->p_i][data->p_j--] = '0';
		data->map[data->p_i][data->p_j] = 'P';
	}
	else if (data->map[data->p_i][data->p_j -1] == 'E')
	{
		if (ft_cheek_coins(data))
		{
			write(1, "\nmove : ", 8);
			ft_putnbr_fd(++data->move);
			data->map[data->p_i][data->p_j--] = '0';
			data->map[data->p_i][data->p_j] = 'P';
		}
		else
			return ;
	}
}
