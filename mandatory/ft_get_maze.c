/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_maze.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:04:39 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/16 11:40:12 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_mlc(int size)
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

void	ft_get_maze(t_data *data)
{
	int		i;
	int		width;
	int		height;

	i = 0;
	height = data->height / 50;
	width = data->width / 50;
	data->maze = malloc((height + 1) * sizeof(char *));
	if (!data->maze)
		ft_write_error(4, data);
	while (i < height)
	{
		data->maze[i] = ft_mlc(width);
		if (!data->maze[i])
			ft_write_error2(data->maze, i, data);
		i++;
	}
	data->maze[i] = 0;
}
