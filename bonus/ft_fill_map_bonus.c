/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:16:40 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/17 17:44:43 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	ft_fill_map_bonus(t_data *data, char *str)
{
	ft_cheek_ber_bonus(str);
	data->av = ft_map_bonus(str);
	ft_cheek_map_bonus(data);
	data->map = ft_split_bonus(data->av, '\n', data);
	ft_width_height_bonus(data);
	ft_cheek_edge_bonus(data);
	ft_find_player_bonus(data);
	ft_find_exit_bonus(data);
	ft_cheek_path_bonus(data);
}
