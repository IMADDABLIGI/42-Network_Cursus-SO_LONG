/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:12:18 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/17 15:23:28 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	**ft_callstg(char **ptr, char const *s, char c, t_data *data)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			i++;
		}
		while (s[i] != '\0' && s[i] != c)
			i++;
		while (s[i] != '\0' && s[i] == c)
			i++;
	}
	ptr = malloc((count + 1) * sizeof(char *));
	if (!ptr)
		ft_write_error(2, data);
	ptr[count] = 0;
	return (ptr);
}

static size_t	len_string(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static char	*wrt_stg(char const *s, char c)
{
	size_t	len_s;
	char	*pptr;

	len_s = len_string(s, c);
	pptr = malloc((len_s + 1) * sizeof(char));
	if (!pptr)
		return (0);
	ft_memcpy(pptr, s, len_s);
	pptr[len_s] = '\0';
	return (pptr);
}

static char	**free_all(char **ptr, size_t i, t_data *data)
{
	while (i--)
		free(ptr[i]);
	free(ptr);
	ft_write_error(2, data);
	return (0);
}

char	**ft_split(char const *s, char c, t_data *data)
{
	char	**ptr;
	size_t	i;

	ptr = NULL;
	ptr = ft_callstg(ptr, s, c, data);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			ptr[i++] = wrt_stg(s, c);
			if (!ptr[i - 1])
				return (free_all(ptr, i, data));
		}
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (ptr);
}
