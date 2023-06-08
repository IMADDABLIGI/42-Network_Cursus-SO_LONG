/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:01:48 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/19 12:55:16 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

int	ft_count_bonus(t_data *data)
{
	mlx_string_put(data->mlx, data->mlx_win, 0, 0, 0xFFFFFF, "Move :");
	if (data->m_i == data->p_i && data->m_j == data->p_j)
	{
		mlx_string_put(data->mlx, data->mlx_win, 70, 0, 0xFFFFFF, data->stm);
	}
	else if (data->m_i != data->p_i || data->m_j != data->p_j)
	{
		free(data->stm);
		data->stm = ft_itoa(data->move);
		mlx_string_put(data->mlx, data->mlx_win, 70, 0, 0xFFFFFF, data->stm);
		data->m_i = data->p_i;
		data->m_j = data->p_j;
	}
	return (1);
}
