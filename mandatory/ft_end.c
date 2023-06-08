/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:54:47 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/17 10:52:40 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_free_maze(t_data *data)
{
	int	size;

	size = data->tall;
	while (size >= 0)
	{
		free(data->maze[size]);
		size--;
	}
	free(data->maze);
}

void	ft_end(t_data *data)
{
	free(data->av);
	ft_free_split(data);
	ft_free_maze(data);
}
