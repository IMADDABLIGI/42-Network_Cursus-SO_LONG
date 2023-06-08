/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:16:45 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/19 12:46:25 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

int	ft_event_bonus(int keycode, t_data *data)
{
	if (keycode == 123 || keycode == 0)
		data->key = 'l';
	else if (keycode == 124 || keycode == 2)
		data->key = 'w';
	ft_push_bonus(keycode, data);
	push_images_bonus(data, 0, 0);
	return (1);
}

int	ft_destroy_bonus(t_data *data)
{
	ft_end_bonus(data);
	exit (0);
}
