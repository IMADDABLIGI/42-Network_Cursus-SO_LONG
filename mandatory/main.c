/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:04:41 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/19 10:37:05 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		ft_write_error(1, &data);
	ft_fill_map(&data, av[1]);
	data.mlx = mlx_init();
	if (!data.mlx)
		ft_write_error(6, &data);
	data.mlx_win = mlx_new_window(data.mlx, data.width, data.height, "MARIO");
	if (!data.mlx_win)
		ft_write_error(6, &data);
	ft_textures(&data);
	push_images(&data, 'w', 0, 0);
	mlx_hook(data.mlx_win, 2, 0, ft_event, &data);
	mlx_hook(data.mlx_win, 17, 0, ft_destroy, &data);
	mlx_loop(data.mlx);
}
