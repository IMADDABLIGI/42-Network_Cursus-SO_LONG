/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_maze_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:16:11 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/18 10:38:00 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

static char	*ft_mlc_bonus(int size)
{
	int		j;
	char	*str;

	j = 0;
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);
	while (j < size)
	{
		str[j] = '1';
		j++;
	}
	str[size] = '\0';
	return (str);
}

void	ft_get_maze_bonus(t_data *data)
{
	int		i;
	int		width;
	int		height;

	i = 0;
	height = data->height / 50;
	width = data->width / 50;
	data->maze = malloc((height + 1) * sizeof(char *));
	if (!data->maze)
		ft_write_error_bonus(4, data);
	while (i < height)
	{
		data->maze[i] = ft_mlc_bonus(width);
		if (!data->maze[i])
			ft_write_error2_bonus(data->maze, i, data);
		i++;
	}
	data->maze[i] = 0;
}
