/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_error2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:14:35 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/18 15:54:11 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	ft_write_error2_bonus(char **maze, int i, t_data *data)
{
	while (i--)
		free(maze[i]);
	free(maze);
	free(data->av);
	ft_free_split_bonus(data);
	write(1, "!Error in Maze\n", 15);
	exit (1);
}
