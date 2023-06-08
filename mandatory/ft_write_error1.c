/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_error1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:14:03 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/17 17:09:48 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_write_error1(char *buff, char *line, int fd)
{
	close(fd);
	if (line)
		free(line);
	free(buff);
	write(1, "!ERROR in reading the map\n", 26);
	exit (1);
}
