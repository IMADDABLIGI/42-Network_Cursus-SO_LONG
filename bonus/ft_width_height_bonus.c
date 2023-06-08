/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_height_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:15:29 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/18 17:29:06 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	ft_width_height_bonus(t_data *data)
{
	data->width = 0;
	data->height = 0;
	while (data->map[1][data->width])
		data->width++;
	data->width = data->width * 50;
	while (data->map[data->height])
		data->height++;
	data->height = data->height * 50;
	data->tall = data->height / 50;
}
