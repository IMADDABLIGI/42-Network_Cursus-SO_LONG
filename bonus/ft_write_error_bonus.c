/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_error_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:14:58 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/18 15:17:16 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	ft_free_split_bonus(t_data *data)
{
	int	size;

	size = data->tall;
	while (size >= 0)
	{
		free(data->map[size]);
		size--;
	}
	free(data->map);
}

void	ft_write_error_bonus(int f, t_data *data)
{
	if (f == 1)
		write(1, "!ERROR check arguments\n", 23);
	else if (f == 2 || f == 5)
	{
		free(data->av);
		if (f == 2)
			write(1, "!ERROR in split\n", 16);
		else if (f == 5)
			write(1, "!ERROR please check the map again\n", 34);
	}
	else if (f == 3 || f == 4)
	{
		free(data->av);
		ft_free_split_bonus(data);
		if (f == 3)
			write(1, "!ERROR please check the map again\n", 34);
		else if (f == 4)
			write(1, "!ERROR in Maze\n", 15);
	}
	else if (f == 6)
	{
		ft_end_bonus(data);
		write(1, "!ERROR in MLX\n", 14);
	}
	exit (1);
}
