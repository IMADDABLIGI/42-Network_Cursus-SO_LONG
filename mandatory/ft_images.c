/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:02:36 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/18 15:50:46 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_error_textures(t_data *data)
{
	ft_end(data);
	write(1, "!ERROR in Textures\n", 19);
	exit (1);
}

static void	ft_textures_2(t_data *data)
{
	data->coin = mlx_xpm_file_to_image(data->mlx,
			"./textures/coin.xpm", &(data->width), &(data->height));
	if (data->height != 50 || data->width != 50)
		ft_error_textures(data);
	data->door = mlx_xpm_file_to_image(data->mlx,
			"./textures/door.xpm", &(data->width), &(data->height));
	if (data->height != 50 || data->width != 50)
		ft_error_textures(data);
	if (!data->wall || !data->space || !data->player || !data->player_l
		|| !data->coin || !data->door)
		ft_error_textures(data);
}

void	ft_textures(t_data *data)
{
	data->move = 0;
	data->wall = mlx_xpm_file_to_image(data->mlx,
			"./textures/wall.xpm", &(data->width), &(data->height));
	if (data->height != 50 || data->width != 50)
		ft_error_textures(data);
	data->space = mlx_xpm_file_to_image(data->mlx,
			"./textures/space.xpm", &(data->width), &(data->height));
	if (data->height != 50 || data->width != 50)
		ft_error_textures(data);
	data->player = mlx_xpm_file_to_image(data->mlx,
			"./textures/mario.xpm", &(data->width), &(data->height));
	if (data->height != 50 || data->width != 50)
		ft_error_textures(data);
	data->player_l = mlx_xpm_file_to_image(data->mlx,
			"./textures/mario_L.xpm", &(data->width), &(data->height));
	if (data->height != 50 || data->width != 50)
		ft_error_textures(data);
	ft_textures_2(data);
}

static void	ft_w_l(t_data *data, char key, int x, int y)
{
	if (key == 'l')
		mlx_put_image_to_window(data->mlx,
			data->mlx_win, data->player_l, (y * 50), (x * 50));
	else
		mlx_put_image_to_window(data->mlx,
			data->mlx_win, data->player, (y * 50), (x * 50));
}

void	push_images(t_data *data, char key, int x, int y)
{
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if ((data->map[x][y]) == '1')
				mlx_put_image_to_window(data->mlx,
					data->mlx_win, data->wall, (y * 50), (x * 50));
			else if ((data->map[x][y]) == '0')
				mlx_put_image_to_window(data->mlx,
					data->mlx_win, data->space, (y * 50), (x * 50));
			else if ((data->map[x][y]) == 'P')
				ft_w_l(data, key, x, y);
			else if ((data->map[x][y]) == 'C')
				mlx_put_image_to_window(data->mlx,
					data->mlx_win, data->coin, (y * 50), (x * 50));
			else if ((data->map[x][y]) == 'E')
				mlx_put_image_to_window(data->mlx,
					data->mlx_win, data->door, (y * 50), (x * 50));
			y++;
		}
		x++;
	}
}
