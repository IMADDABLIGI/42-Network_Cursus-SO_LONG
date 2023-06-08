/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_error2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:29:50 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/16 11:44:36 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_write_error2(char **maze, int i, t_data *data)
{
	while (i--)
		free(maze[i]);
	free(maze);
	free(data->av);
	ft_free_split(data);
	write(1, "!Error in Maze\n", 15);
	exit (1);
}
