/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:16:05 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/19 12:56:56 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

static void	ft_textures2_bonus(t_data *data)
{
	data->door = mlx_xpm_file_to_image(data->mlx,
			"./textures/door.xpm", &(data->width), &(data->height));
	if (data->height != 50 || data->width != 50)
		ft_error_textures_b(data);
	data->enemy = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemy.xpm", &(data->width), &(data->height));
	if (data->height != 50 || data->width != 50)
		ft_error_textures_b(data);
	data->enemy_2 = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemy_2.xpm", &(data->width), &(data->height));
	if (data->height != 50 || data->width != 50)
		ft_error_textures_b(data);
	if (!data->wall || !data->space || !data->player || !data->player_l
		|| !data->coin || !data->door || !data->enemy || !data->enemy_2)
		ft_error_textures_b(data);
}

void	ft_textures_bonus(t_data *data)
{
	data->move = 0;
	data->key = 'w';
	data->dey = 'l';
	data->stm = ft_itoa(data->move);
	data->wall = mlx_xpm_file_to_image(data->mlx,
			"./textures/wall.xpm", &(data->width), &(data->height));
	if (data->height != 50 || data->width != 50)
		ft_error_textures_b(data);
	data->space = mlx_xpm_file_to_image(data->mlx,
			"./textures/space.xpm", &(data->width), &(data->height));
	if (data->height != 50 || data->width != 50)
		ft_error_textures_b(data);
	data->player = mlx_xpm_file_to_image(data->mlx,
			"./textures/mario.xpm", &(data->width), &(data->height));
	if (data->height != 50 || data->width != 50)
		ft_error_textures_b(data);
	data->player_l = mlx_xpm_file_to_image(data->mlx,
			"./textures/mario_L.xpm", &(data->width), &(data->height));
	if (data->height != 50 || data->width != 50)
		ft_error_textures_b(data);
	data->coin = mlx_xpm_file_to_image(data->mlx,
			"./textures/coin.xpm", &(data->width), &(data->height));
	if (data->height != 50 || data->width != 50)
		ft_error_textures_b(data);
	ft_textures2_bonus(data);
}

static void	ft_w_l(t_data *data, int x, int y)
{
	if (data->key == 'l')
		mlx_put_image_to_window(data->mlx,
			data->mlx_win, data->player_l, (y * 50), (x * 50));
	else
		mlx_put_image_to_window(data->mlx,
			data->mlx_win, data->player, (y * 50), (x * 50));
}

void	ft_enemy_dir(t_data *data, int x, int y)
{
	ft_count_bonus(data);
	if (data->dey == 'l')
		mlx_put_image_to_window(data->mlx,
			data->mlx_win, data->enemy, (y * 50), (x * 50));
	else
		mlx_put_image_to_window(data->mlx,
			data->mlx_win, data->enemy_2, (y * 50), (x * 50));
	if ((data->p_i == data->en_i) && (data->p_j == data->en_j))
		ft_enemy(data);
}

void	push_images_bonus(t_data *data, int x, int y)
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
				ft_w_l(data, x, y);
			else if ((data->map[x][y]) == 'C')
				mlx_put_image_to_window(data->mlx,
					data->mlx_win, data->coin, (y * 50), (x * 50));
			else if ((data->map[x][y]) == 'E')
				mlx_put_image_to_window(data->mlx,
					data->mlx_win, data->door, (y * 50), (x * 50));
			else if ((data->map[x][y]) == 'A')
				ft_enemy_dir(data, x, y);
			y++;
		}
		x++;
	}
}
