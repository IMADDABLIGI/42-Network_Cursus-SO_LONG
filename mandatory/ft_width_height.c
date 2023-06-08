/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_height.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:00:11 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/18 15:51:58 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_width_height(t_data *data)
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
