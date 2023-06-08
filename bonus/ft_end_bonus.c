/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:16:50 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/19 13:01:13 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	ft_free_maze_bonus(t_data *data)
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

void	ft_end_bonus(t_data *data)
{
	free(data->av);
	free(data->stm);
	ft_free_split_bonus(data);
	ft_free_maze_bonus(data);
}
