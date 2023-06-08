/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:30:10 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/19 09:48:01 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_fill_map(t_data *data, char *str)
{
	ft_cheek_ber(str);
	data->av = ft_map(str);
	ft_cheek_map(data);
	data->map = ft_split(data->av, '\n', data);
	ft_width_height(data);
	ft_cheek_edge(data);
	ft_find_player(data);
	ft_find_exit(data);
	ft_cheek_path(data);
}
