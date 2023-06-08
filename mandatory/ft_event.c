/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:02:36 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/17 14:19:59 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_event(int keycode, t_data *data)
{
	static char	key;

	if (keycode == 123 || keycode == 0)
		key = 'l';
	else if (keycode == 124 || keycode == 2)
		key = 'w';
	ft_push(keycode, data);
	push_images(data, key, 0, 0);
	return (1);
}

int	ft_destroy(t_data *data)
{
	ft_end(data);
	exit (0);
}
