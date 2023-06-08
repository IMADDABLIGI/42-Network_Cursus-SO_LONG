/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_error1_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:14:45 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/18 15:37:46 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	ft_error_textures_b(t_data *data)
{
	ft_end_bonus(data);
	write(1, "!ERROR in Textures\n", 19);
	exit (1);
}

void	ft_write_error1_bonus(char *buff, char *line, int fd)
{
	close(fd);
	if (line)
		free(line);
	free(buff);
	write(1, "!ERROR in reading the map\n", 26);
	exit (1);
}
