/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:13:43 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/19 13:16:51 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		ft_write_error_bonus(1, &data);
	ft_fill_map_bonus(&data, av[1]);
	data.mlx = mlx_init();
	if (!data.mlx)
		ft_write_error_bonus(6, &data);
	data.mlx_win = mlx_new_window(data.mlx, data.width, data.height, "MARIO");
	if (!data.mlx_win)
		ft_write_error_bonus(6, &data);
	ft_textures_bonus(&data);
	push_images_bonus(&data, 0, 0);
	mlx_hook(data.mlx_win, 2, 0, ft_event_bonus, &data);
	mlx_hook(data.mlx_win, 17, 0, ft_destroy_bonus, &data);
	mlx_loop_hook(data.mlx, ft_move_enemy, &data);
	mlx_loop(data.mlx);
}
