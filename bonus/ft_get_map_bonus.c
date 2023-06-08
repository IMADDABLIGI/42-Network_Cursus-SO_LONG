/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:16:19 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/18 09:49:27 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strjoin(char *s1, char *s2, int i, int j)
{
	char	*string;
	int		mix;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	mix = ft_strlen(s1) + ft_strlen(s2);
	string = malloc((mix + 1) * sizeof(char));
	if (!string)
		return (free(string), NULL);
	while (s1[i] != '\0')
	{
		string[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		string[i + j] = s2[j];
		j++;
	}
	string[mix] = '\0';
	return (free(s1), string);
}

char	*ft_map_bonus(char *str)
{
	char	*buff;
	char	*line;
	int		readvl;
	int		fd;

	line = NULL;
	fd = open(str, O_RDONLY);
	buff = malloc((4 + 1) * sizeof(char));
	if (!buff)
	{
		write(1, "!ERROR in reading the map\n", 26);
		exit (1);
	}
	readvl = 1;
	while (readvl > 0)
	{
		readvl = read(fd, buff, 4);
		if (readvl == -1)
			ft_write_error1_bonus(buff, line, fd);
		buff[readvl] = 0;
		line = ft_strjoin(line, buff, 0, 0);
		if (!line)
			ft_write_error1_bonus(buff, line, fd);
	}
	return (free(buff), close(fd), line);
}
